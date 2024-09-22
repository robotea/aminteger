/**
 * @file: AMInteger.h
 * Safe integer operations with overflow detection
 *
 * @author Zdeněk Skulínek  &lt;<a href="mailto:me@zdenekskulinek.cz">me@zdenekskulinek.cz</a>&gt;
 */
#ifndef AMCORE_AMINTEGER_H
#define AMCORE_AMINTEGER_H

#include <type_traits>
#include <limits>

/**
 *  @ingroup Common
 *  @{
 */

namespace AMCore {

    /**
	 *  @ingroup Common
	 *  @brief Safe integer operations with overflow detection
	 *
     *  All function have TIntType template argument. The argument may by any integral type.
	 */

    /**
     *  @brief High bits (a half) of argument
     *  @param x
     *  @throw This function will not throw an exception.
     */
    template<typename TIntType>
    TIntType AMIntegerHi(TIntType x)
    {
        return (x >> (sizeof(TIntType) * 4));
    }

    /**
     *  @brief Low bits (a half) of argument
     *  @param x
     *  @throw This function will not throw an exception.
     */
    template<typename TIntType>
    TIntType AMIntegerLo(TIntType x)
    {
        TIntType res = ((1ULL << sizeof(TIntType) * 4) - 1) & x;
        return res;
    }

    /**
     *  @brief Safe multiply with overflow detection
     *  @param a first multiplicand
     *  @param b second multiplicand
     *  @param result reference to result
     *  @returns true if success, false if overflow
     *  @throw This function will not throw an exception.
     */
    template<typename TIntType>
    bool AMIntegerMultiply(TIntType a, TIntType b, TIntType& result) {

        static_assert(std::is_integral<TIntType>::value, "Integral required.");

        if constexpr (sizeof(long long) >= sizeof(TIntType) * 2) {
            if constexpr (std::is_signed<TIntType>::value) {
                long long tresult = (long long) a * (long long) b;
                long long cresult = tresult >> (sizeof(TIntType) * 8);
                bool rsign = tresult & (1ULL << (sizeof(TIntType) * 8 -1));
                if (cresult == 0 || cresult == -1) {
                    if ((a >= 0 && b >= 0 && !rsign)
                        || (a <= 0 && b <= 0 && !rsign)
                        || (a < 0 && b > 0 && rsign)
                        || (a > 0 && b < 0 && rsign)) {
                        result = (TIntType) tresult;
                        return true;
                    }
                }
                if ((a < 0 && b < 0) || (a > 0 && b > 0)) {
                    result = std::numeric_limits<TIntType>::max();
                } else {
                    result = std::numeric_limits<TIntType>::min();
                }
                return false;
            } else {
                unsigned long long tresult = (unsigned long long) a * (unsigned long long) b;
                unsigned long long cresult = tresult >> (sizeof(TIntType) * (sizeof(unsigned long long) == sizeof(TIntType) ? 0 : 8));
                if (cresult == 0) {
                    result = (TIntType)tresult;
                    return true;
                }
                result = std::numeric_limits<TIntType>::max();
                return false;
            }
        } else {
            typedef std::conditional_t<std::is_signed<TIntType>::value, TIntType, typename std::make_unsigned<TIntType>::type> TUIntType;
            const TUIntType mask = (1ULL << sizeof(TIntType) * 4) - 1;

            TUIntType s0, s11, s12, s21, s22, s3;
            TUIntType loa = AMIntegerLo((TUIntType)a), lob = AMIntegerLo((TUIntType)b), hia = AMIntegerHi((TUIntType)a), hib = AMIntegerHi((TUIntType)b);

            TUIntType x1 = loa * lob;
            s0 = AMIntegerLo(x1);

            TUIntType x2 = hia * lob + AMIntegerHi(x1);
            s11 = AMIntegerLo(x2);
            s21 = AMIntegerHi(x2);

            TUIntType x3 = s11 + loa * hib;
            s12 = AMIntegerLo(x3);

            TUIntType x4 = s21 + hia * hib + AMIntegerHi(x3);;
            s22 = AMIntegerLo(x4);
            s3 = AMIntegerHi(x4);

            if constexpr (std::is_signed<TIntType>::value) {
                if (((s22 & mask) != 0 || (s3 & mask) != 0)
                    && ((s22 & mask) != (((TUIntType) - 1) & mask) || (s3 & mask) != (((TUIntType) - 1) & mask))) {
                    if (s3 >= 0) {
                        result = std::numeric_limits<TIntType>::max();
                    } else {
                        result = std::numeric_limits<TIntType>::min();
                    }
                    return false;
                }
                TIntType tresult = s12 << (sizeof(TIntType) * 4) | s0;
                if ((a >= 0 && b >= 0 && tresult >= 0)
                    || (a <= 0 && b <= 0 && tresult >= 0)
                    || (a < 0 && b > 0 && tresult < 0)
                    || (a > 0 && b < 0 && tresult < 0)) {
                    result = tresult;
                    return true;
                }
                if (s3 >= 0) {
                    result = std::numeric_limits<TIntType>::max();
                } else {
                    result = std::numeric_limits<TIntType>::min();
                }
                return false;
            } else {
                if (s22 > 0 || s3 > 0) {
                    result = std::numeric_limits<TIntType>::max();
                    return false;
                }
                result = s12 << (sizeof(TIntType) * 4) | s0;
                return true;
            }
        }
    }

    /**
     *  @brief Safe addition with overflow detection
     *  @param a first addend
     *  @param b second addend
     *  @param result reference to result
     *  @returns true if success, false if overflow
     *  @throw This function will not throw an exception.
     */
    template<typename TIntType>
    bool AMIntegerAdd(TIntType a, TIntType b, TIntType& result) {

        static_assert(std::is_integral<TIntType>::value, "Integral required.");

        if constexpr ((sizeof(long long) >= sizeof(TIntType) * 2) || std::is_signed<TIntType>::value) {
            if constexpr (std::is_signed<TIntType>::value) {
                TIntType tresult = a + b;
                if (a > 0 && b > 0 && tresult < 0) {
                    result = std::numeric_limits<TIntType>::max();
                    return false;
                } else if (a < 0 && b < 0 && tresult > 0) {
                    result = std::numeric_limits<TIntType>::min();
                    return false;
                } else {
                    result = tresult;
                    return true;
                }
            } else {
                unsigned long long tresult = (unsigned long long) a + (unsigned long long) b;
                long long cresult = tresult & (-1LL ^ ((1ULL << sizeof(TIntType)*8) - 1));
                if (cresult > 0) {
                    result = std::numeric_limits<TIntType>::max();
                    return false;
                }
                result = (TIntType)tresult;
                return true;
            }
        } else {
            typedef std::conditional_t<std::is_signed<TIntType>::value, TIntType, typename std::make_unsigned<TIntType>::type> TUIntType;

            TUIntType s0, s1, s2;
            TUIntType loa = AMIntegerLo((TUIntType)a), lob = AMIntegerLo((TUIntType)b), hia = AMIntegerHi((TUIntType)a), hib = AMIntegerHi((TUIntType)b);

            TUIntType x1 = loa + lob;
            s0 = AMIntegerLo(x1);

            TUIntType x2 = hia + hib + AMIntegerHi(x1);
            s1 = AMIntegerLo(x2);
            s2 = AMIntegerHi(x2);

            if (s2 > 0) {
                result = std::numeric_limits<TIntType>::max();
                return false;
            }
            result = s1 << (sizeof(TIntType) * 4) | s0;
            return true;
        }
    }

    template<typename TIntType>
    bool AMIntegerPow(TIntType x, unsigned int p, TIntType& result)
    {
        if (p == 0) return 1;
        if (p == 1) return x;

        TIntType tmp;
        if (!AMIntegerPow(x, p/2, tmp)) {
            return false;
        }
        if (AMIntegerHi(tmp)) {
            return false;
        }
        if (p%2 == 0)  {
            result = tmp * tmp;
        }
        else {
            TIntType tres;
            if (!AMIntegerMultiply(x, tmp * tmp, tres)) {
                return false;
            }
            result = tres;
        }
        return true;
    }

    template<typename TIntType>
    TIntType AMIntegerPowRaw(TIntType x, unsigned int p)
    {
        if (p == 0) return 1;
        if (p == 1) return x;

        int tmp = AMIntegerPowRaw(x, p/2);
        if (p%2 == 0)  {
            return tmp * tmp;
        }
        else return x * tmp * tmp;
    }
}

/** @} */

#endif //AMCORE_AMINTEGER_H

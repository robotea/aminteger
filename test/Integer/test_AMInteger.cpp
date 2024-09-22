#include "../../AMInteger.h"
#include "gtest/gtest.h"

using namespace AMCore;


TEST(AMRange, basicTestIntMult)
{
    bool rs;
    int  rv;
    rs = AMIntegerMultiply( 10 , 20 , rv);
    EXPECT_EQ(rv, 200);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( -10 , 20 , rv);
    EXPECT_EQ(rv, -200);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 10 , -20 , rv);
    EXPECT_EQ(rv, -200);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( -10 , -20 , rv);
    EXPECT_EQ(rv, 200);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 0 , 20 , rv);
    EXPECT_EQ(rv, 0);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 0 , -20 , rv);
    EXPECT_EQ(rv, 0);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 10 , 0 , rv);
    EXPECT_EQ(rv, 0);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( -10 , 0 , rv);
    EXPECT_EQ(rv, 0);
    EXPECT_EQ(rs, true);



    rs = AMIntegerMultiply( 3000000 , 2000000 , rv);
    EXPECT_EQ(rv, std::numeric_limits<int>::max());
    EXPECT_EQ(rs, false);

    rs = AMIntegerMultiply( -3000000 , 2000000 , rv);
    EXPECT_EQ(rv, std::numeric_limits<int>::min());
    EXPECT_EQ(rs, false);

    rs = AMIntegerMultiply( 3000000 , -2000000 , rv);
    EXPECT_EQ(rv, std::numeric_limits<int>::min());
    EXPECT_EQ(rs, false);

    rs = AMIntegerMultiply( -3000000 ,- 2000000 , rv);
    EXPECT_EQ(rv, std::numeric_limits<int>::max());
    EXPECT_EQ(rs, false);

    rs = AMIntegerMultiply( 0x10000 , 0x8000 , rv);
    EXPECT_EQ(rv, std::numeric_limits<int>::max());
    EXPECT_EQ(rs, false);

    rs = AMIntegerMultiply( -0x10000 , 0x8000 , rv);
    EXPECT_EQ(rv, std::numeric_limits<int>::min());
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 0x10000 , -0x8000 , rv);
    EXPECT_EQ(rv, std::numeric_limits<int>::min());
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( -0x10000 , -0x8000 , rv);
    EXPECT_EQ(rv, std::numeric_limits<int>::max());
    EXPECT_EQ(rs, false);

}

TEST(AMRange, basicTestUIntMult)
{
    bool rs;
    unsigned int  rv;
    rs = AMIntegerMultiply( 10U , 20U , rv);
    EXPECT_EQ(rv, 200U);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 0U , 20U , rv);
    EXPECT_EQ(rv, 0U);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 10U , 0U , rv);
    EXPECT_EQ(rv, 0U);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 3000000U , 2000000U , rv);
    EXPECT_EQ(rv, std::numeric_limits<unsigned int>::max());
    EXPECT_EQ(rs, false);


    rs = AMIntegerMultiply( 0x10000U , 0x8000U , rv);
    EXPECT_EQ(rv, 0x80000000);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 0x10000U , 0x10000U , rv);
    EXPECT_EQ(rv, std::numeric_limits<unsigned int>::max());
    EXPECT_EQ(rs, false);

}

TEST(AMRange, basicTestULongLongMult)
{
    bool rs;
    unsigned long long  rv;
    rs = AMIntegerMultiply( 10ULL , 20ULL , rv);
    EXPECT_EQ(rv, 200ULL);
    EXPECT_EQ(rs, true);


    rs = AMIntegerMultiply( 10ULL , 0ULL , rv);
    EXPECT_EQ(rv, 0ULL);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 0ULL , 20ULL , rv);
    EXPECT_EQ(rv, 0ULL);
    EXPECT_EQ(rs, true);


    rs = AMIntegerMultiply( 300000000000ULL , 200000000000ULL , rv);
    EXPECT_EQ(rv, std::numeric_limits<unsigned long long>::max());
    EXPECT_EQ(rs, false);


    rs = AMIntegerMultiply( 0x100000000ULL , 0x80000000ULL , rv);
    EXPECT_EQ(rv, 0x8000000000000000ULL);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 0x100000000ULL , 0x100000000ULL , rv);
    EXPECT_EQ(rv, std::numeric_limits<unsigned long long>::max());
    EXPECT_EQ(rs, false);

}

TEST(AMRange, basicTestLongLongMult)
{
    bool rs;
    long long rv;
    rs = AMIntegerMultiply( 10LL , 20LL , rv);
    EXPECT_EQ(rv, 200LL);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( -10LL , 20LL , rv);
    EXPECT_EQ(rv, -200LL);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 10LL , -20LL , rv);
    EXPECT_EQ(rv, -200LL);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( -10LL , -20LL , rv);
    EXPECT_EQ(rv, 200LL);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 0LL , 20LL , rv);
    EXPECT_EQ(rv, 0LL);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 0LL , -20LL , rv);
    EXPECT_EQ(rv, 0LL);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 10LL , 0LL , rv);
    EXPECT_EQ(rv, 0LL);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( -10LL , 0LL , rv);
    EXPECT_EQ(rv, 0LL);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 300000000000LL , 200000000000LL , rv);
    EXPECT_EQ(rv, std::numeric_limits<long long>::max());
    EXPECT_EQ(rs, false);

    rs = AMIntegerMultiply( -300000000000LL , 200000000000LL , rv);
    EXPECT_EQ(rv, std::numeric_limits<long long>::min());
    EXPECT_EQ(rs, false);

    rs = AMIntegerMultiply( 300000000000LL , -200000000000LL , rv);
    EXPECT_EQ(rv, std::numeric_limits<long long>::min());
    EXPECT_EQ(rs, false);

    rs = AMIntegerMultiply( -300000000000LL ,- 200000000000LL , rv);
    EXPECT_EQ(rv, std::numeric_limits<long long>::max());
    EXPECT_EQ(rs, false);

    rs = AMIntegerMultiply( 0x100000000LL , 0x80000000LL , rv);
    EXPECT_EQ(rv, std::numeric_limits<long long>::max());
    EXPECT_EQ(rs, false);

    rs = AMIntegerMultiply( -0x100000000LL , 0x80000000LL , rv);
    EXPECT_EQ(rv, std::numeric_limits<long long>::min());
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 0x100000000LL , -0x80000000LL , rv);
    EXPECT_EQ(rv, std::numeric_limits<long long>::min());
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( -0x100000000LL , -0x80000000LL , rv);
    EXPECT_EQ(rv, std::numeric_limits<long long>::max());
    EXPECT_EQ(rs, false);

}

TEST(AMRange, basicTestUIntAdd)
{
    bool rs;
    unsigned int  rv;
    rs = AMIntegerAdd( 10U , 20U , rv);
    EXPECT_EQ(rv, 30U);
    EXPECT_EQ(rs, true);


    rs = AMIntegerAdd( 0xA0000000U , 0xA0000000U , rv);
    EXPECT_EQ(rv, std::numeric_limits<unsigned int>::max());
    EXPECT_EQ(rs, false);


    rs = AMIntegerAdd( 0x80000000U , 0x7FFFFFFFU , rv);
    EXPECT_EQ(rv, 0xFFFFFFFF);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 0x80000000U , 0x80000000U , rv);
    EXPECT_EQ(rv, std::numeric_limits<unsigned int>::max());
    EXPECT_EQ(rs, false);

}

TEST(AMRange, basicTestIntAdd)
{
    bool rs;
    int  rv;
    rs = AMIntegerAdd( 10 , 20 , rv);
    EXPECT_EQ(rv, 30);
    EXPECT_EQ(rs, true);

    rs = AMIntegerAdd( -10 , 20 , rv);
    EXPECT_EQ(rv, 10);
    EXPECT_EQ(rs, true);

    rs = AMIntegerAdd( 10 , -20 , rv);
    EXPECT_EQ(rv, -10);
    EXPECT_EQ(rs, true);

    rs = AMIntegerAdd( -10 , -20 , rv);
    EXPECT_EQ(rv, -30);
    EXPECT_EQ(rs, true);


    rs = AMIntegerAdd( 0x60000000 , 0x60000000 , rv);
    EXPECT_EQ(rv, std::numeric_limits<int>::max());
    EXPECT_EQ(rs, false);

    rs = AMIntegerAdd( -2000000000 , -2000000000 , rv);
    EXPECT_EQ(rv, std::numeric_limits<int>::min());
    EXPECT_EQ(rs, false);

    rs = AMIntegerAdd( -2000000000 , 2000004000 , rv);
    EXPECT_EQ(rv, 4000);
    EXPECT_EQ(rs, true);

    rs = AMIntegerAdd( 0x7FFFFFFF , 1 , rv);
    EXPECT_EQ(rv, std::numeric_limits<int>::max());
    EXPECT_EQ(rs, false);

    rs = AMIntegerAdd( -0x7FFFFFFF , -2 , rv);
    EXPECT_EQ(rv, std::numeric_limits<int>::min());
    EXPECT_EQ(rs, false);


}

TEST(AMRange, basicTestUIntLongAdd)
{
    bool rs;
    unsigned long long  rv;
    rs = AMIntegerAdd( 10ULL , 20ULL , rv);
    EXPECT_EQ(rv, 30ULL);
    EXPECT_EQ(rs, true);


    rs = AMIntegerAdd( 0xA000000000000000ULL , 0xA000000000000000ULL , rv);
    EXPECT_EQ(rv, std::numeric_limits<unsigned long long>::max());
    EXPECT_EQ(rs, false);


    rs = AMIntegerAdd( 0x8000000000000000ULL , 0x7FFFFFFFFFFFFFFFULL , rv);
    EXPECT_EQ(rv, 0xFFFFFFFFFFFFFFFFULL);
    EXPECT_EQ(rs, true);

    rs = AMIntegerMultiply( 0x8000000000000000ULL , 0x8000000000000000ULL , rv);
    EXPECT_EQ(rv, std::numeric_limits<unsigned long long>::max());
    EXPECT_EQ(rs, false);

}

TEST(AMRange, basicTestIntLongAdd)
{
    bool rs;
    long long  rv;
    rs = AMIntegerAdd( 10LL , 20LL , rv);
    EXPECT_EQ(rv, 30LL);
    EXPECT_EQ(rs, true);

    rs = AMIntegerAdd( -10LL , 20LL , rv);
    EXPECT_EQ(rv, 10LL);
    EXPECT_EQ(rs, true);

    rs = AMIntegerAdd( 10LL , -20LL , rv);
    EXPECT_EQ(rv, -10LL);
    EXPECT_EQ(rs, true);

    rs = AMIntegerAdd( -10LL , -20LL , rv);
    EXPECT_EQ(rv, -30LL);
    EXPECT_EQ(rs, true);


    rs = AMIntegerAdd( 0x6000000000000000LL , 0x6000000000000000LL , rv);
    EXPECT_EQ(rv, std::numeric_limits<long long>::max());
    EXPECT_EQ(rs, false);

    rs = AMIntegerAdd( -5000000000000000000LL , -5000000000000000000LL , rv);
    EXPECT_EQ(rv, std::numeric_limits<long long>::min());
    EXPECT_EQ(rs, false);

    rs = AMIntegerAdd( -5000000000000000000LL , 5000000000000004000LL , rv);
    EXPECT_EQ(rv, 4000LL);
    EXPECT_EQ(rs, true);

    rs = AMIntegerAdd( 0x7FFFFFFFFFFFFFFFLL , 1LL , rv);
    EXPECT_EQ(rv, std::numeric_limits<long long>::max());
    EXPECT_EQ(rs, false);

    rs = AMIntegerAdd( -0x7FFFFFFFFFFFFFFFLL , -2LL , rv);
    EXPECT_EQ(rv, std::numeric_limits<long long>::min());
    EXPECT_EQ(rs, false);


}

int main(int argc, char **argv) {

     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
}

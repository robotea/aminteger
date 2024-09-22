/**
 * @mainpage Andromeda AMInteger library
 * @brief \ref AMInteger - Safe integer operations with overflow detection.
 *
 * If overflow of two integral types may cause problem, you need to use this two funtions.
 *
 * Usage
 * =====
 *
 * \code
 *
 * #include "aminteger/AMInteger.h"
 *
 *  bool rs;
 *  int  rv;
 *  rs = AMIntegerMultiply( 10 , 20 , rv);
 *
 *  rs = AMIntegerAdd( 10 , 20 , rv);
 *
 *  \endcode
 *
 * Sources
 * =======
 *
 * Download at [GitHUB](https://github.com/robotea/aminteger)
 *
 * Building AMInteger
 * ==================
 *
 * Getting sources
 * ---------------
 *
 * \code
 * git submodule update
 * \endcode
 *
 * Compiling
 * ---------
 *
 * \code
 *
 * mkdir cmake-build-debug
 *
 * cd cmake-build-debug
 *
 * cmake ..
 *
 * make
 *
 * \endcode
 *
 * Single test (not necessary)
 * ---------------------------
 *
 * \code
 *
 * ./TEST_AMInteger
 *
 * \endcode
 *
 * Licencing
 * =========
 *
 * This library is under GNU GPL v3 license. If you need business license, don't hesitate to contact [me](mailto:zdenek.skulinek@robotea.com?subject=License for AMInteger).
 *
 * Contribute
 * ==========
 *
 * Please contact [me](mailto:zdenek.skulinek@robotea.com?subject=License for AMInteger).
 *
 * Dependencies
 * ============
 *
 * - [Google test](https://github.com/google/googletest.git)
 */

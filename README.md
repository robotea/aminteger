# AMInteger - Safe integer operations with overflow detection.

If overflow of two integral types may cause problem, you need to use this two funtions.

Template functions - support all integral types.

## Usage

    #include "aminteger/AMInteger.h"

    bool rs;
    int  rv;
    rs = AMIntegerMultiply( 10 , 20 , rv);

    rs = AMIntegerAdd( 10 , 20 , rv);

## Documetation

There are doxygen generated documentation [here on libandromeda.org](http://libandromeda.org/aminteger/latest/).

## Building AMInteger

### Getting sources

```bash
git submodule update
```

### Compiling

```bash

mkdir cmake-build-debug

cd cmake-build-debug

cmake ..

make
```

### Single test (not necessary)

```bash
./TEST_AMInteger
```

## License

This library is under GNU GPL v3 license. If you need business license, don't hesitate to contact [me](mailto:zdenek.skulinek\@robotea.com\?subject\=License%20for%20AMInteger).

## Contribute

Please contact [me](mailto:zdenek.skulinek\@robotea.com\?subject\=License%20for%20AMInteger).

## Ask for help

Please contact [me](mailto:zdenek.skulinek\@robotea.com\?subject\=Consultation).

## Dependencies

1. [Google test](https://github.com/google/googletest.git)

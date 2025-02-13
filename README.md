# BLAS usage examples

The documents and presentations of the tutorial can be found in the `doc` directory.

## Compilation

To compile these examples, you will need access to a BLAS library. Netlib BLAS is the reference implementation of BLAS and is distributed together with the reference implementation of LAPACK. Clone the official repository of [Netlib LAPACK](https://github.com/Reference-LAPACK/lapack). You can the checkout the latest version (v3.12.1), build, and install BLAS and LAPACK.

### Building BLAS and LAPACK

BLAS and LAPACK are built with a single configuration. Configure the compilation with the following command:
```bash
cmake -S path/to/lapack -B /tmp/build_lapack -G Ninja -DBUILD_SHARED_LIBS:BOOL=ON -DCBLAS:BOOL=ON -DCMAKE_BUILD_TYPE:STRING=Release -DCMAKE_INSTALL_PREFIX:PATH=${HOME}/.local/opt/netlib
```
This configures the software to be built in the local volume of the node and to install the resulting libraries in your home directory. Build BLAS and LAPACK with,
```bash
cmake --build /tmp/build_lapack --target all
```
and install with:
```bash
cmake --build /tmp/build_lapack --target install
```

### Building the matrix garden I/O library

This tutorial is also using an auxiliary library for reading and writing matrices in files in the matrix garden formats. Download the [Matrix Market Exchange Formats](https://gitlab.com/greeklug/matrix_market_exchange_formats) repository and checkout the v1.0 tag. The library can be configured with:
```bash
cmake -S . --preset default-config
```

Build the software with,
```bash
cmake --build build/Release --target all
```
and install with:
```bash
cmake --build build/Release --target install
```
The library is installed in `${HOME}/.local/opt/matrix-market` by default.


## Collection of matrix examples

The [Matrix Market](https://math.nist.gov/MatrixMarket/index.html) repository of test data for use in performance analysis of algorithms for numerical linear algebra. It contains multiple collections of test data, such as the [Harwell-Boeing](https://math.nist.gov/MatrixMarket/data/Harwell-Boeing/) and [SPARSKIT](https://math.nist.gov/MatrixMarket/data/SPARSKIT/) collections. The data are provided in [multiple text file formats](https://math.nist.gov/MatrixMarket/formats.html), including [Harwell-Boeing Exchange Format](https://math.nist.gov/MatrixMarket/formats.html#hb) and the [Matrix Market Exchange Format](https://math.nist.gov/MatrixMarket/formats.html#MMformat). We are using the Matrix Market Exchange Format due to its simplicity. More information regarding the format can be found in its [official documentation](https://math.nist.gov/MatrixMarket/reports/MMformat.ps).

In this example the matrices user are:
- [`Harwell-Boeing/bcsstruc1/bcsstk01`](https://math.nist.gov/MatrixMarket/data/Harwell-Boeing/bcsstruc1/bcsstk01.html): BCS Structural Engineering Matrices (eigenvalue matrices)
    - Type: real symmetric positive definite
    - Size: 48 x 48, 224 entries


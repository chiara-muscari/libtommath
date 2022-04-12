# libtommath

This is a fork of [LibTomMath](http://www.libtom.net/LibTomMath/) (a free open source portable number theoretic multiple-precision integer (MPI) library written entirely in C), purposing to optimize the library for STM32 platforms, especially concerning Barrett Reduction operation.


## Building, Installing and Testing

The development platform which has been used is the Nucleo F401-RE board. STM32CUBEIDE 1.4.0 has been used and it is suggested especially to perform the tests.


1. Clone the repo
2. Setup a project and add the libtommath-stm32 folder, for example in Core/ directory.
3. Then close the IDE, move into Testing directory and execute test.sh script to easily build, program and execute an example main.
   Some header files containing test vectors are already present, they have been generated through the Python script in Testing/ folder.

In `original_repo_resources/` folder, there are the tests resources, written by developers of LibTomMath original repo.
Be aware that they've not been modified and/or adapted for STM32 platform, they have been kept just for reference.

In general, the `test_generator.py` script in `Core/libtommath/Testing/Example_test_vectors/` can be used to generate an header file containing the test vectors definitions. You can specify the operation you want to test, the number of test vector you want to generate and if they should be only random or if they can contain some particular patterns to test.
The script `test.sh` in `Core/libtommath/Testing/` can be used to automatize the process. Please refer to the README in `Testing/` to understand how to do the setup before executing the script.




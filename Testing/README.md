# Testing

## test.sh script

This script has been used to more easily collect data about performances of the reduction algorithm, since it eases the testing by allowing to execute all in once all the operation needed.

0. Open STM32CUBEIDE and create a project for the platform, with the UART peripheral active. This project will be backup and then used as base project for the testing during the script execution. 
Clone the repo in some location, for example in `/Core/libtommath-stm32`
Then close the IDE. Open test.sh script with an editor, to set the variables properly.
1. Set STM32_WORKSPACE  variable, containing the path to workspace for STM32CUBEIDE (for example `/home/{user}/Documents/STM32_ws`)
   Set STM32CUBEIDE_PATH  variable, containing the path to the bin for STM32CUBEIDE (for example `/opt/st/stm32cubeide_1.4.0`)
   Set CUBE_PROGRAMMER_PATH  variable, containing the path to STM32CubeProgrammer, which is automatically installed with the IDE
   (for example `${STM32CUBEIDE_PATH}/plugins/com.st.stm32cube.ide.mcu.externaltools.cubeprogrammer.linux64_1.4.0.202007081208/tools/bin/STM32_Programmer_CLI`)
2. Set LOG_BIT_NUM variable to perform the test with a modulo of 2^LOG_BIT_NUM bits
3. Set the name of the project you created in 0. in PROJECT_NAME var
4. Launch the script test.sh, pay attention on having the IDE closed.
5. Now the script will execute the python script to generate the various test vectors, it will compile, flash and run the code, reporting the results.
   Note a serial communication will be established with the board. 


## python script test_generator.py

This scripts generates 2 header files, one with 28-bits digits and one with 32-bits digits, named `{operation}/test_vec_{num_bits}.h`, which contains the definitions of a series of sets of three arrays (first operand, second operand, result). 
You can select the number of tests to generates, the operation (addition, subtraction, multiplication, integer division, reduction), the bit-length of the operands and if some tests incuding particular patterns have to be included.
Call `python3 test_generator.py -h` to show the help text.
Usage `python3 test_generator.py  [options]`



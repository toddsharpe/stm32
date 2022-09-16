set CUBE_BIN=C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin

REM Erasing
"%CUBE_BIN%\STM32_Programmer_CLI.exe" -c port=SWD -e all

REM Flashing
"%CUBE_BIN%\STM32_Programmer_CLI.exe" -c port=SWD -w build\Nucleo.elf -v

"%CUBE_BIN%\STM32_Programmer_CLI.exe" -c port=SWD -s
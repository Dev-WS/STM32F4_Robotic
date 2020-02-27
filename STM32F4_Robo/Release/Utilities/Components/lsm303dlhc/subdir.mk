################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/Components/lsm303dlhc/lsm303dlhc.c 

OBJS += \
./Utilities/Components/lsm303dlhc/lsm303dlhc.o 

C_DEPS += \
./Utilities/Components/lsm303dlhc/lsm303dlhc.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/Components/lsm303dlhc/%.o: ../Utilities/Components/lsm303dlhc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407G_DISC1 -DSTM32F407xx -DUSE_HAL_DRIVER -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/ili9325" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/s25fl512s" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/ili9341" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/cs43l22" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/ampire480272" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/n25q512a" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/s5k5cag" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/mfxstm32l152" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/CMSIS/device" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/ts3510" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/n25q128a" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/st7735" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/HAL_Driver/Inc/Legacy" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/lis302dl" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/otm8009a" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/stmpe1600" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/ov2640" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/Common" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/l3gd20" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/HAL_Driver/Inc" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/stmpe811" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/lis3dsh" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/wm8994" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/n25q256a" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/ls016b8uy" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/inc" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/ft6x06" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/STM32F4-Discovery" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/exc7200" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/st7789h2" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/ampire640480" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/Utilities/Components/lsm303dlhc" -I"/media/wojtek/2f408d53-351e-4a9a-9af4-83a9ff57c044/Programming/Eclipse/Workspace/STM32F4_Disc/CMSIS/core" -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



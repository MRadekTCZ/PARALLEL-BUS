################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/BUS_8bit.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/tim.c 

OBJS += \
./Core/Src/BUS_8bit.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/tim.o 

C_DEPS += \
./Core/Src/BUS_8bit.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F411xE -I"C:/Users/macie/Desktop/Studia/STMgeek/mag_8bitFPGA/mag_8bitSTM/mag_8bitSTM/Core/Inc" -I"C:/Users/macie/Desktop/Studia/STMgeek/mag_8bitFPGA/mag_8bitSTM/mag_8bitSTM/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/macie/Desktop/Studia/STMgeek/mag_8bitFPGA/mag_8bitSTM/mag_8bitSTM/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/macie/Desktop/Studia/STMgeek/mag_8bitFPGA/mag_8bitSTM/mag_8bitSTM/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/macie/Desktop/Studia/STMgeek/mag_8bitFPGA/mag_8bitSTM/mag_8bitSTM/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



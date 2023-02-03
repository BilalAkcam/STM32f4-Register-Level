################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/My_Driver/Src/Button_Driver.c \
../Drivers/My_Driver/Src/Led_Driver.c 

OBJS += \
./Drivers/My_Driver/Src/Button_Driver.o \
./Drivers/My_Driver/Src/Led_Driver.o 

C_DEPS += \
./Drivers/My_Driver/Src/Button_Driver.d \
./Drivers/My_Driver/Src/Led_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/My_Driver/Src/%.o Drivers/My_Driver/Src/%.su: ../Drivers/My_Driver/Src/%.c Drivers/My_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/My_Driver/Inc -I../Drivers/My_Driver/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-My_Driver-2f-Src

clean-Drivers-2f-My_Driver-2f-Src:
	-$(RM) ./Drivers/My_Driver/Src/Button_Driver.d ./Drivers/My_Driver/Src/Button_Driver.o ./Drivers/My_Driver/Src/Button_Driver.su ./Drivers/My_Driver/Src/Led_Driver.d ./Drivers/My_Driver/Src/Led_Driver.o ./Drivers/My_Driver/Src/Led_Driver.su

.PHONY: clean-Drivers-2f-My_Driver-2f-Src


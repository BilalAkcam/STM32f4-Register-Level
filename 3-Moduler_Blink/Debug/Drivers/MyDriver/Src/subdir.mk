################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MyDriver/Src/buton.c \
../Drivers/MyDriver/Src/led.c 

OBJS += \
./Drivers/MyDriver/Src/buton.o \
./Drivers/MyDriver/Src/led.o 

C_DEPS += \
./Drivers/MyDriver/Src/buton.d \
./Drivers/MyDriver/Src/led.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MyDriver/Src/%.o Drivers/MyDriver/Src/%.su: ../Drivers/MyDriver/Src/%.c Drivers/MyDriver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Drivers/CMSIS/Include -I../Drivers/MyDriver/Src -I../Drivers/MyDriver/Inc -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-MyDriver-2f-Src

clean-Drivers-2f-MyDriver-2f-Src:
	-$(RM) ./Drivers/MyDriver/Src/buton.d ./Drivers/MyDriver/Src/buton.o ./Drivers/MyDriver/Src/buton.su ./Drivers/MyDriver/Src/led.d ./Drivers/MyDriver/Src/led.o ./Drivers/MyDriver/Src/led.su

.PHONY: clean-Drivers-2f-MyDriver-2f-Src


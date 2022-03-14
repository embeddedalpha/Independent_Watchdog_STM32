################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/Independent_Watchdog/IDWatchdog.c 

OBJS += \
./Inc/Independent_Watchdog/IDWatchdog.o 

C_DEPS += \
./Inc/Independent_Watchdog/IDWatchdog.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/Independent_Watchdog/%.o: ../Inc/Independent_Watchdog/%.c Inc/Independent_Watchdog/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411CEUx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc-2f-Independent_Watchdog

clean-Inc-2f-Independent_Watchdog:
	-$(RM) ./Inc/Independent_Watchdog/IDWatchdog.d ./Inc/Independent_Watchdog/IDWatchdog.o

.PHONY: clean-Inc-2f-Independent_Watchdog


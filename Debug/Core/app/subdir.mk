################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/app/app_command.c \
../Core/app/app_robot.c \
../Core/app/drv_bluetoothoruart.c 

OBJS += \
./Core/app/app_command.o \
./Core/app/app_robot.o \
./Core/app/drv_bluetoothoruart.o 

C_DEPS += \
./Core/app/app_command.d \
./Core/app/app_robot.d \
./Core/app/drv_bluetoothoruart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/app/%.o Core/app/%.su Core/app/%.cyclo: ../Core/app/%.c Core/app/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/dtnb25/robot_car/Core/drivers" -I"/home/dtnb25/robot_car/Core/platform" -I"/home/dtnb25/robot_car/Core/utils" -I"/home/dtnb25/robot_car/Core/app" -I"/home/dtnb25/robot_car/Core/services" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-app

clean-Core-2f-app:
	-$(RM) ./Core/app/app_command.cyclo ./Core/app/app_command.d ./Core/app/app_command.o ./Core/app/app_command.su ./Core/app/app_robot.cyclo ./Core/app/app_robot.d ./Core/app/app_robot.o ./Core/app/app_robot.su ./Core/app/drv_bluetoothoruart.cyclo ./Core/app/drv_bluetoothoruart.d ./Core/app/drv_bluetoothoruart.o ./Core/app/drv_bluetoothoruart.su

.PHONY: clean-Core-2f-app


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/drivers/drv_i3g4250.c \
../Core/drivers/drv_motor.c \
../Core/drivers/drv_motor_drv8833.c \
../Core/drivers/stm32f429i_discovery_lcd.c 

OBJS += \
./Core/drivers/drv_i3g4250.o \
./Core/drivers/drv_motor.o \
./Core/drivers/drv_motor_drv8833.o \
./Core/drivers/stm32f429i_discovery_lcd.o 

C_DEPS += \
./Core/drivers/drv_i3g4250.d \
./Core/drivers/drv_motor.d \
./Core/drivers/drv_motor_drv8833.d \
./Core/drivers/stm32f429i_discovery_lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Core/drivers/%.o Core/drivers/%.su Core/drivers/%.cyclo: ../Core/drivers/%.c Core/drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/dtnb25/robot_car/Core/drivers" -I"/home/dtnb25/robot_car/Core/platform" -I"/home/dtnb25/robot_car/Core/utils" -I"/home/dtnb25/robot_car/Core/app" -I"/home/dtnb25/robot_car/Core/services" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-drivers

clean-Core-2f-drivers:
	-$(RM) ./Core/drivers/drv_i3g4250.cyclo ./Core/drivers/drv_i3g4250.d ./Core/drivers/drv_i3g4250.o ./Core/drivers/drv_i3g4250.su ./Core/drivers/drv_motor.cyclo ./Core/drivers/drv_motor.d ./Core/drivers/drv_motor.o ./Core/drivers/drv_motor.su ./Core/drivers/drv_motor_drv8833.cyclo ./Core/drivers/drv_motor_drv8833.d ./Core/drivers/drv_motor_drv8833.o ./Core/drivers/drv_motor_drv8833.su ./Core/drivers/stm32f429i_discovery_lcd.cyclo ./Core/drivers/stm32f429i_discovery_lcd.d ./Core/drivers/stm32f429i_discovery_lcd.o ./Core/drivers/stm32f429i_discovery_lcd.su

.PHONY: clean-Core-2f-drivers


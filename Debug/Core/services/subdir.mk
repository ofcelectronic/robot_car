################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/services/debug.c \
../Core/services/svc_heading.c \
../Core/services/svc_motion.c 

OBJS += \
./Core/services/debug.o \
./Core/services/svc_heading.o \
./Core/services/svc_motion.o 

C_DEPS += \
./Core/services/debug.d \
./Core/services/svc_heading.d \
./Core/services/svc_motion.d 


# Each subdirectory must supply rules for building sources it contributes
Core/services/%.o Core/services/%.su Core/services/%.cyclo: ../Core/services/%.c Core/services/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/dtnb25/robot_car/Core/drivers" -I"/home/dtnb25/robot_car/Core/platform" -I"/home/dtnb25/robot_car/Core/utils" -I"/home/dtnb25/robot_car/Core/app" -I"/home/dtnb25/robot_car/Core/services" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-services

clean-Core-2f-services:
	-$(RM) ./Core/services/debug.cyclo ./Core/services/debug.d ./Core/services/debug.o ./Core/services/debug.su ./Core/services/svc_heading.cyclo ./Core/services/svc_heading.d ./Core/services/svc_heading.o ./Core/services/svc_heading.su ./Core/services/svc_motion.cyclo ./Core/services/svc_motion.d ./Core/services/svc_motion.o ./Core/services/svc_motion.su

.PHONY: clean-Core-2f-services


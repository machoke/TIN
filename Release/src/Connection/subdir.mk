################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Connection/connection.cpp \
../src/Connection/connectionSettings.cpp 

OBJS += \
./src/Connection/connection.o \
./src/Connection/connectionSettings.o 

CPP_DEPS += \
./src/Connection/connection.d \
./src/Connection/connectionSettings.d 


# Each subdirectory must supply rules for building sources it contributes
src/Connection/%.o: ../src/Connection/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



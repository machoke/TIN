################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ParserDemo.cpp \
../src/bufor_client.cpp \
../src/bufor_server.cpp \
../src/client.cpp \
../src/server.cpp 

OBJS += \
./src/ParserDemo.o \
./src/bufor_client.o \
./src/bufor_server.o \
./src/client.o \
./src/server.o 

CPP_DEPS += \
./src/ParserDemo.d \
./src/bufor_client.d \
./src/bufor_server.d \
./src/client.d \
./src/server.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Parser.cpp \
../src/ParserTexts.cpp \
../src/TIN.cpp 

OBJS += \
./src/Parser.o \
./src/ParserTexts.o \
./src/TIN.o 

CPP_DEPS += \
./src/Parser.d \
./src/ParserTexts.d \
./src/TIN.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



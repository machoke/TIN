################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Parser/Parser.cpp \
../src/Parser/ParserTexts.cpp \
../src/Parser/TIN.cpp 

OBJS += \
./src/Parser/Parser.o \
./src/Parser/ParserTexts.o \
./src/Parser/TIN.o 

CPP_DEPS += \
./src/Parser/Parser.d \
./src/Parser/ParserTexts.d \
./src/Parser/TIN.d 


# Each subdirectory must supply rules for building sources it contributes
src/Parser/%.o: ../src/Parser/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


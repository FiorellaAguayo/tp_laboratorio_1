################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Controller.c \
../funcionesUTN.c \
../parser.c \
../passenger.c 

C_DEPS += \
./Controller.d \
./funcionesUTN.d \
./parser.d \
./passenger.d 

OBJS += \
./Controller.o \
./funcionesUTN.o \
./parser.o \
./passenger.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Controller.d ./Controller.o ./funcionesUTN.d ./funcionesUTN.o ./parser.d ./parser.o ./passenger.d ./passenger.o

.PHONY: clean--2e-


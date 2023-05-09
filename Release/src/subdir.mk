################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Particle.cpp \
../src/Screen.cpp \
../src/Swarm.cpp \
../src/particle_explosion.cpp 

CPP_DEPS += \
./src/Particle.d \
./src/Screen.d \
./src/Swarm.d \
./src/particle_explosion.d 

OBJS += \
./src/Particle.o \
./src/Screen.o \
./src/Swarm.o \
./src/particle_explosion.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/homebrew/Cellar/sdl2/2.26.5/include/SDL2 -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Particle.d ./src/Particle.o ./src/Screen.d ./src/Screen.o ./src/Swarm.d ./src/Swarm.o ./src/particle_explosion.d ./src/particle_explosion.o

.PHONY: clean-src


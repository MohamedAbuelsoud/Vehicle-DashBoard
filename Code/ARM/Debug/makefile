################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include system/src/stm32f4-hal/subdir.mk
-include system/src/newlib/subdir.mk
-include system/src/diag/subdir.mk
-include system/src/cortexm/subdir.mk
-include system/src/cmsis/subdir.mk
-include src/00_COTS/04_SERVICE/Temp/subdir.mk
-include src/00_COTS/04_SERVICE/Speed/subdir.mk
-include src/00_COTS/04_SERVICE/MIL/subdir.mk
-include src/00_COTS/04_SERVICE/Fuel/subdir.mk
-include src/00_COTS/04_SERVICE/BMS/subdir.mk
-include src/00_COTS/02_HAL/Time/subdir.mk
-include src/00_COTS/02_HAL/System_Init/subdir.mk
-include src/00_COTS/02_HAL/ENCODER/subdir.mk
-include src/00_COTS/02_HAL/DATA\ _FRAME/subdir.mk
-include src/00_COTS/02_HAL/ADC_conversion/subdir.mk
-include src/00_COTS/01_MCAL/07_ADC/subdir.mk
-include src/00_COTS/01_MCAL/06_UART/subdir.mk
-include src/00_COTS/01_MCAL/05_DMA/subdir.mk
-include src/00_COTS/01_MCAL/04_EXTI/subdir.mk
-include src/00_COTS/01_MCAL/03_NVIC/subdir.mk
-include src/00_COTS/01_MCAL/02_SYSTICK/subdir.mk
-include src/00_COTS/01_MCAL/01_GPIO/subdir.mk
-include src/00_COTS/01_MCAL/00_RCC/subdir.mk
-include src/00_COTS/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
Test6.hex \

SECONDARY_SIZE += \
Test6.siz \


# All Target
all: Test6.elf secondary-outputs

# Tool invocations
Test6.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM GNU C++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -T mem.ld -T libs.ld -T sections.ld -nostartfiles -Xlinker --gc-sections -L"../ldscripts" -Wl,-Map,"Test6.map" --specs=nano.specs -o "Test6.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Test6.hex: Test6.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex "Test6.elf"  "Test6.hex"
	@echo 'Finished building: $@'
	@echo ' '

Test6.siz: Test6.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley "Test6.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(CPP_DEPS) Test6.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

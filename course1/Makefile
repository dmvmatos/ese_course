#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for the m2 assesment
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.i - Builds <FILE>.i preprocessed file
#      <FILE>.asm - Builds <FILE>.asm assembly file
#      <FILE>.o - Builds <FILE>.o object file
#      compile-all - Builds all source files
#      build - Builds and links all source files
#      clean - removes all generated files
#
# Platform Overrides:
#      CPU - ARM Cortex Architecture (cortex-m4)
#      ARCH - ARM Architecture (armv7e-m)
#      SPECS - Specs file to give the linker (nosys.specs)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# Platform Specific Flags
LINKER_FILE = ../msp432p401r.lds

# Architectures Specific Flags
CPU = cortex-m4
ARCH = thumb
MARCH = armv7e-m
MFLOAT = hard
MFPU = fpv4-sp-d16
SPECS = nosys.specs

ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SIZE-TOOL = arm-none-eabi-size
        LDFLAGS = -T $(LINKER_FILE)
        CFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=$(MARCH) -mfloat-abi=$(MFLOAT) -mfpu=$(MFPU) --specs=$(SPECS)
else
	CC = gcc
	SIZE-TOOL = size
endif

#Executable output file
TARGET = c1m2

# Compiler Flags
LDFLAGS += -Wl,-Map=$(TARGET).map
CFLAGS += -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM)
CPPFLAGS = -E -MD -MP -D$(PLATFORM)
ASFLAGS = -S -D$(PLATFORM)

%.i : %.c
	$(CC) $(CPPFLAGS) -o $*.i $*.c

%.asm : %.c
	$(CC) $(ASFLAGS) -o $*.asm $*.c

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $*.o

OBJS = $(SOURCES:.c=.o)

.PHONY: compile-all
compile-all: $(OBJS)
	$(SIZE-TOOL) -Atd $(OBJS)
	
.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE-TOOL) -Atd $@
	#objdump -S $@


CPPS = $(SOURCES:.c=.i)
ASS = $(SOURCES:.c=.asm)
DEPS = $(SOURCES:.c=.d)

clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map
	rm -f $(CPPS) $(ASS) $(DEPS)

-include $(SOURCES:%.c=%.dep)

#http://www.microhowto.info/howto/automatically_generate_makefile_dependencies.html
#https://bruno.defraine.net/techtips/makefile-auto-dependencies-with-gcc/

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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
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
SPECS = nosys.specs

ifeq ($(PLATFORM),HOST)
	CC = gcc
	SIZE-TOOL = size
else
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	SIZE-TOOL =
endif

#Executable output file
TARGET = c1m2

# Compiler Flags
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
CFLAGS = -Wall -D$(PLATFORM)
CPPFLAGS = -E -MD -MP -D$(PLATFORM)
ASFLAGS = -S -D$(PLATFORM)

%.i : %.c
	$(CC) $(CPPFLAGS) -o $*.i $*.c

%.asm : %.c
	$(CC) $(ASFLAGS) -o $*.asm $*.c
	#Check what can be done with objump

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


CPPS = $(SOURCES:.c=.i)
ASS = $(SOURCES:.c=.asm)

clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map
	rm -f $(CPPS) $(ASS)

-include $(SOURCES:%.c=%.dep)

#Compilar preprocessor main.i
#gcc -E -o main.i main.c -DHOST

#http://www.microhowto.info/howto/automatically_generate_makefile_dependencies.html
#https://bruno.defraine.net/techtips/makefile-auto-dependencies-with-gcc/
#$(CC) -MM $(CFLAGS) -o $*.dep $*.c
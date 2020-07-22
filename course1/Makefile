#------------------------------------------------------------------------------
# Description: Makefile for week 2 application assignment
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <file>.i    - Generate the preprocessed output of <file>.c file.
#      <file>.asm  - Generate assembly output of <file>.c file.
#      <file>.o    - Generate the object file for <file>.c file.
#      compile-all - Compile all object files, but DO NOT link.
#      build       - Compile all object files and link into a final executable.
#      clean       - Remove all compiled objects, preprocessed outputs,
#                    assembly outputs, executable files and build output files.
#
# Platform Overrides:
#      PLATFORM=HOST   - Build target will be the host platform.
#      PLATFORM=MSP432 - Build target will be the MSP432 platform.
#
#------------------------------------------------------------------------------

# Platform Overrides
PLATFORM ?= HOST

# Include source files
include sources.mk

# Target name
TARGET = c1m2

# Architectures Specific Options
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
LINKER_FILE = ../msp432p401r.lds

# Compiler Executable Definition
ifeq ($(PLATFORM), HOST)
# Linker Executable Definition
  CC = gcc
  LD = ld
  SIZE = size
  OBJDUMP = objdump
  # Compiler Flags
  CFLAGS = -Wall -Werror -g -O0 -std=c99
  # Linker Flags
  LDFLAGS = -Xlinker -Map=$(TARGET).map
else
# Linker Executable Definition
  CC = arm-none-eabi-gcc
  LD = arm-none-eabi-ld
  SIZE = arm-none-eabi-size
  OBJDUMP = arm-none-eabi-objdump
  # Compiler Flags
  CFLAGS = -Wall -Werror -g -O0 -std=c99 \
           -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) \
           -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
  # Linker Flags
  LDFLAGS = -Xlinker -Map=$(TARGET).map -T $(LINKER_FILE)
endif

# Preprocessor Flags
CPPFLAGS = -D$(PLATFORM) $(INCLUDES)

# Build Receipes
IMEDIATES = $(SOURCES:.c=.i)
%.i : %.c
	$(CC) -E $< $(CPPFLAGS) $(CFLAGS) -o $@

ASEMBLIES = $(SOURCES:.c=.asm)
%.asm : %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) -o $@

DEPENDENCIES = $(SOURCES:.c=.d)
%.d : %.c
	$(CC) -M $< $(CPPFLAGS) $(CFLAGS) -o $@

OBJECTS = $(SOURCES:.c=.o)
%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

# Phony Targets
.PHONY: compile-all
compile-all: $(OBJECTS)

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJECTS) $(DEPENDENCIES)
	$(CC) $(OBJECTS) $(CFLAGS) $(LDFLAGS) -MD -o $@
	$(SIZE) -Atd $@

$(TARGET).asm : $(TARGET).out
	touch $(TARGET).asm
	$(OBJDUMP) -d -C -S $(TARGET).out > $(TARGET).asm

.PHONY: clean
clean:
	rm -f $(IMEDIATES) $(ASEMBLIES) $(DEPENDENCIES) $(OBJECTS) $(TARGET).out $(TARGET).map $(TARGET).asm *o *d

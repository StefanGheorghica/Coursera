# Add your Source files to this variable
ifeq ($(PLATFORM), HOST)
  SOURCES = main.c \
            memory.c
else
  SOURCES = main.c \
            memory.c \
            system_msp432p401r.c \
            startup_msp432p401r_gcc.c \
            interrupts_msp432p401r_gcc.c
endif

# Add your include paths to this variable
ifeq ($(PLATFORM), HOST)
  INCLUDES = -I../include/common
else
  INCLUDES = -I../include/common \
             -I../include/msp432 \
             -I../include/CMSIS
endif


# Add your Source files to this variable
ifeq ($(PLATFORM), HOST)
  SOURCES = \
	src/main.c \
        src/memory.c \
	src/stats.c  \
	src/data.c   \
	src/course1.c
else
  SOURCES = \
	src/main.c \
        src/memory.c \
	src/stats.c  \
	src/data.c   \
	src/course1.c \
        src/system_msp432p401r.c \
        src/startup_msp432p401r_gcc.c \
        src/interrupts_msp432p401r_gcc.c
endif

# Add your include paths to this variable
ifeq ($(PLATFORM), HOST)
  INCLUDES = -I./include/common
else
  INCLUDES = -I./include/common \
             -I./include/msp432 \
             -I./include/CMSIS
endif


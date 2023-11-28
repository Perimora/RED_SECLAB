# Compiler and flags
CC = riscv32-unknown-elf-gcc
CFLAGS = -march=rv32imac -O2 -nostartfiles -I$(CURDIR)

# Source files
SRCS = main.c

# Object files
OBJS = $(SRCS:.c=.o)

# Output binary
TARGET = red

all: $(TARGET).bin

$(TARGET).bin: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET).bin

.PHONY: all clean

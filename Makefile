CC = riscv64-unknown-elf-gcc
CFLAGS = -nostdlib -fno-builtin -mcmodel=medany -march=rv32g -mabi=ilp32 -Wall -Wextra

QEMU = qemu-system-riscv32
QFLAGS = -nographic -smp 4 -machine virt -bios none

SRCS_ASM = \
	start.S \

SRCS_C = \
	kernel.c \
	uart.c \

OBJS = $(SRCS_ASM:.S=.o)
OBJS += $(SRCS_C:.c=.o)

.DEFAULT_GOAL := all
all: os.elf

os.elf: $(OBJS)
	$(CC) $(CFLAGS) -T os.ld -o os.elf $^

%.o : %.S
	${CC} ${CFLAGS} -c -o $@ $<

%.o : %.c
	${CC} ${CFLAGS} -c -o $@ $<

run: all
	@${QEMU} -M ? | grep virt >/dev/null || exit
	@echo "Press Ctrl-A and then X to exit QEMU"
	@${QEMU} ${QFLAGS} -kernel os.elf

.PHONY : clean
clean:
	rm -rf *.o *.bin *.elf

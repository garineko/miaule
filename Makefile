CC = riscv64-unknown-elf-gcc
CFLAGS = -I./include -nostdlib -fno-builtin -mcmodel=medany -march=rv32g -mabi=ilp32 -Wall -Wextra

QEMU = qemu-system-riscv32
QFLAGS = -nographic -smp 4 -machine virt -bios none

SRC = src/

SRCS_ASM = ${wildcard ${SRC}*.S}
SRCS_C = ${wildcard ${SRC}*.c}

OBJ = obj/

OBJS = ${addprefix ${OBJ}, ${notdir ${SRCS_ASM:.S=.o}}}
OBJS += ${addprefix ${OBJ}, ${notdir ${SRCS_C:.c=.o}}}

BIN = bin/os.elf

.DEFAULT_GOAL := all
all: ${BIN}

${BIN}: ${OBJS}
	${CC} ${CFLAGS} -T os.ld -o ${BIN} $^

${OBJ}%.o : ${SRC}%.S
	${CC} ${CFLAGS} -c -o $@ $<

${OBJ}%.o : ${SRC}%.c
	${CC} ${CFLAGS} -c -o $@ $<

run: all
	@${QEMU} -M ? | grep virt >/dev/null || exit
	@echo "Press Ctrl-A and then X to exit QEMU"
	@${QEMU} ${QFLAGS} -kernel ${BIN}

.PHONY : clean
clean:
	rm -f ${OBJ}* ${BIN}

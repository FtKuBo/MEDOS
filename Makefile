GCC = /usr/src/cross/bin/i686-elf-gcc
CFLAGS = -ffrestanding -Wall -Wextra -g -02

all: clean assembly

clean:
	rm -rf *.o

assembly:
	nasm -f elf32 src/boot/boot.s -o boot.o
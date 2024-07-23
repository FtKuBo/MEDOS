gcc=/usr/opt/cross/bin/i686-elf-gcc
ld=/usr/opt/cross/bin/i686-elf-ld
CFLAGS = -ffreestanding -g

all: clean kernel boot image visual_bochs

clean:
	rm -rf *.o

kernel:
	$(gcc) $(CFLAGS) -c src/kernel.c -o kernel.o
	$(gcc) $(CFLAGS) -c src/vga.c -o vga.o
	$(gcc) $(CFLAGS) -c src/stdlib/stdio.c -o stdio.o
	$(gcc) $(CFLAGS) -c src/gdt/gdt.c -o gdt.o
	$(gcc) $(CFLAGS) -c src/utils/util.c -o util.o
	$(gcc) $(CFLAGS) -c src/interrupts/idt.c -o idt.o
	$(gcc) $(CFLAGS) -c src/pit/timer.c -o timer.o
	$(gcc) $(CFLAGS) -c src/keyboard/keyboard.c -o keyboard.o
	$(gcc) $(CFLAGS) -c src/memory/memory.c -o memory.o

boot:
	nasm -f elf32 src/boot.s -o boot.o
	nasm -f elf32 src/gdt/gdt.s -o gdts.o
	nasm -f elf32 src/interrupts/idt.s -o idts.o
image:
	$(ld) -T linker.ld -o kernel boot.o kernel.o vga.o stdio.o gdt.o gdts.o util.o idt.o idts.o timer.o keyboard.o memory.o
	mv kernel Med/boot/kernel
	grub-mkrescue -o kernel.iso Med/
	rm *.o

visual_bochs:
	bochs -f bochs

visual_qemu:
	qemu-system-i386 kernel.iso


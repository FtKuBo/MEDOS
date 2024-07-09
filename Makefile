CFLAGS = -g -m32 -fno-stack-protector -fno-builtin

all: clean kernel boot image visual

clean:
	rm -rf *.o

kernel:
	gcc $(CFLAGS) -c src/kernel.c -o kernel.o
	gcc $(CFLAGS) -c src/vga.c -o vga.o
	gcc $(CFLAGS) -c src/gdt/gdt.c -o gdt.o
	gcc $(CFLAGS) -c src/utils/util.c -o util.o
	gcc $(CFLAGS) -c src/interrupts/idt.c -o idt.o


boot:
	nasm -f elf32 src/boot.s -o boot.o
	nasm -f elf32 src/gdt/gdt.s -o gdts.o
	nasm -f elf32 src/interrupts/idt.s -o idts.o

image:
	ld -m elf_i386 -T linker.ld -o kernel boot.o kernel.o util.o vga.o gdt.o gdts.o idt.o idts.o
	mv kernel Med/boot/kernel
	grub-mkrescue -o Med.iso Med/
	rm *.o


visual:
	qemu-system-i386 Med.iso
	
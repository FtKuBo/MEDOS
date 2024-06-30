CFLAGS = -m32 -fno-stack-protector -fno-builtin

all: clean kernel boot image visual

clean:
	rm -rf *.o

kernel:
	gcc $(CFLAGS) -c src/kernel.c -o kernel.o
	gcc $(CFLAGS) -c src/vga.c -o vga.o


boot:
	nasm -f elf32 src/boot.s -o boot.o

image:
	ld -m elf_i386 -T linker.ld -o kernel boot.o kernel.o vga.o
	mv kernel Med/boot/kernel
	grub-mkrescue -o Med.iso Med/
	rm *.o


visual:
	qemu-system-i386 Med.iso
	
#MEDOS: Minimalistic x86 Operating System

MEDOS is an experimental operating system written in C and NASM (x86 assembly) for 32-bit systems. It boots using GRUB and includes basic components such as the kernel, VGA support, GDT (Global Descriptor Table), IDT (Interrupt Descriptor Table), keyboard input, PIT (Programmable Interval Timer), MMU (Memory Management Unit), and paging.

Project Status
MEDOS is currently not fully functional; it serves as a learning project and a foundation for further development. The project is on pause but will be resumed in the future.

Running MEDOS
To compile, link, and run the MEDOS project, follow these steps:

Linux Environment: Ensure you are using a Linux environment.
Install Dependencies: Make sure you have the following tools installed:
NASM
GCC (GNU Compiler Collection)
LD (GNU Linker)
GRUB
Bochs (for simulation)
Adjust Makefile: Modify the Makefile according to the location of your cross-compiler.
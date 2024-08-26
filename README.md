# MEDOS: Minimalistic x86 Operating System

state : not finished

MEDOS is an experimental operating system written in C and NASM (x86 assembly) for 32-bit systems. It boots using GRUB and includes basic components such as the kernel, VGA support, GDT (Global Descriptor Table), IDT (Interrupt Descriptor Table), keyboard input, PIT (Programmable Interval Timer), and MMU (Memory Management Unit) with paging.

-Project Status:

MEDOS is currently not fully functional; it serves as a learning project and a foundation for further development. The project is on pause but will be resumed in the future.

-Running MEDOS:

To compile, link, and run the MEDOS project, follow these steps:

-Linux Environment:

It is preferred that you use a Linux environment.

-Install Dependencies:

.Cross-compiler

.NASM

.GCC (GNU Compiler Collection)

.LD (GNU Linker)

.GRUB 

.Bochs (for simulation)

-Adjustments: 

Modify the Makefile according to the location of your cross-compiler.

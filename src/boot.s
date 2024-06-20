%define ALIGN 1<<0
%define MEMINFO 1<<1
%define FLAGS ALIGN | MEMINFO
%define MAGIC 0x1BADB002
%define CHECKSUM -(MAGIC-FLAGS)

section .multiboot

align 4
DD MAGIC
DD FLAGS
DD CHECKSUM


section .bss

align 16
stack_bottom:
    RESB 16384
stack_top:


section .text

global _start
_start:
    MOV esp, stack_top

    ; LOAD THE GDT HERE

    CALL kernel_main

halt:
    hlt
    jmp halt


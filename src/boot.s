BITS 32

section .text
    ALIGN 4
    DD 0x1BADB002
    DD 0x00000003   ; memory and video information
    DD -(0x1BADB002 + 0x00000003)

global start
extern kernel_main

start:
    CLI
    MOV esp, stack
    PUSH ebx  ; multiboot information structure
    PUSH eax  ; magic value
    CALL kernel_main
    HLT
HaltKernel:
    CLI
    HLT
    JMP HaltKernel

section .bss
RESB 8192
stack:
MBOOT_PAGE_ALIGN EQU 1 << 0
MBOOT_MEM_INFO EQU 1 << 1
MBOOT_USER_GFX EQU 0

MBOOT_MAGIC EQU 0x1BADB002
MBOOT_FLAGS EQU MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO | MBOOT_USER_GFX
MBOOT_CHECKSUM EQU -(MBOOT_MAGIC + MBOOT_FLAGS)

section .multiboot
ALIGN 4 
    DD MBOOT_MAGIC
    DD MBOOT_FLAGS
    DD MBOOT_CHECKSUM
    DD 0, 0, 0, 0, 0

    DD 0
    DD 800  ; width
    DD 600  ; height
    DD 32   ; depths

section .bss
ALIGN 16
stack_bottom:
    RESB 16384 * 8
stack_top:

section .boot

global _start
_start:
    MOV eax, (intial_page_dir - 0xC0000000)
    MOV cr3, eax

    MOV ecx, cr4
    OR ecx, 0x10
    MOV cr4, ecx

    MOV ecx, cr0
    OR ecx, 0x80000000    ; enables paging
    MOV cr0, ecx  

    JMP higher_half

section .text
higher_half:    
    MOV esp, stack_top
    PUSH ebx
    XOR ebp, ebp
    extern kernel_main
    CALL kernel_main

halt:
    HLT
    JMP halt

section .data
ALIGN 4096
global intial_page_dir
intial_page_dir:                  ;   setting up page directory entries
    DD 10000011b   
    TIMES 768 - 1 DD 0

    DD (0 << 22) | 10000011b
    DD (1 << 22) | 10000011b
    DD (2 << 22) | 10000011b
    DD (3 << 22) | 10000011b
    TIMES  256-4 DD 0
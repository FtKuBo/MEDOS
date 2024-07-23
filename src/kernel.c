#include "vga.h"
#include "stdint.h"
#include "gdt/gdt.h"
#include "interrupts/idt.h"
#include "pit/timer.h"
#include "stdlib/stdio.h"
#include "keyboard/keyboard.h"
#include "memory/memory.h"
#include "multiboot.h"
#include "utils/util.h"


void kernel_main(uint32_t magic, struct multiboot_info* bootInfo);

void kernel_main(uint32_t magic, struct multiboot_info* bootInfo){
    reset();
    initGdt();
    print("GDT is initialized !\n");
    initIdt();
    print("IDT is initialized !\n");
    initTimer();
    initKeyboard();

    uint32_t mod1 = *(uint32_t*)(bootInfo->mods_addr + 4);
    uint32_t physicalAllocStart = (mod1 + 0xFFF) & ~0xFFF;

    initMemory(bootInfo->mem_upper * 1024, physicalAllocStart);
    print("Memory allocation done!");

    
    
    
    for(;;);
}
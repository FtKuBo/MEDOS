#include "vga.h"
#include "stdint.h"
#include "gdt/gdt.h"
#include "interrupts/idt.h"
#include "pit/timer.h"
#include "stdlib/stdio.h"
#include "keyboard/keyboard.h"
#include "memory/memory.h"


void kernel_main(uint32_t magic, struct multiboot_info* bootInfo);

void kernel_main(uint32_t magic, struct multiboot_info* bootInfo){
    reset();
    initGdt();
    print("GDT is initialized !\n");
    initIdt();
    print("IDT is initialized !\n");
    initTimer();
    initKeyboard();
    initMemory(bootInfo);
    
    
    
    for(;;);
}
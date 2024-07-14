#include "vga.h"
#include "stdint.h"
#include "gdt/gdt.h"
#include "interrupts/idt.h"
#include "pit/timer.h"
#include "stdlib/stdio.h"
#include "keyboard/keyboard.h"


void kernel_main(void);

void kernel_main(void){
    reset();
    initGdt();
    print("GDT is initialized !\n");
    initIdt();
    print("IDT is initialized !\n");
    initTimer();
    initKeyboard();
    
    
    
    for(;;);
}
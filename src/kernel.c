#include "vga.h"
#include "gdt/gdt.h"
#include "interrupts/idt.h"
#include "pit/timer.h"


void kernel_main(void);

void kernel_main(void){
    reset();
    initGdt();
    print("GDT is initialized !\n");
    initIdt();
    print("IDT is initialized !\n");
    initTimer();
    
    
    for(;;);
}
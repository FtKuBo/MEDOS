#include "vga.h"
#include "gdt/gdt.h"


void kernel_main(void);

void kernel_main(void){
    reset();

    initGdt();
    print("GDT is initialized !\n");
}
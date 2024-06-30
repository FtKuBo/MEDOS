#include "vga.h"


void kernel_main(void);

void kernel_main(void){
    reset();
    print("Hello Habibi!");
}
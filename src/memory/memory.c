#include "../stdint.h"
#include "../multiboot.h"
#include "../stdlib/stdio.h"

void initMemory(struct multiboot_info* bootInfo){
    for(int i=0; i<bootInfo->mmap_length; i+= sizeof(struct multiboot_mmap_entry)){
        
        struct multiboot_mmap_entry * mmmt = (struct multiboot_mmap_entry*)(bootInfo->mmap_addr + i);
        printf("Low adrr: %x | High adrr: %x | Low length: %x | High Length: %x | size: %x | Type: %d \n", mmmt->addr_low, mmmt->addr_high, mmmt->len_low, mmmt->len_high, mmmt->size, mmmt->type);
    }
}
#include "gdt.h"

extern void gdtFlush(uint32_t);

struct gdt_entry_structer gdt_entries[6];
struct pointer_structer gdt_ptr;

void initGdt(){
    gdt_ptr.limit = (sizeof(struct gdt_entry_structer) * 6) -1;
    gdt_ptr.base = (uint32_t)&gdt_entries;

    setGdtGate(0,0,0,0,0); // Null segment
    setGdtGate(1,0,0xFFFFFFFF, 0x9A,0xCF); // kernel code segment
    setGdtGate(2,0,0xFFFFFFFF, 0x92,0xCF); // kernel data segment
    setGdtGate(3,0,0xFFFFFFFF, 0xFA,0xCF); // user code segment
    setGdtGate(4,0,0xFFFFFFFF, 0xF2,0xCF); // user data segment
    writeTSS(5, 0x10, 0x0);
    gdtFlush((uint32_t)&gdt_ptr);
} 

void setGdtGate(uint32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran){
    gdt_entries[num].base_low = (base & 0xFFFF);
    gdt_entries[num].base_middle = (base >> 16) & 0xFF;
    gdt_entries[num].base_high = (base >> 24) & 0xFF;

    gdt_entries[num].limit = (limit & 0xFFFF);
    gdt_entries[num].flags = (limit >> 16) & 0x0F;
    gdt_entries[num].flags |= (gran & 0xF0);

    gdt_entries[num].access = access;
}

void writeTSS(uint32_t num, uint16_t ss0, uint32_t esp0){} // 8:10 video 41
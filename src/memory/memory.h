#include "../multiboot.h"
#pragma once

extern uint32_t initial_page_dir[1024];
void initMemory(uint32_t memHighPoint, uint32_t physicalAllocStart);
void pmm_init(uint32_t memLowPoint, uint32_t memHighPoint);
void invalidate(uint32_t vadrr);


#define KERNEL_START 0xC0000000
#define PAGE_FLAG_PRESENT (1 << 0)
#define PAGE_FLAG_WRITE (1 << 1)

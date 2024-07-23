#include "../stdint.h"
#include "../multiboot.h"
#include "../stdlib/stdio.h"
#include "../utils/util.h"
#include "memory.h"

static uint32_t pageFrameMin;
static uint32_t pageFrameMax;
static uint32_t totalPagesAlloc;

#define NUM_PAGES_DIRS 256
#define NUM_PAGE_FRAMES (0x100000000 / 0x1000 / 8)

uint8_t physicalMemoryBitmap[NUM_PAGE_FRAMES / 8];  //  todo : Dynamically, bit array

static uint32_t pageDirs[NUM_PAGES_DIRS][1024] __attribute__((aligned(4096)));
static uint32_t pageDirUsed[NUM_PAGES_DIRS];
// physical memory manager
void pmm_init(uint32_t memLowPoint, uint32_t memHighPoint){
    pageFrameMin = CEIL_DIV(memLowPoint, 0x1000);
    pageFrameMax = memHighPoint / 0x1000;   
    totalPagesAlloc = 0; 

    memset(physicalMemoryBitmap, 0, sizeof(physicalMemoryBitmap));
}

void initMemory(uint32_t memHighPoint, uint32_t physicalAllocStart){
    initial_page_dir[0] = 0; 
    invalidate(0);
    initial_page_dir[1023] = ((uint32_t) initial_page_dir - KERNEL_START) | PAGE_FLAG_PRESENT | PAGE_FLAG_WRITE;
    invalidate(0xFFFFF000);


    pmm_init(physicalAllocStart, memHighPoint);
    memset(pageDirs, 0, 0x1000 * NUM_PAGES_DIRS);
    memset(pageDirUsed, 0, NUM_PAGES_DIRS);

}

void invalidate(uint32_t vadrr){
    asm volatile("invlpg %0" :: "m"(vadrr));
}
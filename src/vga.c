#include "vga.h"
#include "stdint.h"

uint16_t column = 0;
uint16_t line = 0;

uint16_t* const vga = (uint16_t*const) 0xC00B8000;   /*pointer to location of video memory*/
const  uint16_t defaultColor = (COLOR8_BLACK << 8) | (COLOR8_LIGHT_GREY << 12);
uint16_t currentColor = defaultColor;

void reset(){
    uint16_t column = 0;
    uint16_t line = 0;
    currentColor = defaultColor;
    for(uint16_t l = 0; l < height; l++){
        for(uint16_t c = 0; c < width; c++){
            vga[l * width + c] = ' ' | defaultColor;
        }
    }
}

void newLine(){
    if(line < height - 1){
        line ++;
        column = 0;
    }
    else{
        scrollUp();
        column = 0;
    }
}

void scrollUp(){
    for(uint16_t l = 0; l < height; l++){
        for(uint16_t c = 0; c < width; c++){
            vga[(l-1) * width + c] = vga[l * width + c];
        }
    }

    for(uint16_t c = 0; c < width; c++){
        vga[(height-1) * width + c] = ' ' | currentColor;
    }
}

void print(const char *s){
    while(*s){
        switch (*s)
        {
        case '\n':
            newLine();
            break;
        case '\r':
            column = 0; 
            break;
        case '\b':
            if (column == 0 && line != 0){
                line --;
                column = width;
            }
            vga[line * width + (--column)] = ' ' | currentColor;
            break;
        case '\t':
            if(column == width){
                newLine();
            }
            uint16_t tabLen = 4 - (column % 4);
            while(tabLen != 0){
                vga[line * width + (column++)] = ' ' | currentColor;
                tabLen --;
            }
            break;
        
        default:
            if(column == width){
                newLine();
            }
            vga[line * width + (column++)] = *s | currentColor;
            break;
        }
    s++;
    }
}
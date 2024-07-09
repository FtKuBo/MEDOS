global gdtFlush

;This function is responsible for loading the gdt
;
gdtFlush:
    MOV eax, [esp+4]
    LGDT [eax] ; loads the gdt

;segment registers use the correct segment descriptor
    MOV eax, 0x10 ; 0x10 points to gdt table
    MOV ds, ax
    MOV es, ax
    MOV fs, ax  
    MOV gs, ax
    MOV ss, ax

;setting up the code segment
    JMP 0x08:.flush 

.flush:
    RET


global tssFlush

tssFlush:
    MOV ax, 0x2B
    LTR ax
    RET
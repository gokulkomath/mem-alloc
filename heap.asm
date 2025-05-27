bits 64 ;is used in NASM to tell the assembler that you are writing code for a 64-bit architecture
global memspace
%define Heapsize (1024*1024*1024/4)



section .data alloc noexec write progbits
    memspace:
        dq _memspace  ;stores address of _memspace (it is a pointer)

section .heap alloc noexec write nobits
    _memspace:
        heapsize equ Heapsize
        resd heapsize    ; reserve double word heapsize

section .note.GNU-stack noalloc


#include <stdbool.h>
#include <stdio.h>

int foo(char* s);

union reg_32 {
    union reg_16 {
        struct {
            char byte_l;
            char byte_h;
        } bytes;
        short int word;
    } lower;
    int dword;
};

union reg_64 {
    union reg_32 lower;
    unsigned long qword;
    char* ptr;
};

int main() {
    char* s = "picoCTF_f97bb";
    printf("Out: %x\n", foo(s));
    return 0;
}

int foo(char* s) {
    // hack for pointer arithmetic
    union reg_64 rax;
    union reg_64 rbx;
    union reg_64 rcx;
    union reg_64 rdx;

    union reg_32* eax = &rax.lower;
    union reg_32* ebx = &rbx.lower;
    union reg_32* ecx = &rcx.lower;
    union reg_32* edx = &rdx.lower;

    rax.qword = (unsigned long)0;
    rbx.qword = (unsigned long)0;
    rcx.qword = (unsigned long)0;
    rdx.qword = (unsigned long)0;

    // _start



    // log
    printf("rax: | %lx | %x | %x | h: %x | l: %x\n", rax.qword, eax->dword, eax->lower.word, eax->lower.bytes.byte_h, eax->lower.bytes.byte_l);
    printf("rbx: | %lx | %x | %x | h: %x | l: %x\n", rbx.qword, ebx->dword, ebx->lower.word, ebx->lower.bytes.byte_h, ebx->lower.bytes.byte_l);
    printf("rcx: | %lx | %x | %x | h: %x | l: %x\n", rcx.qword, ecx->dword, ecx->lower.word, ecx->lower.bytes.byte_h, ecx->lower.bytes.byte_l);
    printf("rdx: | %lx | %x | %x | h: %x | l: %x\n", rdx.qword, edx->dword, edx->lower.word, edx->lower.bytes.byte_h, edx->lower.bytes.byte_l);
    return eax->dword;


}

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

int main() {
    char* s = "picoCTF_f97bb";
    printf("Out: %x\n", foo(s));
    return 0;
}

int foo(char* s) {
    union reg_32 eax;
    eax.dword = 0;

    printf("dword: %x, word: %x, byte_l: %x, byte_h: %x \n", eax.dword,
           eax.lower.word, eax.lower.bytes.byte_l, eax.lower.bytes.byte_h);
    return eax.dword;
}

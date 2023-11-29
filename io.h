#ifndef IO_H
#define IO_H

#include <stdint.h>

// Define return macros
#define ESUCCESS 0
#define EPROCESS_ERRORED 0x16

void putstr(const char * str) {
    asm volatile(
        // move argument to a0 register
        "mv a0, %0;"
        // calculate address of putstr() --> tp + 0x38
        "addi a1, tp, 0x38;"
        // load function pointer from memory
        "lw a1, 0(a1);"
        // jump to the function pointer
        "jalr a1;"
        :
        : "r"(str)
        : "a0", "a1"
    );

}

int now_ms(uint64_t * arg) {
    int result = -1;
    asm volatile(
        // move argument to a0 register
        "mv a0, %1;"
        // calculate address of now_ms() --> tp + 0x54
        "addi a1, tp, 0x54;"
        // load function pointer from memory
        "lw a1, 0(a1);"
        // jump to the function pointer
        "jalr a1;"
        // store return value in result var
        "mv %1, a0;"
        : "=r"(result)
        : "r"(arg)
        : "a0", "a1"
    );
    return result;
}

void alarm_ms(int alarm) {
asm volatile(
        // move argument to a0 register
        "mv a0, %0;"
        // calculate address of alarm_ms() --> tp + 0x64
        "addi a1, tp, 0x64;"
        // load function pointer from memory
        "lw a1, 0(a1);"
        // jump to the function pointer
        "jalr a1;"
        :
        : "r"(alarm)
        : "a0", "a1"
    );
}


#endif /* IO_H */

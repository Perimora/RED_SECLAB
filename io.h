#ifndef IO_H
#define IO_H

#include <stdint.h>

// Define return macros
#define ESUCCESS 0
#define EPROCESS_ERRORED 0x16

void putstr(const char * str) {
    asm volatile(
        // move argument to a0 register
        "move a0, %0;"
        // calculate address of putstr() --> tp + 0x38
        "addi a1, tp, 0x38;"
        // load function pointer from memory
        "lw a1, 0(a1);"
        // jump to the function pointer
        "c.jalr a1;"
        :
        : "r"(str)
        : "a0", "a1"
    );

}

int now_ms(uint64_t * out) {

}

void alarm_ms(int alarm) {

}


#endif /* IO_H */

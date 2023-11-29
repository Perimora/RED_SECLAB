#ifndef LOG_H
#define LOG_H

void log_printf(const char* msg, int l) {
    asm volatile(
        // move msg to a0 register
        "mv a0, %0;"
        "mv a1, %1;"
        // calculate address of putstr() --> tp + 0x70
        "addi a2, tp, 0x70;"
        // load function pointer from memory
        "lw a2, 0(a2);"
        // jump to the function pointer
        "jalr a2;"
        :
        : "r"(msg), "r"(l)
        : "a0", "a1", "a2"
    );
}

#endif
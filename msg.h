#ifndef MSG_H
#define MSG_H

typedef struct
{
  const char *chars;
}magic_t;

int send_msg_magic(magic_t magic_struct, void* msg, unsigned int msg_size, int flag) {
  int result;
  asm volatile(
      // move magic_struct to a0 register
      "mv a0, %1;"
      // move msg to a1 register
      "mv a1, %2;"
      // move msg_size to a2 register
      "mv a2, %3;"
      // move flag to a3 register
      "mv a3, %4;"
      // calculate address of send_msg_magic() --> tp + 0x78
      "addi a4, tp, 0x78;"
      // load function pointer from memory
      "lw a4, 0(a4);"
      // jump to the function pointer
      "jalr a1;"
      : "=r"(result)
      : "r"(magic_struct), "r"(msg), "r"(msg_size), "r"(flag)
      : "a0", "a1"
  );
  return result;
}

#endif /* GAME_MSG_H */
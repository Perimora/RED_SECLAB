#ifndef MSG_H
#define MSG_H

typedef struct
{
  const char *chars;
}magic_t;

int send_msg_magic(magic_t magic_struct, void* msg, unsigned int msg_size, int flag) {

    return 0;
}

#endif /* GAME_MSG_H */
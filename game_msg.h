#ifndef GAME_MSG_H
#define GAME_MSG_H

#include <log.h>
#include <msg.h>
#include <errors.h>

typedef struct {
  union {
    enum {
      game_msg_ping,
      game_msg_led_rgb,
      game_msg_led_direct,
    } kind;
    int rc;
  } head;
  union {
    struct __attribute__((packed)) {
      uint8_t red;
      uint8_t green;
      uint8_t blue;
    } led;
  } body;
} game_msg_t;

typedef struct
{
  char *chars;
}magic_t;


__attribute__((always_inline)) inline
int ping() {
  game_msg_t msg = {
    .head.kind = game_msg_ping,
  };
  int rc = send_msg_magic((magic_t) { .chars = "LNCH" }, (void*) &msg, sizeof(msg), 1);
  if (rc) {
    log_printf("error while sending ping message: %e", rc);
    return rc;
  }

  if (msg.head.rc)
    log_printf("warning: ping message got \"%e\" as an answer!", msg.head.rc);

  return ESUCCESS;
}

__attribute__((always_inline)) inline
int set_led(uint8_t red, uint8_t green, uint8_t blue) {
  game_msg_t msg = {
    .head.kind = game_msg_led_rgb,
    .body.led = { .red = red, .green = green, .blue = blue },
  };
  int rc = send_msg_magic((magic_t) { .chars = "LNCH" }, (void*) &msg, sizeof(msg), 1);
  if (rc) {
    log_printf("error while sending led message: %e", rc);
    return rc;
  }

  if (msg.head.rc)
    log_printf("warning: led message got \"%e\" as an answer!", msg.head.rc);

  return ESUCCESS;
}

#endif /* GAME_MSG_H */

#include <io.h>
#include <time.h>

#include "game_msg.h"

int main () {
  int rc;

  putstr("hai!\r\n");

  uint64_t next_alarm;
  rc = now_ms(&next_alarm);
  if (rc) goto ERROR;
  next_alarm += 10;

  while (1) {

    for (int i = 0; i < 100; i++) {
      rc = set_led((255 * i) / 100, 0, 0);
      if (rc) goto ERROR;

      alarm_ms(next_alarm);
      next_alarm += 10;
    }

    for (int i = 0; i < 100; i++) {
      rc = set_led((255 * (100 - i)) / 100, 0, 0);
      if (rc) goto ERROR;

      alarm_ms(next_alarm);
      next_alarm += 10;
    }

  }

ERROR:
  putstr("Error!\r\n");
  return EPROCESS_ERRORED;
}

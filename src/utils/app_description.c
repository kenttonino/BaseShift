#include "ansi_color.h"
#include "custom_print.h"
#include "escape_sequence.h"

void app_description(void) {
  text_blue("--------------------------------------------------------", 15);
  add_new_line(2);
  text_green("BaseShift", 38);
  add_new_line(2);
  text_white("A CLI tool thhat converts a number system to another.", 17);
  add_new_line(2);
  text_blue("--------------------------------------------------------", 15);
}

#include "../../displays/ansi_color.h"
#include "../../displays/custom_print.h"
#include "../../displays/escape_sequence.h"

void binary_description(void) {
  text_blue("--------------------------------------------------------", 15);
  add_new_line(2);
  text_green("Binary to Other System", 32);
  add_new_line(2);
  text_blue("--------------------------------------------------------", 15);
}

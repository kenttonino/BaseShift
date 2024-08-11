#include "../displays/ansi_color.h"
#include "../displays/clear_terminal.h"
#include "../displays/escape_sequence.h"
#include "celsius_description.h"
#include <stdio.h>

void celsius_scale(void) {
  clear_terminal();
  add_new_line();
  add_new_line();

  // Display celsius description.
  celsius_description();
  add_new_line();
  add_new_line();
}

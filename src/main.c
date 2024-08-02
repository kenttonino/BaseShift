#include "displays/app_description.h"
#include "displays/app_options.h"
#include "displays/clear_terminal.h"
#include "displays/escape_sequence.h"
#include <stdio.h>

int main(void) {
  // Cleanup the terminal.
  clear_terminal();
  add_new_line();
  add_new_line();

  // App description.
  app_description();
  add_new_tab();
  add_new_line();

  // Show the app options.
  app_options();
  add_new_line();
  add_new_line();

  add_new_line();
  add_new_line();
  return 0;
}

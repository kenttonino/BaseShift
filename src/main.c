#include "displays/app_description.h"
#include "displays/app_options.h"
#include "displays/clear_terminal.h"
#include "displays/error_message.h"
#include "displays/escape_sequence.h"
#include "inputs/main_option.h"
#include <stdio.h>

int main(void) {
  int option;
  int invalid_option = 0;

  while (1) {
    // Cleanup the terminal.
    clear_terminal();
    add_new_line();
    add_new_line();

    // App description.
    app_description();
    add_new_tab();
    add_new_line();
    add_new_line();

    // Show the error message.
    if (invalid_option) {
      error_message("Invalid main option. Please try again.");
      add_new_line();
      add_new_line();
    }

    // Show the app options.
    app_options();
    add_new_line();

    // Ask the user choosen option.
    option = main_option();

    // Exit application right away.
    if (option == 5) {
      break;
    }

    if (option == 1) {
      invalid_option = 0;
      continue;
    }

    if (option == 2) {
      invalid_option = 0;
      continue;
    }

    if (option == 3) {
      invalid_option = 0;
      continue;
    }

    if (option == 4) {
      invalid_option = 0;
      continue;
    }

    invalid_option = 1;
  }

  add_new_line();
  add_new_line();
  return 0;
}

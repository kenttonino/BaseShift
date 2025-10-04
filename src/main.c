#include "menu/binary_system/binary_system.h"
#include "menu/main/menu_main.h"
#include "utils/app_description.h"
#include "utils/app_options.h"
#include "utils/clear_terminal.h"
#include "utils/error_print.h"
#include "utils/escape_sequence.h"

int main(void) {
  int option;
  int invalid_option = 0;

  while (1) {
    // Cleanup the terminal.
    clear_terminal();
    add_new_line(2);

    // App description.
    app_description();
    add_new_tab(1);
    add_new_line(2);

    // Show the error message.
    if (invalid_option) {
      error_print("Invalid main option. Please try again.", 16);
      add_new_line(2);
    }

    // Show the app options.
    app_options();
    add_new_line(1);

    // Ask the user choosen option.
    option = main_option();

    // Exit application right away.
    if (option == 5) {
      break;
    }

    if (option == 1) {
      binary_system();
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

  add_new_line(2);
  return 0;
}

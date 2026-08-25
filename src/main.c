#include "./menu/compute_binary/compute_binary.h"
#include "./menu/compute_decimal/compute_decimal.h"
#include "./menu/compute_octal/compute_octal.h"
#include "./menu/main/menu_main.h"
#include "./utils/utils.h"

int main(void) {
  int option;
  int invalid_option = 0;

  while (1) {
    clear_terminal();
    add_new_line(2);

    app_description();
    add_new_tab(1);
    add_new_line(2);

    if (invalid_option) {
      error_print("Invalid main option. Please try again.", 16);
      add_new_line(2);
    }

    app_options();
    add_new_line(1);

    option = main_option();

    if (option == 5) {
      break;
    }

    if (option == 1) {
      compute_binary();
      invalid_option = 0;
      continue;
    }

    if (option == 2) {
      compute_decimal();
      invalid_option = 0;
      continue;
    }

    if (option == 3) {
      compute_octal();
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

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"
#include "./to_decimal.c"
#include "./to_octal.c"
#include "./to_hexadecimal.c"

void _bin_description(void) {
  text_blue("--------------------------------------------------------", 15);
  add_new_line(2);
  text_green("Binary Conversion", 34);
  add_new_line(2);
  text_white("Convert binary values to other system.", 24);
  add_new_line(2);
  text_blue("--------------------------------------------------------", 15);
}

int _bin_validate(char *bin_input) {
  int is_valid = 0;
  int input_length = strlen(bin_input);
  int num_of_dots = 0;

  for (int i = 0; i < input_length; i++) {
    // Check if there is a minus sign.
    if (bin_input[i] == '-') {
      if (i == 0) {
        is_valid = 1;
        continue;
      } else {
        is_valid = 0;
        break;
      }
    }

    // Check if its a dot.
    if (bin_input[i] == '.') {
      if (num_of_dots == 0) {
        is_valid = 1;
        num_of_dots++;
        continue;
      } else {
        is_valid = 0;
        break;
      }
    }

    // Check if value is alphabet.
    // Return 0 right away.
    if (isalpha(bin_input[i])) {
      is_valid = 0;
      break;
    }

    // Check if either 0 or 1.
    if (bin_input[i] == '1' || bin_input[i] == '0') {
      is_valid = 1;
      continue;
    }

    // Default return.
    is_valid = 0;
    break;;
  }

  return is_valid;
}

void _get_bin_input(char *bin_input) {
  printf(
    "%-16s[%s %sBinary%s %s]%s : ",
    BLUE,
    RESET,
    YELLOW,
    RESET,
    BLUE,
    RESET
  );
  scanf("%s", bin_input);
}

void compute_binary(void) {
  char *bin_input = malloc(100);
  char *garbage_buffer = malloc(100);
  int try_again = 0;

  while (1) {
    // Clean up the terminal.
    clear_terminal();
    add_new_line(2);

    // Show the description.
    _bin_description();
    add_new_line(2);

    // Ask the input.
    _get_bin_input(bin_input);
    fgets(garbage_buffer, 100, stdin);

    // Check the validity of binary input.
    int valid_binary = _bin_validate(bin_input);
    if (valid_binary == 0) {
      // Display error message.
      add_new_line(1);
      printf("%-16sError: Invalid input.%s", RED, RESET);
      add_new_line(2);

      // Ask to try again.
      printf("%-16sTry again (1-yes, 0-no):%s ", WHITE, RESET);
      scanf("%d", &try_again);
      fgets(garbage_buffer, 100, stdin);

      if (try_again) {
        continue;
      } else {
        break;
      }
    }

   to_decimal(bin_input);
   add_new_line(1);

   to_octal(bin_input);
   add_new_line(1);

   to_hexadecimal(bin_input);
   add_new_line(2);

    // Ask to try again.
    printf("%-16sTry again (1-yes, 0-no):%s ", WHITE, RESET);
    scanf("%d", &try_again);
    fgets(garbage_buffer, 100, stdin);

    if (try_again) {
      continue;
    } else {
      break;
    }
  }

  free(bin_input);
  free(garbage_buffer);
}

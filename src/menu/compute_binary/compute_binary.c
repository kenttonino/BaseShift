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

int _bin_validate(char *binary_input) {
  int is_valid = 0;
  int input_length = strlen(binary_input);
  int num_of_dots = 0;

  for (int i = 0; i < input_length; i++) {
    // Check if there is a minus sign.
    if (binary_input[i] == '-') {
      if (i == 0) {
        is_valid = 1;
        continue;
      } else {
        is_valid = 0;
        break;
      }
    }

    // Check if its a dot.
    if (binary_input[i] == '.') {
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
    if (isalpha(binary_input[i])) {
      is_valid = 0;
      break;
    }

    // Check if either 0 or 1.
    if (binary_input[i] == '1' || binary_input[i] == '0') {
      is_valid = 1;
      continue;
    }

    // Default return.
    is_valid = 0;
    break;;
  }

  return is_valid;
}

void _get_bin_input(char *binary_input) {
  printf(
    "%-16s[%s %sBinary%s %s]%s : ",
    BLUE,
    RESET,
    YELLOW,
    RESET,
    BLUE,
    RESET
  );
  scanf("%s", binary_input);
}

void compute_binary(void) {
  char *binary_input = malloc(100);
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
    _get_bin_input(binary_input);
    fgets(garbage_buffer, 100, stdin);

    // Check the validity of binary input.
    int valid_binary = _bin_validate(binary_input);
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

   to_decimal(binary_input);
   add_new_line(1);

   to_octal(binary_input);
   add_new_line(1);

   to_hexadecimal(binary_input);
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

  free(binary_input);
  free(garbage_buffer);
}

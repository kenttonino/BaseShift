#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../../utils/utils.h"
#include "./decimal_description.c"

void _get_dec_input(char *binary_input) {
  printf(
    "%-16s[%s %sDecimal%s %s]%s : ",
    BLUE,
    RESET,
    YELLOW,
    RESET,
    BLUE,
    RESET
  );
  scanf("%s", binary_input);
}

int _dec_validate(char *decimal_input) {
  int is_valid = 0;
  int input_length = strlen(decimal_input);
  int num_of_dots = 0;

  for (int i = 0; i < input_length; i++) {
    // Check if there is a minus sign.
    if (decimal_input[i] == '-') {
      if (i == 0) {
        is_valid = 1;
        continue;
      } else {
        is_valid = 0;
        break;
      }
    }

    // Check if its a dot.
    if (decimal_input[i] == '.') {
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
    if (isalpha(decimal_input[i])) {
      is_valid = 0;
      break;
    }


    // Default return.
    is_valid = 1;
  }

  return is_valid;
}


void compute_decimal(void) {
  char *dec_input = malloc(sizeof(char) * 1000);
  char *garbage_buffer = malloc(sizeof(char) * 1000);
  int try_again = 0;

  while (1) {
    // Clean up the terminal.
    clear_terminal();
    add_new_line(2);

    // Show the description.
    decimal_description();
    add_new_line(2);

    // Ask the input.
    _get_dec_input(dec_input);
    fgets(garbage_buffer, 100, stdin);

    // Check the validity of decimal input.
    int valid_dec = _dec_validate(dec_input);
    if (valid_dec == 0) {
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

  free(dec_input);
  free(garbage_buffer);
}

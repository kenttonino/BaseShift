#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"
#include "binary_description.c"
#include "binary_to_decimal.c"
#include "binary_validate.c"
#include "get_binary_input.c"
#include "binary_to_octal.c"
#include "binary_to_hexadecimal.c"

void binary_system(void) {
  char *binary_input = malloc(100);
  char *garbage_buffer = malloc(100);
  int try_again = 0;

  while (1) {
    // Clean up the terminal.
    clear_terminal();
    add_new_line(2);

    // Show the description.
    binary_description();
    add_new_line(2);

    // Ask the input.
    get_binary_input(binary_input);
    fgets(garbage_buffer, 100, stdin);

    // Check the validity of binary input.
    int valid_binary = binary_validate(binary_input);
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

   binary_to_decimal(binary_input);
   add_new_line(1);

   binary_to_octal(binary_input);
   add_new_line(1);

   binary_to_hexadecimal(binary_input);
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

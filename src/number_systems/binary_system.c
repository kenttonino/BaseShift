#include "../displays/ansi_color.h"
#include "../displays/clear_terminal.h"
#include "../displays/escape_sequence.h"
#include "binary_description.h"
#include "binary_validate.h"
#include <stdio.h>
#include <string.h>
#include "reverse_string.h"

void binary_system(void) {
  char *binary_input = malloc(100);
  char *garbage_buffer = malloc(100);
  int is_valid_binary = 1;
  int try_again = 0;

  while (1) {
    // Clean up the terminal.
    clear_terminal();
    add_new_line();
    add_new_line();

    // Show the description.
    binary_description();
    add_new_line();
    add_new_line();

    // Ask the input.
    printf("%-16sBinary:%s ", WHITE, RESET);
    scanf("%s", binary_input);
    fgets(garbage_buffer, 100, stdin);

    // Check the validity of binary input.
    if (binary_validate(binary_input) == 0) {
      // Display error message.
      add_new_line();
      printf("%-16sError: Invalid input.%s", RED, RESET);
      add_new_line();
      add_new_line();

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

    // TODO: Handle the computation for binary to decimal.
    // TODO: Handle the computation for negative binary.
    // TODO: Handle the computation for binary with dot.
    printf("%s \n", reverse_string(binary_input));

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
}

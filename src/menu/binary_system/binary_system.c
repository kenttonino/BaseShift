#include "../../utils/ansi_color.h"
#include "../../utils/clear_terminal.h"
#include "../../utils/utils.h"
#include "binary_description.h"
#include "binary_to_decimal.h"
#include "binary_validate.h"
#include <stdio.h>
#include <stdlib.h>

void binary_system(void) {
  char *binary_input = malloc(100);
  char *garbage_buffer = malloc(100);
  int is_valid_binary = 1;
  int try_again = 0;

  while (1) {
    // Clean up the terminal.
    clear_terminal();
    add_new_line(2);

    // Show the description.
    binary_description();
    add_new_line(2);

    // Ask the input.
    printf("%-16s[%s %sBinary%s %s]%s : ", BLUE, RESET, GREEN, RESET, BLUE,
           RESET);
    scanf("%s", binary_input);
    fgets(garbage_buffer, 100, stdin);

    // Check the validity of binary input.
    if (binary_validate(binary_input) == 0) {
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

    // TODO: Handle the computation for negative binary input to decimal.
    // TODO: Handle the computation for binary with dot to decimal.
    binary_to_decimal(binary_input);
    add_new_line(1);

    // TODO: Handle the computation for binary to octal.
    printf("%-16s[%s %sOctal%s %s]%s : %sTODO%s", BLUE, RESET, GREEN, RESET,
           BLUE, RESET, YELLOW, RESET);
    add_new_line(1);

    // TODO: Handle the computation for binary to hexadecimal.
    printf("%-16s[%s %sHexadecimal%s %s]%s : %sTODO%s", BLUE, RESET, GREEN,
           RESET, BLUE, RESET, YELLOW, RESET);
    add_new_line(3);

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

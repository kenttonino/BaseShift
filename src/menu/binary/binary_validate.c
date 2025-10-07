#include <ctype.h>
#include <string.h>

int binary_validate(char *binary_input) {
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
    continue;
  }

  return is_valid;
}

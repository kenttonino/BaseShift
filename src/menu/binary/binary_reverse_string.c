#include <string.h>

char *binary_reverse_string(char *input) {
  int input_length = strlen(input);
  int current_index = input_length - 1;
  int index_increment = 0;
  static char reversed_string[1000];

  for (; current_index > -1; current_index--) {
    reversed_string[index_increment] = input[current_index];
    index_increment++;
  }

  return reversed_string;
}

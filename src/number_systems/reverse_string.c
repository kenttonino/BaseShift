#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* reverse_string(char *input) {
  int input_length = strlen(input);
  int current_index = input_length - 1;
  char* reversed_string = malloc(sizeof(char) * input_length);

  for (; current_index > -1; current_index--) {
    printf("%c \n", input[current_index]);
  }

  return reversed_string;
}

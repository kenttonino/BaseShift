#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils/utils.h"
#include "./to_hex_bin.c"
#include "./to_hex_dec.c"

void _hex_description() {
  text_blue("--------------------------------------------------------", 15);
  add_new_line(2);
  text_green("Hexadecimal Conversion", 34);
  add_new_line(2);
  text_white("Convert hexadecimal digits to other systems.", 24);
  add_new_line(2);
  text_blue("--------------------------------------------------------", 15);
}

void _get_hex_input(char *hex_input) {
  printf(
    "%-16s[%s %sHexadecimal%s %s]%s : ",
    BLUE,
    RESET,
    YELLOW,
    RESET,
    BLUE,
    RESET
  );
  scanf("%s", hex_input);
}

int _hex_validate(char *hex_input) {
  int is_valid = 0;
  int input_length = strlen(oct_input);
  int num_of_dots = 0;

  for (int i = 0; i < input_length; i++) {
    if (oct_input[i] == '-') {
      if (i == 0) {
        is_valid = 1;
        continue;
      } else {
        is_valid = 0;
        break;
      }
    }

    if (oct_input[i] == '.') {
      if (num_of_dots == 0) {
        is_valid = 1;
        num_of_dots++;
        continue;
      } else {
        is_valid = 0;
        break;
      }
    }

    if (isalpha(oct_input[i])) {
      is_valid = 0;
      break;
    }

    if (isdigit(oct_input[i]) == 0) {
      is_valid = 0;
      break;
    }

    static char oct_buffer[2];
    memset(oct_buffer, 0, sizeof(char) * 2);
    oct_buffer[0] = oct_input[i];
    double double_current_oct = atof(oct_buffer);
    int int_current_oct = (int) double_current_oct;
    if (int_current_oct > 7) {
      is_valid = 0;
      break;
    }

    is_valid = 1;
  }

  return is_valid;
}

void compute_hexadecimal(void) {
  char *hex_input = malloc(sizeof(char) * 1000);
  char *garbage_buffer = malloc(sizeof(char) * 1000);
  int try_again = 0;

  while (1) {
    clear_terminal();
    add_new_line(2);

    _hex_description();
    add_new_line(2);

    _get_hex_input(hex_input);
    fgets(garbage_buffer, 100, stdin);

    int valid_oct = _hex_validate(hex_input);
    if (valid_oct == 0) {
      add_new_line(1);
      printf("%-16sError: Invalid input.%s", RED, RESET);
      add_new_line(2);

      printf("%-16sTry again (1-yes, 0-no):%s ", WHITE, RESET);
      scanf("%d", &try_again);
      fgets(garbage_buffer, 100, stdin);

      if (try_again) {
        continue;
      } else {
        break;
      }
    }

    to_hex_bin(hex_input);
    add_new_line(1);
    to_hex_dec(hex_input);
    add_new_line(1);
    to_oct_hex(oct_input);
    add_new_line(2);

    printf("%-16sTry again (1-yes, 0-no):%s ", WHITE, RESET);
    scanf("%d", &try_again);
    fgets(garbage_buffer, 100, stdin);

    if (try_again) {
      continue;
    } else {
      break;
    }
  }

  free(oct_input);
  free(garbage_buffer);
}

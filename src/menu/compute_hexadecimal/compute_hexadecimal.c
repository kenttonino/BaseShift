#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils/utils.h"
#include "./to_hex_bin.c"
#include "./to_hex_dec.c"
#include "./to_hex_oct.c"

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

int is_valid_hex(char* hex_digit) {
  if (
      strcmp(hex_digit, "0") ||
      strcmp(hex_digit, "1") ||
      strcmp(hex_digit, "2") ||
      strcmp(hex_digit, "3") ||
      strcmp(hex_digit, "4") ||
      strcmp(hex_digit, "5") ||
      strcmp(hex_digit, "6") ||
      strcmp(hex_digit, "7") ||
      strcmp(hex_digit, "8") ||
      strcmp(hex_digit, "9") ||
      strcmp(hex_digit, "a") ||
      strcmp(hex_digit, "A") ||
      strcmp(hex_digit, "b") ||
      strcmp(hex_digit, "B") ||
      strcmp(hex_digit, "c") ||
      strcmp(hex_digit, "C") ||
      strcmp(hex_digit, "d") ||
      strcmp(hex_digit, "D") ||
      strcmp(hex_digit, "e") ||
      strcmp(hex_digit, "E") ||
      strcmp(hex_digit, "f") ||
      strcmp(hex_digit, "F")
  ) return 1;

  return 0;
}

// TODO: Handle the hex input validation.
int _hex_validate(char *hex_input) {
  int is_valid = 0;
  int input_length = strlen(hex_input);
  int num_of_dots = 0;

  for (int i = 0; i < input_length; i++) {
    if (hex_input[i] == '-') {
      if (i == 0) {
        is_valid = 1;
        continue;
      } else {
        is_valid = 0;
        break;
      }
    }

    if (hex_input[i] == '.') {
      if (num_of_dots == 0) {
        is_valid = 1;
        num_of_dots++;
        continue;
      } else {
        is_valid = 0;
        break;
      }
    }

    static char hex_buffer[2];
    memset(hex_buffer, 0, sizeof(char) * 2);
    hex_buffer[0] = hex_input[i];
    if (is_valid_hex(hex_buffer) == 0) {
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

    int valid_hex = _hex_validate(hex_input);
    if (valid_hex == 0) {
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

    printf("hex_input: %s", hex_input);
    add_new_line(1);
    to_hex_bin(hex_input);
    add_new_line(1);
    to_hex_dec(hex_input);
    add_new_line(1);
    to_hex_oct(hex_input);
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

  free(hex_input);
  free(garbage_buffer);
}

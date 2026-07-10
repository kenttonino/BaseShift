#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../../utils/utils.h"
#include "./to_decimal_binary.c"
#include "./to_decimal_octal.c"

void _dec_description(void) {
  text_blue("--------------------------------------------------------", 15);
  add_new_line(2);
  text_green("Decimal Conversion", 34);
  add_new_line(2);
  text_white("Convert decimal values to other system.", 24);
  add_new_line(2);
  text_blue("--------------------------------------------------------", 15);
}

void _get_dec_input(char *dec_input) {
  printf(
    "%-16s[%s %sDecimal%s %s]%s : ",
    BLUE,
    RESET,
    YELLOW,
    RESET,
    BLUE,
    RESET
  );
  scanf("%s", dec_input);
}

int _dec_validate(char *dec_input) {
  int is_valid = 0;
  int input_length = strlen(dec_input);
  int num_of_dots = 0;

  for (int i = 0; i < input_length; i++) {
    if (dec_input[i] == '-') {
      if (i == 0) {
        is_valid = 1;
        continue;
      } else {
        is_valid = 0;
        break;
      }
    }

    if (dec_input[i] == '.') {
      if (num_of_dots == 0) {
        is_valid = 1;
        num_of_dots++;
        continue;
      } else {
        is_valid = 0;
        break;
      }
    }

    if (isalpha(dec_input[i])) {
      is_valid = 0;
      break;
    }


    is_valid = 1;
  }

  return is_valid;
}


void compute_decimal(void) {
  char *dec_input = malloc(sizeof(char) * 1000);
  char *garbage_buffer = malloc(sizeof(char) * 1000);
  int try_again = 0;

  while (1) {
    clear_terminal();
    add_new_line(2);

    _dec_description();
    add_new_line(2);

    _get_dec_input(dec_input);
    fgets(garbage_buffer, 100, stdin);

    int valid_dec = _dec_validate(dec_input);
    if (valid_dec == 0) {
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

    to_decimal_binary(dec_input);
    add_new_line(1);
    to_decimal_octal(dec_input);
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

  free(dec_input);
  free(garbage_buffer);
}

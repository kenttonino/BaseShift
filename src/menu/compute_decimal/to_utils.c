#include <string.h>

typedef struct {
  char* before_dot;
  char* after_dot;
} DottedDecimal;


DottedDecimal _get_dec_bin_dotted(char* dec_input) {
  // Store the decimal input in new variable.
  static char dec_buffer[1000];
  memset(dec_buffer, 0, sizeof(char) * 1000);
  memmove(dec_buffer, dec_input, strlen(dec_input));

  // Sanitized the decimal values before and after dot.
  static char dec_before_dot[1000];
  static char dec_after_dot[1000];
  memset(dec_before_dot, 0, sizeof(char) * 1000);
  memset(dec_after_dot, 0, sizeof(char) * 1000);

  int is_after_dot = 0;
  int counter_before_dot = 0;
  int counter_after_dot = 0;
  for (int i = 0; dec_input[i] != '\0'; i++) {
    if (dec_input[i] == '.') {
      is_after_dot = 1;
      continue;
    }

    if (is_after_dot) {
      dec_after_dot[counter_after_dot++] = dec_input[i];
      continue;
    } else {
      dec_before_dot[counter_before_dot++] = dec_input[i];
    }
  }

  // Reset to the null terminator to stop reading this variables.
  dec_before_dot[counter_before_dot] = '\0';
  dec_after_dot[counter_after_dot] = '\0';

  DottedDecimal sanitized_dec;
  sanitized_dec.before_dot = dec_before_dot;
  sanitized_dec.after_dot = dec_after_dot;

  return sanitized_dec;
}

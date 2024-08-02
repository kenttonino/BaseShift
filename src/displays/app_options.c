#include "ansi_color.h"
#include "escape_sequence.h"

void app_options(void) {
  printf("%-16s[%s %s1%s %s]%s Convert Binary Numbers", BLUE, RESET, GREEN,
         RESET, BLUE, RESET);
  add_new_line();
  printf("%-16s[%s %s2%s %s]%s Convert Decimal Numbers", BLUE, RESET, GREEN,
         RESET, BLUE, RESET);
  add_new_line();
  printf("%-16s[%s %s3%s %s]%s Convert Octal Numbers", BLUE, RESET, GREEN,
         RESET, BLUE, RESET);
  add_new_line();
  printf("%-16s[%s %s4%s %s]%s Convert Hexadecimal Numbers", BLUE, RESET, GREEN,
         RESET, BLUE, RESET);
  add_new_line();
  printf("%-16s[%s %s5%s %s]%s Exit", BLUE, RESET, GREEN, RESET, BLUE, RESET);
  add_new_line();
}

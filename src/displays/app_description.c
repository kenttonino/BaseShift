#include "ansi_color.h"
#include "escape_sequence.h"

void app_description(void) {
  printf("%-15s--------------------------------------------------------%s",
         BLUE, RESET);
  add_new_line(2);
  printf("%-38sBaseShift%s", GREEN, RESET);
  add_new_line(2);
  printf("%-17sA CLI tool that converts a number system to another.%s", WHITE,
         RESET);
  add_new_line(2);
  printf("%-15s--------------------------------------------------------%s",
         BLUE, RESET);
}

#include <stdio.h>

/*
 * Output a new lines based on the paramater value.
 *
 * */
void add_new_line(int num_lines) {
  for (int i = 0; i < num_lines; i++) {
    printf("\n");
  }
}

void add_new_tab(void) { printf("\t"); }

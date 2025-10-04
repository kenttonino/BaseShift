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

/*
 * Out a tabs based on the parameter value.
 *
 * */
void add_new_tab(int num_tabs) {
  for (int i = 0; i < num_tabs; i++) {
    printf("\t");
  }
}

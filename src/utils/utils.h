#ifndef UTILS_H
#define UTILS_H
#include "escape_sequence.c"
#include "error_print.c"

extern void error_print(char *text, int width);
extern void add_new_line(int num_lines);
extern void add_new_tab(int num_tabs);

#endif

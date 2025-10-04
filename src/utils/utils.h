#ifndef UTILS_H
#define UTILS_H

// * Function definitions of utils.
#include "escape_sequence.c"
#include "error_print.c"
#include "ansi_codes.c"
#include "clear_terminal.c"

// * Function declarations of utils.
extern void clear_terminal(void);
extern void error_print(char *text, int width);
extern void add_new_line(int num_lines);
extern void add_new_tab(int num_tabs);

#endif

/*
 * These are the reusable functions where you can
 * print a text or message with ANSI color
 * codes support.
 *
 * This also includes a custom width, to handle
 * the spacing in left side, instead of using
 * spaces manually. Which is kind of similar
 * to C++ setw function.
 *
 * */

#include "./ansi_color.h"
#include <stdio.h>

void text_white(char *message, int width) {
  printf("%-*s%s%s", width, WHITE, message, RESET);
}

void text_green(char *message, int width) {
  printf("%-*s%s%s", width, GREEN, message, RESET);
}

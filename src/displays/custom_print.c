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

void text_red(char *text, int width) {
  printf("%-*s%s%s", width, RED, text, RESET);
}

void text_white(char *text, int width) {
  printf("%-*s%s%s", width, WHITE, text, RESET);
}

void text_green(char *text, int width) {
  printf("%-*s%s%s", width, GREEN, text, RESET);
}

void text_blue(char *text, int width) {
  printf("%-*s%s%s", width, BLUE, text, RESET);
}

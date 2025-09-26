#include "ansi_color.h"
#include <stdio.h>

void error_message(char *message) { printf("%-16s%s%s", RED, message, RESET); }

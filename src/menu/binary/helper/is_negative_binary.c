#include <string.h>

// If the binary input does include negative without dot.
int is_negative_binary(char *binary_input) {
  if (strrchr(binary_input, '-') != NULL && strrchr(binary_input, '.') == NULL) {
    return 1;
  } else {
    return 0;
  }
}

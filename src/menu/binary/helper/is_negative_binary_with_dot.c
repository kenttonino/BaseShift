#include <string.h>

// If the binary input does include a negative and dot.
int is_negative_binary_with_dot(char *binary_input) {
  if (strrchr(binary_input, '-') != NULL && strrchr(binary_input, '.') != NULL) {
    return 1;
  } else {
    return 0;
  }
}

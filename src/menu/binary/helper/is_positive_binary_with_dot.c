#include <string.h>

// If the binary input does have a dot without negative sign.
int is_positive_binary_with_dot(char *binary_input) {
  if (strrchr(binary_input, '-') == NULL && strrchr(binary_input, '.') != NULL) {
    return 1;
  } else {
    return 0;
  }
}

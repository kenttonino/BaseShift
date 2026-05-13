#include <string.h>

// If the binary input does not include a dot (.) or negative (-).
int is_positive_binary(char *binary_input) {
  if (strrchr(binary_input, '-') == NULL && strrchr(binary_input, '.') == NULL) {
    return 1;
  } else {
    return 0;
  }
}

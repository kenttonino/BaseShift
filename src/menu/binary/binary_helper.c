#include <string.h>

// If the binary input does not include a dot (.) or negative (-).
int is_positive_binary(char *binary_input) {
  if (strrchr(binary_input, '-') == NULL &&
      strrchr(binary_input, '.') == NULL) {
    return 1;
  } else {
    return 0;
  }
}

// If the binary input does have a dot without negative sign.
int is_positive_binary_with_dot(char *binary_input) {
  if (strrchr(binary_input, '-') == NULL &&
      strrchr(binary_input, '.') != NULL) {
    return 1;
  } else {
    return 0;
  }
}

// If the binary input does include negative without dot.
int is_negative_binary(char *binary_input) {
  if (strrchr(binary_input, '-') != NULL &&
      strrchr(binary_input, '.') == NULL) {
    return 1;
  } else {
    return 0;
  }
}

// If the binary input does include a negative and dot.
int is_negative_binary_with_dot(char *binary_input) {
  if (strrchr(binary_input, '-') != NULL &&
      strrchr(binary_input, '.') != NULL) {
    return 1;
  } else {
    return 0;
  }
}

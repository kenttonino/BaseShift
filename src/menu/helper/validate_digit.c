#include <string.h>
#include <string.h>

int is_positive(char *input) {
  if (strrchr(input, '-') == NULL && strrchr(input, '.') == NULL) {
    return 1;
  } else {
    return 0;
  }
}

int is_positive_radixp(char *input) {
  if (strrchr(input, '-') == NULL && strrchr(input, '.') != NULL) {
    return 1;
  } else {
    return 0;
  }
}

int is_negative(char *input) {
  if (strrchr(input, '-') != NULL && strrchr(input, '.') == NULL) {
    return 1;
  } else {
    return 0;
  }
}

int is_negative_radixp(char *input) {
  if (strrchr(input, '-') != NULL && strrchr(input, '.') != NULL) {
    return 1;
  } else {
    return 0;
  }
}

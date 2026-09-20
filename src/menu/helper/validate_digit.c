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

typedef struct {
  int zero_only;
  int num_zero_prefix;
} ZeroPrefix;
ZeroPrefix is_zero_only(char* input) {
  int zero_only = 1;
  int num_zero_prefix = 0;
  for (size_t i = 0; i < strlen(input); i++) {
<<<<<<< HEAD
    if (i == 0 && input[i] == '-') {
      continue;
    }

=======
>>>>>>> ae7d12d (feat: is_zero_only mapper)
    if (input[i] == '0') {
      num_zero_prefix++;
      continue;
    } else {
      zero_only = 0;
      break;
    }
  }

  ZeroPrefix zero_prefix;
  zero_prefix.zero_only = zero_only;
  zero_prefix.num_zero_prefix = num_zero_prefix;
  return zero_prefix;
}

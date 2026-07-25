#ifndef HELPER_H
#define HELPER_H
#include "./reverse_string.c"
#include "./validate_digit.c"

typedef struct {
  char* before_radixp;
  char* after_radixp;
} GenericInput;

extern char *reverse_string(char *input);
extern int is_negative(char *input);
extern int is_negative_radixp(char *input);
extern int is_positive(char *input);
extern int is_positive_radixp(char *input);

#endif

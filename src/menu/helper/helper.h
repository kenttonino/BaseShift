#ifndef HELPER_H
#define HELPER_H
#include "./reverse_string.c"
#include "./validate_digit.c"
#include "./generic_input.c"

extern char* radixp_adder(char* input);
extern GenericInput get_generic_input(char* input);
extern char* reverse_string(char *input);
extern int is_negative(char *input);
extern int is_negative_radixp(char *input);
extern int is_positive(char *input);
extern int is_positive_radixp(char *input);

#endif

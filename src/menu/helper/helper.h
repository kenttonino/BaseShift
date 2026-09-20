#ifndef HELPER_H
#define HELPER_H
#include "./reverse_string.c"
#include "./validate_digit.c"
#include "./generic_input.c"
#include "./mapper.c"

extern char* radixp_adder(char* input);
extern GenericInput get_generic_input(char* input);
extern char* get_bin_hex_mapper(char* bin);
extern char* reverse_string(char* input);
extern int is_negative(char* input);
extern int is_negative_radixp(char* input);
extern int is_positive(char* input);
extern int is_positive_radixp(char* input);
extern ZeroPrefix is_zero_only(char* input);

#endif

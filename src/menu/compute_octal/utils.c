#include <string.h>

// Return a 3 digits binary equivalent of octal.
char* get_oct_bin_3d_mapper(char* oct) {
  if (strcmp(oct, "1") == 0) return "001";
  if (strcmp(oct, "2") == 0) return "010";
  if (strcmp(oct, "3") == 0) return "011";
  if (strcmp(oct, "4") == 0) return "100";
  if (strcmp(oct, "5") == 0) return "101";
  if (strcmp(oct, "6") == 0) return "110";
  if (strcmp(oct, "7")) return "111";
  return "000";
}

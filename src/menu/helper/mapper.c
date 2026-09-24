#include <string.h>

// Convert 4 digits binary to hex equivalent.
// E.g. 1111 -> F
char* get_bin_hex_mapper(char* bin) {
  if (strcmp(bin, "0001") == 0) return "1";
  if (strcmp(bin, "0010") == 0) return "2";
  if (strcmp(bin, "0011") == 0) return "3";
  if (strcmp(bin, "0100") == 0) return "4";
  if (strcmp(bin, "0101") == 0) return "5";
  if (strcmp(bin, "0110") == 0) return "6";
  if (strcmp(bin, "0111") == 0) return "7";
  if (strcmp(bin, "1000") == 0) return "8";
  if (strcmp(bin, "1001") == 0) return "9";
  if (strcmp(bin, "1010") == 0) return "A";
  if (strcmp(bin, "1011") == 0) return "B";
  if (strcmp(bin, "1100") == 0) return "C";
  if (strcmp(bin, "1101") == 0) return "D";
  if (strcmp(bin, "1110") == 0) return "E";
  if (strcmp(bin, "1111") == 0) return "F";
  return "0";
}

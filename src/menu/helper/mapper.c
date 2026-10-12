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

// Convert hex digit to 4 digits binary.
char* get_hex_bin_mapper(char* hex) {
  if (strcmp(hex, "1") == 0) return "0001";
  if (strcmp(hex, "2") == 0) return "0010";
  if (strcmp(hex, "3") == 0) return "0011";
  if (strcmp(hex, "4") == 0) return "0100";
  if (strcmp(hex, "5") == 0) return "0101";
  if (strcmp(hex, "6") == 0) return "0110";
  if (strcmp(hex, "7") == 0) return "0111";
  if (strcmp(hex, "8") == 0) return "1000";
  if (strcmp(hex, "9") == 0) return "1001";
  if (strcmp(hex, "a") == 0 || strcmp(hex, "A") == 0) return "1010";
  if (strcmp(hex, "b") == 0 || strcmp(hex, "B") == 0) return "1011";
  if (strcmp(hex, "c") == 0 || strcmp(hex, "C") == 0) return "1100";
  if (strcmp(hex, "d") == 0 || strcmp(hex, "D") == 0) return "1101";
  if (strcmp(hex, "e") == 0 || strcmp(hex, "E") == 0) return "1110";
  if (strcmp(hex, "f") == 0 || strcmp(hex, "F") == 0) return "1111";
  return "0000";
}

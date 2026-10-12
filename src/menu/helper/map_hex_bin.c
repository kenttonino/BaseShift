#include <string.h>

// Convert hex digit to 4 digits binary.
char* map_hex_bin(char* hex) {
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

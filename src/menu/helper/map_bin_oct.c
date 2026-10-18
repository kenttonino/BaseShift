#include <string.h>

char* map_bin_oct(char* hex) {
  if (strcmp(hex, "001") == 0) return "1";
  if (strcmp(hex, "010") == 0) return "2";
  if (strcmp(hex, "011") == 0) return "3";
  if (strcmp(hex, "100") == 0) return "4";
  if (strcmp(hex, "101") == 0) return "5";
  if (strcmp(hex, "110") == 0) return "6";
  if (strcmp(hex, "111") == 0) return "7";
  return "0";
}

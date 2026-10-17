#include <string.h>

int map_hex_dec(char* hex) {
  if (strcmp(hex, "1") == 0) return 1;
  if (strcmp(hex, "2") == 0) return 2;
  if (strcmp(hex, "3") == 0) return 3;
  if (strcmp(hex, "4") == 0) return 4;
  if (strcmp(hex, "5") == 0) return 5;
  if (strcmp(hex, "6") == 0) return 6;
  if (strcmp(hex, "7") == 0) return 7;
  if (strcmp(hex, "8") == 0) return 8;
  if (strcmp(hex, "9") == 0) return 9;
  if (strcmp(hex, "a") == 0 || strcmp(hex, "A") == 0) return 10;
  if (strcmp(hex, "b") == 0 || strcmp(hex, "B") == 0) return 11;
  if (strcmp(hex, "c") == 0 || strcmp(hex, "C") == 0) return 12;
  if (strcmp(hex, "d") == 0 || strcmp(hex, "D") == 0) return 13;
  if (strcmp(hex, "e") == 0 || strcmp(hex, "E") == 0) return 14;
  if (strcmp(hex, "f") == 0 || strcmp(hex, "F") == 0) return 15;
  return 0;
}

#ifndef COMPUTE_BINARY_TYPES_H
#define COMPUTE_BINARY_TYPES_H

// Sanitized binary attributes length should be divisible by 3.
typedef struct {
  char *before_dot;
  char *after_dot;
} SanitizedBinary;

#endif

#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  const char *src_char = src;
  char *dest_char = dest;
  for (s21_size_t i = 0; i < n; i++) {
    dest_char[i] = src_char[i];
  }
  return dest_char;
}
#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t nn) {
  char *est = dest + s21_strlen(dest);
  while (*src != '\0' && nn--) *est++ = *src++;
  *est = '\0';
  return dest;
}
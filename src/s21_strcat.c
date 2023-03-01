#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  char *num;
  char *est = dest;
  while (*est != '\0') est++;
  while (*src != '\0') *est++ = *src++;
  *est = '\0';
  num = dest;
  return num;
}
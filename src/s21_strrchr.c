#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *isCharFound = s21_NULL;

  if (str != s21_NULL) {
    do {
      if (*str == (char)c) {
        isCharFound = (char *)str;
      }
    } while (*str++);
  }
  return isCharFound;
}

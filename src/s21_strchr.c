#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  c = (char)c;
  while (*str != c && *str != '\0') {
    str++;
  }
  if (*str == c) {
    return (char *)str;
  } else {
    return s21_NULL;
  }
}
#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *c = s21_NULL;
  if (str) {
    c = str;
    while (*c && s21_strchr(delim, *c)) *c++ = '\0';
  }
  if (c != s21_NULL && *c != '\0') {
    str = c;
    while (*c && !s21_strchr(delim, *c)) ++c;
    while (*c && s21_strchr(delim, *c)) *c++ = '\0';
  } else {
    str = s21_NULL;
  }
  return str;
}
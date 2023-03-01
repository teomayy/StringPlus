#include "s21_string.h"

void *s21_memset(void *str, char c, s21_size_t n) {
  char *temp = str;
  char symb = c;
  for (s21_size_t i = 0; i < n; i++) {
    temp[i] = symb;
  }
  str = temp;
  return temp;
}
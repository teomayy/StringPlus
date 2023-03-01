#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t length = 0;
  const char *vs = 0;
  for (; *str1; str1++, length++) {
    for (vs = str2; *vs && *vs != *str1; vs++)
      ;
    if (!*vs) break;
  }
  return length;
}
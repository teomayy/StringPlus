#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *ch1 = str1;
  const unsigned char *ch2 = str2;
  int charCompareStatus = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (*ch1 != *ch2) {
      charCompareStatus = *ch1 - *ch2;
      break;
    }
    ch1++;
    ch2++;
  }
  return charCompareStatus;
}

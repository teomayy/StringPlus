#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int charCompareStatus = 0;
  if (str1 == str2) {
    return charCompareStatus;
  }
  while (n > 0) {
    if (*str1 != *str2) {
      if (*str1 > *str2) {
        charCompareStatus = 1;
      } else {
        charCompareStatus = -1;
      }
      break;
    }
    n--;
    str1++;
    str2++;
  }
  return charCompareStatus;
}

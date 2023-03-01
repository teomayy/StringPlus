#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  int CompareStat = 0;
  while (*str1 == *str2 && (*str1 != '\0' && *str1 != '\0')) {
    str1++;
    str2++;
  }
  if (*str1 == *str2) {
    CompareStat = 0;
  } else if (*str1 > *str2) {
    CompareStat = 1;
  } else {
    CompareStat = -1;
  }
  return CompareStat;
}
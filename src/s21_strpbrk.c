#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  int i, j, position = 0, flag = 0;
  for (i = 0; str1[i] != '\0'; i++) {
    position = i;
  }
  for (i = 0; str2[i] != '\0'; i++) {
    for (j = 0; str1[j] != '\0'; j++) {
      if (str2[i] == str1[j]) {
        if (j <= position) {
          position = j;
          flag = 1;
        }
      }
    }
  }
  if (flag == 1) {
    return (char *)&str1[position];
  } else {
    return s21_NULL;
  }
}

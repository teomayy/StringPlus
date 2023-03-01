#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *stat = s21_NULL;
  int len = 0;
  if (str) {
    len = s21_strlen(str);
    stat = calloc(len + 1, sizeof(char));
    if (stat != s21_NULL) {
      for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          stat[i] = str[i] + 32;
        } else {
          stat[i] = str[i];
        }
      }
    }
  }
  return stat;
}

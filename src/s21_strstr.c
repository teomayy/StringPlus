#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  while (*haystack != '\0') {
    const char *str = haystack;
    const char *pattern = needle;
    while (*haystack != '\0' && *pattern != '\0' && *haystack == *pattern) {
      haystack++;
      pattern++;
    }
    if (*pattern == '\0') {
      return (char *)str;
    }
    haystack = str + 1;
  }
  return s21_NULL;
}

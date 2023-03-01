#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *n = s21_NULL;
  s21_size_t len1 = 0, len2 = 0;
  src == s21_NULL ? (len1 = 0) : (len1 = s21_strlen(src));
  str == s21_NULL ? (len2 = 0) : (len2 = s21_strlen(str));
  s21_size_t n_len;
  n_len = len1 + len2;
  if (start_index <= len1) {
    n = (char *)calloc(len1 + len2 + 1, sizeof(char));
  }
  if (n != s21_NULL) {
    for (s21_size_t i = 0; i < n_len; i++) {
      if (i < start_index) {
        n[i] = src[i];
      } else if (i < len2 + start_index) {
        n[i] = str[i - start_index];
      } else {
        n[i] = src[i - len2];
      }
    }
  }
  return n;
}
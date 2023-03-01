#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_size_t unsigned long long
#define s21_NULL (void *)0

#if defined(__APPLE__) || defined(__MACH__)
#define S21_ERR_SIZE 107
#elif defined(__linux__)
#define S21_ERR_SIZE 133
#else
#define S21_ERR_SIZE 133
#endif

#define FULL_SIZE 512

void *s21_memchr(const void *str, int c, s21_size_t n);
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strspn(const char *str1, const char *str2);
s21_size_t s21_strcspn(const char *str1, const char *str2);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, char c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t nn);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strerror(int errnum);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
int s21_memcmp(const void *str1, const void *s2tr, s21_size_t n);

int s21_sprintf(char *str, const char *format, ...);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);

void *s21_trim(const char *src, const char *trim_chars);
int left_side(const char *src, const char *trim_chars, int last);
int right_side(const char *src, const char *trim_chars, int last);

void *s21_insert(const char *src, const char *str, s21_size_t start_index);

typedef struct {
  int flag_minus;
  int flag_plus;
  int flag_space;
  char specifier;
  int width;
  int final_width;
  int precision;
  char length;
  int elements;
  int len;
  int sign;
} options;

int s21_sprintf(char *str, const char *format, ...);
void search_flags(const char **format, options *option);
void write_flag(va_list input, options *option, char *str);
void specifier_c(va_list input, char *str, options *option);
void specifier_s(va_list input, char *str, options *option);
void specifier_i_d_u(va_list input, char *str, options *option);
void specifier_f(va_list input, char *str, options *option);
void write_int(long int argument, char *str, options *option);
void write_acc(char *str, options *option);
void write_width(char *str, options *option);
void write_space(char *str, options *option);
void write_u(unsigned int argument, char *str);
void specifier_f_write(long double argument, char *str, options *option);
void s21_move_string(char *str);
void positive_precision(long double argument, options *option, char *str);

#endif  // SRC_S21_STRING_H_

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  str[0] = '\0';
  va_list(input);
  va_start(input, format);
  int count = 0;
  char specifiers[8] = "cdifsu%";

  while (*format != '\0') {
    if (*format != '%') {
      *str = *format;
      str++;
      count++;
      format++;
    } else if (*format == '%') {
      char str_copy[2048] = {'\0'};
      options option = {0};
      format++;
      option.precision = -1;
      char *specifier_remember = s21_strpbrk(format, specifiers);
      option.specifier = *specifier_remember;
      search_flags(&format, &option);
      write_flag(input, &option, str_copy);
      if (!option.elements) {
        for (int i = 0; str_copy[i]; i++, str++) {
          count++;
          *str = str_copy[i];
        }
      } else if (option.elements) {
        count += option.elements;
      }
      format++;
    }
  }
  *str = '\0';
  va_end(input);
  return count;
}

void write_flag(va_list input, options *option, char *str) {
  if (option->specifier == 'i' || option->specifier == 'd' ||
      option->specifier == 'u') {
    specifier_i_d_u(input, str, option);
  } else if (option->specifier == 'f') {
    specifier_f(input, str, option);
  } else if (option->specifier == 'c') {
    specifier_c(input, str, option);
  } else if (option->specifier == 's') {
    specifier_s(input, str, option);
  } else if (option->specifier == '%') {
    option->len = 1;
    str[0] = '%';
  }
}

void specifier_c(va_list input, char *str, options *option) {
  char chr = va_arg(input, int);
  if (!option->flag_minus && option->width) {
    for (int i = 0; i < option->width; i++) {
      str[i] = ' ';
      if (i == option->width - 1) {
        str[i] = chr;
      }
    }
  } else if (option->width && option->flag_minus) {
    str[0] = chr;
    for (int i = 1; i < option->width; i++) {
      str[i] = ' ';
    }
  } else {
    str[0] = chr;
  }
  if (chr == '\0') {
    (option->elements)++;
  }
}

void specifier_s(va_list input, char *str, options *option) {
  char str_copy[2048] = {'\0'};
  char *argument = va_arg(input, char *);
  s21_strcpy(str_copy, argument);
  if (option->precision > 0) {
    str_copy[option->precision] = '\0';
  }
  int final_width = option->width - s21_strlen(str_copy);
  option->len = s21_strlen(argument);
  if (option->flag_minus && final_width > 0) {
    s21_strcpy(str, str_copy);
    s21_memset(str + s21_strlen(str), ' ', final_width);
  } else if (final_width > 0 && !option->flag_minus) {
    s21_memset(str, ' ', final_width);
    s21_strcpy(str + final_width, str_copy);
  } else {
    s21_strcpy(str, str_copy);
  }
}

s21_size_t int_len(const long int number) {
  s21_size_t len_i = 0;
  long int count = number;
  if (count < 0) {
    count = -count;
  }
  while (count > 0) {
    count /= 10;
    len_i++;
  }
  return len_i;
}

void specifier_i_d_u(va_list input, char *str, options *option) {
  long long int argument = 0;
  if (option->specifier == 'u') {
    argument = (unsigned long)argument;
    if (option->length == 'h') {
      argument = va_arg(input, unsigned);
    } else if (option->length == 'l') {
      argument = va_arg(input, unsigned long);
    } else {
      argument = va_arg(input, unsigned int);
    }
    write_u(argument, str);
  } else {
    if (option->length == 'h') {
      argument = (short)va_arg(input, int);
    } else if (option->length == 'l') {
      argument = va_arg(input, long long);
    } else {
      argument = va_arg(input, int);
    }
    write_int(argument, str, option);
  }
  write_acc(str, option);
  write_space(str, option);
  write_width(str, option);
}

void write_space(char *str, options *option) {
  char str_copy[2048] = {0};
  int i = 0;
  if (str[0] != '-' && option->flag_plus && option->specifier != 'u') {
    str_copy[0] = '+';
    i = 1;
    s21_strcpy(str_copy + i, str);
    s21_strcpy(str, str_copy);
  } else if (str[0] != '-' && option->flag_space && option->specifier != 'u') {
    str_copy[0] = ' ';
    i = 1;
    s21_strcpy(str_copy + i, str);
    s21_strcpy(str, str_copy);
  }
}

void write_width(char *str, options *option) {
  char str_copy[2048] = {0};
  int length = s21_strlen(str);
  int final_width = option->width - length;
  if (option->width > length) {
    if (!option->flag_minus) {
      s21_memset(str_copy, ' ', final_width);
      s21_strcpy(str_copy + final_width, str);
    } else {
      s21_strcpy(str_copy, str);
      s21_memset(str_copy + s21_strlen(str_copy), ' ', final_width);
    }
    s21_strcpy(str, str_copy);
  }
}

void write_acc(char *str, options *option) {
  char str_copy[2048] = {0};
  int length = s21_strlen(str);
  int i = 0;
  int j = 0;
  if (option->precision >= length) {
    if (str[i] == '-') {
      str_copy[0] = '-';
      i++;
      j++;
      length--;
    }
    for (; i < option->precision - length + j; i++) {
      str_copy[i] = '0';
    }
    for (; str[j]; i++, j++) {
      str_copy[i] = str[j];
    }
    s21_strcpy(str, str_copy);
  }
}

void write_u(unsigned int argument, char *str) {
  char str_copy[2048] = {0};
  char str_copy_2[2048] = {0};
  int len = int_len(argument);
  int j = 0;
  if (argument == 0) {
    str_copy[len] = 48;
  }
  while (argument > 0) {
    str_copy[len - 1] = argument % 10 + 48;
    argument /= 10;
    len--;
  }
  for (int i = 0; str_copy[i]; j++, i++) {
    str_copy_2[j] = str_copy[i];
  }
  for (int i = 0; str_copy_2[i]; i++) {
    str[i] = str_copy_2[i];
  }
}

void write_int(long int argument, char *str, options *option) {
  char str_copy[2048] = {0};
  char str_copy_2[2048] = {0};
  int j = 0;
  if (argument < 0) {
    argument *= -1;
    str_copy_2[0] = '-';
    j = 1;
    option->sign = 1;
  }
  int len = int_len(argument);
  if (argument == 0) {
    str_copy[len] = 48;
  }
  while (argument > 0) {
    str_copy[len - 1] = argument % 10 + 48;
    argument /= 10;
    len--;
  }
  for (int i = 0; str_copy[i]; j++, i++) {
    str_copy_2[j] = str_copy[i];
  }
  s21_strcpy(str, str_copy_2);
}

void specifier_f(va_list input, char *str, options *option) {
  long double argument = va_arg(input, double);
  specifier_f_write(argument, str, option);
  write_space(str, option);
  write_width(str, option);
}

void specifier_f_write(long double argument, char *str, options *option) {
  char str_copy_2[1024] = {0};
  int sign = 0;
  if (argument < 0) {
    argument *= -1;
    sign = 1;
  }

  if (option->precision == 0) {
    long long int left_part = roundl(argument);
    write_int(left_part, str_copy_2, option);
    s21_strcpy(str, str_copy_2);
    if (sign) {
      s21_move_string(str);
    }
  } else if (option->precision == -1 || option->precision > 0) {
    positive_precision(argument, option, str);
    if (sign) s21_move_string(str);
  }
}

void positive_precision(long double argument, options *option, char *str) {
  char right_part[1024] = {0};
  char str_copy_2[1024] = {0};
  char zero[1024] = {0};
  long double left = 0, right = modfl(argument, &left);
  if (option->precision == -1) option->precision = 6;
  long long int left_part = left;
  int i = 0;
  if (left_part != 0) {
    write_int(left_part, str_copy_2, option);
    i += int_len(left_part);
  } else if (left_part == 0) {
    str_copy_2[i] = '0';
    i++;
  }

  s21_strcat(str_copy_2, ".");
  i++;

  int k = 0;
  for (; k < option->precision; k++) {
    right *= 10;
  }
  long long right_int = roundl(right);

  if (right_int != 0) {
    for (int j = 0; j < (int)int_len(right_int); j++) {
      right_part[j] = right_int % 10 + 48;
      left /= 10;
    }
    for (int i = 0; i < k - (int)int_len(right_int); i++) {
      zero[i] = '0';
    }
    for (int m = (int)s21_strlen(right_part) - 1; m > 0 || right_int; m--) {
      right_part[m] = (int)(right_int % 10 + 0.05) + '0';
      right_int /= 10;
    }
  } else if (right_int == 0) {
    for (int j = 0; j < option->precision; j++, i++) {
      str_copy_2[i] = '0';
    }
  }
  s21_strcat(zero, right_part);
  s21_strcat(str_copy_2, zero);
  s21_strcpy(str, str_copy_2);
}

void s21_move_string(char *str) {
  int position = (int)s21_strlen(str);
  str[position + 1] = '\0';
  while (position > 0) {
    str[position] = str[position - 1];
    position--;
  }
  str[position] = '-';
}

void search_flags(const char **format, options *option) {
  int exact = 0;
  while (**format != option->specifier) {
    if (**format == 'l' || **format == 'h') {  // длины
      option->length = **format;
    }
    if (**format == '-') {
      option->flag_minus = 1;
    } else if (**format == '+') {
      option->flag_plus = 1;
    } else if (**format == ' ') {
      option->flag_space = 1;
    }
    if (**format == '.' || exact == 1) {
      if (exact == 0 && !isdigit(*(*format + 1))) {
        option->precision = 0;
      } else {
        if (exact == 0) {
          option->precision = 0;
        }
        if (isdigit(**format)) {
          option->precision *= 10;
          option->precision += **format - '0';
        }
        exact = 1;
      }
    }
    if (exact == 0) {
      if (isdigit(**format)) {
        option->width *= 10;
        option->width += **format - '0';
      }
    }
    (*format)++;
  }
}
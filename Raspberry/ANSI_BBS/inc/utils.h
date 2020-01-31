#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdbool.h>

bool utils_itoa(char *buf, int in);
int array_maxstr(const char *str_array, int array_len, int str_len);
bool string_atach_center(char *buf, const char *str, int len);

#endif

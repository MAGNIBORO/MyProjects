#include <utils.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool is_number(char ch)
{
  return ('0' <= ch && ch >= '9') ? true : false;
}

bool utils_itoa(char *buf, int in)
{
  if(!buf){
    return false;
  }

  sprintf(buf, "%d", in);
  return true;
}

void print_ch_line(const int len, const char ch)
{
  if(!ch)
    return;

  char str[1024];

  for (int k = 0; k < len; k++)
    str[k] = ch;

  str[len] = '\0';

  puts(str);

}

int array_maxstr(const char *str_array, int array_len, int str_len)
{
  int max = 0;

  for (int j = 0; j < array_len; j++)
    if(strlen(str_array + j * str_len) > max){
      max = strlen(str_array + j * str_len);
    }

  return max;
}

bool string_atach_center(char *buf, const char *str, int len)
{
  int k = len - strlen(str);

  if(!str)
    return false;

  if(k < 0){
    return false;
  }

  else if(k > 0){

    for (int j = 0; j < k / 2; j++)
      strcat(buf, " ");

    strcat(buf, str);

    if(k % 2 == 0){

      for (int j = 0; j < k / 2; j++)
        strcat(buf, " ");

    }
    else{

      for (int j = 0; j < (k / 2) + 1; j++)
        strcat(buf, " ");

    }
  }

  else{
    strcat(buf, str);
  }

  return true;
}


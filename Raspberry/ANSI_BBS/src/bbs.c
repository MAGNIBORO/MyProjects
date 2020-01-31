#include <bbs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>

static bool colour_parameters_str(char *str, style_t sty, colour_t for_col, colour_t back_col)
{

  if(COLOR_END <= back_col || back_col <= COLOR_INVALID){
    return false;
  }
  if(COLOR_END <= for_col || for_col <= COLOR_INVALID){
    return false;
  }
  if(STYLE_END <= sty || sty <= STYLE_INVALID){
    return false;
  }

  for (int k = STYLE_INVALID + 1; k < STYLE_END; k++){
    if(sty == k){

      char hold[10];
      utils_itoa(hold, k);

      strcat(str, hold);
      strcat(str, ";");
      break;
    }
  }

  for (int k = COLOR_INVALID + 1; k < COLOR_END; k++){
    if(for_col == k){

      char hold[10];
      utils_itoa(hold, 30 + k);

      strcat(str, hold);
      strcat(str, ";");
      break;
    }
  }

  for (int k = COLOR_INVALID + 1; k < COLOR_END; k++){
    if(back_col == k){

      char hold[10];
      utils_itoa(hold, 40 + k);

      strcat(str, hold);
      break;
    }
  }

  return true;

}

bool bbs_str_colour(char *buf, style_t sty, colour_t for_col, colour_t back_col)
{
  char aux_buf[1000];
  strcpy(aux_buf, buf);

  if(COLOR_END <= back_col || back_col <= COLOR_INVALID){
    puts("invalid background color");
    return false;
  }
  if(COLOR_END <= for_col || for_col <= COLOR_INVALID){
    puts("invalid foreground color");
    return false;
  }
  if(STYLE_END <= sty || sty <= STYLE_INVALID){
    puts("invalid style");
    return false;
  }
//  if(8 + strlen(buf) * sizeof(char) + 4){
//    puts("buffer length to small");
//    return false;
//  }

//TODO dinamic malloc depending of style and color active

  *buf = '\0';
  strcat(buf, "\033[");

  colour_parameters_str(buf, sty, for_col, back_col);

  strcat(buf, "m");
  strcat(buf, aux_buf);
  strcat(buf, "\033[m");

  return true;
}

void bbs_print_line(const int len, const char *str)
{
  if(!str)
    return;

  char aux[1024], ch;
  strcpy(aux, str);

  ch = aux[strlen(aux) - 4];
  aux[strlen(aux) - 3] = '\0';

  for (int k = 1; k < len; k++)
    strncat(aux, &ch, 1);

  strcat(aux, "\033[m");

  puts(aux);

}

bool bbs_is_string(const char *str)
{
  return (str[0] == '\033' && str[1] == '[') ? true : false;
}

int bbs_string_escape_len(const char *str)
{
  int total_len = strlen(str);
  int ret = 0;
  char ch;

  if(!str)
    return 0;
  if(!bbs_is_string(str))
    return 0;

  for (int k = 0; ch != 'm'; k++){
    ch = str[k];
    ret++;
  }

  if(str[total_len - 3] != '\033'){
    // LOG ERROR TO PARSE BBS STRING
    return 0;
  }

  return ret + 3;
}

bool bbs_string_atach_center(char *buf, const char *str, int len)
{
  return string_atach_center(buf, str, len + bbs_string_escape_len(str));
}

menu_t* bbs_menu_new(const char *str_array, int array_len, int array_str_len, colour_t fore,
                     colour_t back, colour_t edg, style_t sty)
{

  if((!str_array) || (array_len > MAX_MENU_OPTIONS) || (array_str_len > MAX_MENU_OPTION_LEN)){
    return NULL;
  }

  menu_t *ret = malloc(sizeof(menu_t));

// load default styles and colours
  ret->foreground = fore;
  ret->background = back;
  ret->edges = edg;
  ret->style = sty;

  ret->n_options = array_len;
  ret->option_max_len = array_str_len;

  for (int k = 0; k < array_len; k++){
    strcpy(ret->options[k], str_array + k * array_str_len);
  }

  return ret;
}

void bbs_menu_delete(menu_t *menu)
{
  free(menu);
}

bool bbs_is_char(const char *str)
{
  if(str[1] == '\0')
    return false;

  return (strlen(str) - bbs_string_escape_len(str) == 1) ? true : false;
}

void bbs_menu_print_char_line(const menu_t *menu, const char *str)
{

  if(bbs_is_char(str)){
    bbs_print_line(menu->option_max_len + 2, str);
  }
  else{
    print_ch_line(menu->option_max_len + 2, *str);
  }

}

void bbs_menu_show(const menu_t *menu, int x, int y, char *roof, char *walls, char *floor)
{

  if(!menu)
    return;
  if(!roof)
    return;
  if(!walls)
    return;
  if(!floor)
    return;

  char buf[MAX_MENU_OPTION_LEN + 3];

  bbs_menu_print_char_line(menu, roof);

  for (int y = 0; y < menu->n_options; y++){

    strcpy(buf, "");

    strcat(buf, walls);

    if(bbs_is_string(menu->options[y])){
      bbs_string_atach_center(buf, menu->options[y], menu->option_max_len);
    }
    else{
      string_atach_center(buf, menu->options[y], menu->option_max_len);
    }

    strcat(buf, walls);

    printf("%s\n", buf);
  }

  bbs_menu_print_char_line(menu, floor);

}


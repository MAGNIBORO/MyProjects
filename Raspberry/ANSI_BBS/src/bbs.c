#include <bbs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static bool utils_itoa(char *buf, int in)
{
  if(!buf)
    return false;

  sprintf(buf, "%d", in);
  return true;
}

static bool string_atach_spaces(char *buf, int len)
{
  if(len < 0)
    return false;

  for (int j = 0; j < len; j++)
    strcat(buf, " ");

  return true;
}

static bool colour_parameters_str(char *str, style_t sty, colour_t for_col, colour_t back_col)
{

  if(COLOUR_END <= back_col || back_col <= COLOUR_INVALID)
    return false;
  if(COLOUR_END <= for_col || for_col <= COLOUR_INVALID)
    return false;
  if(STYLE_END <= sty || sty <= STYLE_INVALID)
    return false;

  for (int k = STYLE_INVALID + 1; k < STYLE_END; k++){
    if(sty == k){

      char hold[10];
      utils_itoa(hold, k);

      strcat(str, hold);
      strcat(str, ";");
      break;
    }
  }

  for (int k = COLOUR_INVALID + 1; k < COLOUR_END; k++){
    if(for_col == k){

      char hold[10];
      utils_itoa(hold, 30 + k);

      strcat(str, hold);
      strcat(str, ";");
      break;
    }
  }

  for (int k = COLOUR_INVALID + 1; k < COLOUR_END; k++){
    if(back_col == k){

      char hold[10];
      utils_itoa(hold, 40 + k);

      strcat(str, hold);
      break;
    }
  }

  return true;

}

bool bbs_is_string(const char *str)
{
  return (str[0] == '\033' && str[1] == '[') ? true : false;
}

int bbs_strlen(const char *str)
{
  int total_len = strlen(str);
  int ret = 0;
  char ch = '\0';

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

bool bbs_str_colour(char *buf, style_t sty, colour_t for_col, colour_t back_col)
{
  char aux_buf[1000];
  strcpy(aux_buf, buf);

  if(COLOUR_END <= back_col || back_col <= COLOUR_INVALID){
//    puts("invalid background color");
    return false;
  }
  if(COLOUR_END <= for_col || for_col <= COLOUR_INVALID){
//    puts("invalid foreground color");
    return false;
  }
  if(STYLE_END <= sty || sty <= STYLE_INVALID){
//    puts("invalid style");
    return false;
  }

//TODO dinamic malloc depending of style and color active

  *buf = '\0';
  strcat(buf, "\033[");

  colour_parameters_str(buf, sty, for_col, back_col);

  strcat(buf, "m");
  strcat(buf, aux_buf);
  strcat(buf, "\033[m");

  return true;
}

static void bbs_print_line(const int len, const char *str)
{
  if(!str)
    return;
  if(strlen(str) - bbs_strlen(str) != 1)
    return;

  char aux[MAX_SCREEN_HORIZONTAL_SIZE], ch;
  strcpy(aux, str);

  ch = aux[strlen(aux) - 4];
  aux[strlen(aux) - 3] = '\0';

  for (int k = 1; k < len; k++)
    strncat(aux, &ch, 1);

  strcat(aux, "\033[m");

  puts(aux);

}

static void bbs_char_load(char *dst, const char *src, style_t sty, colour_t for_col, colour_t back_col)
{
  if(bbs_is_char(src)){
    strcpy(dst, src);
  }
  else{
    strcpy(dst, "");
    strncat(dst, src, 1);
    bbs_str_colour(dst, sty, for_col, back_col);
  }
}
bbs_menu_t* bbs_menu_new(const char *str_array, int array_len, int array_str_len, bbs_menu_colour_t colors, bbs_menu_edges_t edges)
{

  if(!str_array)
    return NULL;
  if(array_len > MAX_MENU_OPTIONS)
    return NULL;
  if(array_str_len > MAX_MENU_OPTION_LEN)
    return NULL;

  bbs_menu_t *ret = malloc(sizeof(bbs_menu_t));

  ret->child=NULL;
  ret->prev=NULL;
  ret->next=NULL;
// load default styles and colours
  ret->colors.foreground = colors.foreground;
  ret->colors.background = colors.background;
  ret->colors.edges_background = colors.edges_background;
  ret->colors.edges_foreground = colors.edges_foreground;
  ret->colors.style = colors.style;

  bbs_char_load(ret->edges.roof, edges.roof, colors.style, colors.edges_foreground, colors.edges_background);
  bbs_char_load(ret->edges.walls, edges.walls, colors.style, colors.edges_foreground, colors.edges_background);
  bbs_char_load(ret->edges.floor, edges.floor, colors.style, colors.edges_foreground, colors.edges_background);


  ret->n_options = array_len;
  ret->option_max_len = array_str_len;

  for (int k = 0; k < array_len; k++){
    strcpy(ret->options[k], str_array + k * array_str_len);
  }

  return ret;
}

void bbs_menu_delete(bbs_menu_t *menu)
{
  bbs_menu_t *next = NULL;

  while (menu != NULL){
    next = menu->next;

    if (menu->child)
      bbs_menu_delete(menu->child);

    free(&menu->colors);
    free(&menu->edges);
    free(&menu->options);
    free(&menu->n_options);
    free(&menu->option_max_len);
    free(&menu->prev);

    menu = next;

  }

}

bool bbs_add_menu_to_menu(bbs_menu_t *father,bbs_menu_t *child){

  if(!father)
    return false;
  if(!child)
    return false;

  bbs_menu_t *last_child = father->child;

  if(last_child != NULL){

    while (last_child->next != NULL){
      last_child = last_child->next;
    }

    child->prev = last_child;
    child->next = NULL;
    last_child->next = child;
  }
  else{
    child->prev = NULL;
    child->next = NULL;
    father->child = child;
  }

  return true;
}

bool bbs_is_char(const char *str)
{
  if(str[1] == '\0')
    return false;

  return ((strlen(str) - bbs_strlen(str)) == 1) ? true : false;
}

static void bbs_menu_print_char_line(const bbs_menu_t *menu, const char *str)
{
    bbs_print_line(menu->option_max_len + 2, str);
}

static void bbs_menu_atach_char(const bbs_menu_t *menu, char *buf, const char *str)
{

  if(bbs_is_char(str)){
    strcat(buf, str);
  }
  else{
    char aux[20]="";
    strncat(aux, str, 1);

    bbs_str_colour(aux, menu->colors.style, menu->colors.edges_foreground, menu->colors.edges_background);
    strcat(buf, aux);
  }

}

static void bbs_menu_atach_string_center(const bbs_menu_t *menu, char *buf, const char *str, int len)
{
  if(!menu)
    return;
  if(!buf)
    return;
  if(!str)
    return;
  if(!len)
    return;

  int space_to_fill = len - strlen(str) + bbs_strlen(str);
  char aux_buf[MAX_SCREEN_HORIZONTAL_SIZE - 2] = "";
  char back_str_begin[20] = "";

  bbs_str_colour(back_str_begin, menu->colors.style, menu->colors.foreground, menu->colors.background);
  back_str_begin[strlen(back_str_begin) - 3] = '\0';
  strcat(aux_buf, back_str_begin);

  string_atach_spaces(aux_buf, space_to_fill / 2);
  strcat(aux_buf, "\033[m");

  if(bbs_is_string(str)){
    strcat(aux_buf, str);
  }
  else{
    char aux_str[MAX_SCREEN_HORIZONTAL_SIZE];
    strcpy(aux_str, str);
    bbs_str_colour(aux_str, menu->colors.style, menu->colors.foreground, menu->colors.background);
    strcat(aux_buf, aux_str);
  }

  strcat(aux_buf, back_str_begin);

  if(space_to_fill % 2 == 0)
    string_atach_spaces(aux_buf, space_to_fill / 2);
  else
    string_atach_spaces(aux_buf, space_to_fill / 2 + 1);

  strcat(aux_buf, "\033[m");

  strcat(buf, aux_buf);
}

void bbs_menu_show(const bbs_menu_t *menu)
{

  if(!menu)
    return;

  char buf[MAX_SCREEN_HORIZONTAL_SIZE];

  bbs_menu_print_char_line(menu, menu->edges.roof);

  for (int y = 0; y < menu->n_options; y++){

    strcpy(buf, "");

    bbs_menu_atach_char(menu, buf, menu->edges.walls);
    bbs_menu_atach_string_center(menu, buf, menu->options[y], menu->option_max_len);
    bbs_menu_atach_char(menu, buf, menu->edges.walls);

    printf("%s\n", buf);
  }

  bbs_menu_print_char_line(menu, menu->edges.floor);

}

void bbs_screen_clear()
{
  puts("\033[2J");
}

void bbs_get_screen_size(int *x, int *y)
{
  win_get_screen_size(x, y);
}

void bbs_start(const bbs_menu_t *menu)
{

  for (;;){

    int x_len, y_len;

    bbs_get_screen_size(&x_len, &y_len);
    //   bbs_menu_show_center(menu);

  }
}





















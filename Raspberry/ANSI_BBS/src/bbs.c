#include <bbs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#ifdef WIN32
#include <windows.h>

void get_screen_size(int *x, int *y)
{

  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  *x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
  *y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

}

void msleep(int a){
  Sleep(a);
}

bool key_is_pressed(){
  return kbhit();
}

#endif

bool bbs_window_is_resized(int x, int y){
  int aux_x,aux_y;

  bbs_screen_get_size(&aux_x,&aux_y);

  if( (x!=aux_x) || (y!=aux_y) )
    return true;

  return false;
}

static bool bbs_itoa(char *buf, int in)
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
      bbs_itoa(hold, k);

      strcat(str, hold);
      strcat(str, ";");
      break;
    }
  }

  for (int k = COLOUR_INVALID + 1; k < COLOUR_END; k++){
    if(for_col == k){

      char hold[10];
      bbs_itoa(hold, 30 + k);

      strcat(str, hold);
      strcat(str, ";");
      break;
    }
  }

  for (int k = COLOUR_INVALID + 1; k < COLOUR_END; k++){
    if(back_col == k){

      char hold[10];
      bbs_itoa(hold, 40 + k);

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

int bbs_esclen(const char *str)
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

int bbs_strlen(const char *str){
  return strlen(str) - bbs_esclen(str);
}

bool bbs_str_colour(char *buf, style_t sty, colour_t for_col, colour_t back_col)
{
  char aux_buf[MAX_MENU_OPTION_LEN];
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
  if(bbs_strlen(str) != 1)
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

bool bbs_option_menu_new(bbs_menu_option_t ret[], char *str_array,int str_len ,void (*callbacks_array)(void),bool *is_prompt_array, int options_qty)
{
  if(!str_array)
    return false;
  if(!callbacks_array)
    return false;
  if(!is_prompt_array)
    return false;
  if(!options_qty)
    return false;

  for(int k=0; k<options_qty; k++){

    ret[k].name = (str_array + str_len * k);
    ret[k].callback = *(callbacks_array + k*sizeof( void(*)(void) ) );
    ret[k].is_prompt = *(is_prompt_array + k*sizeof(bool));
    ret[k].associated_menu = UNKNOW_MENU;
    ret[k].value_string = NULL;
  }

  return true;
}

static int option_array_max_strlen(bbs_menu_option_t option_array[], int options_qty){

  int ret=0;

  for(int k=0; k<options_qty; k++){

    if( bbs_strlen(option_array[k].name) > ret){
      ret = bbs_strlen(option_array[k].name);
    }
  }

  return ret;
}

bbs_menu_t* bbs_menu_new(bbs_menu_option_t option_array[] ,int options_qty, bbs_menu_colour_t colors, bbs_menu_edges_t edges)
{

  if(!option_array)
    return NULL;
  if(options_qty > MAX_MENU_OPTIONS)
    return NULL;

  bbs_menu_t *ret = malloc(sizeof(bbs_menu_t));


  ret->child=NULL;
  ret->prev=NULL;
  ret->next=NULL;
  ret->father=NULL;


  ret->n_options = options_qty;
  ret->option_max_len = option_array_max_strlen(option_array, options_qty);


  memcpy(&ret->option, option_array, options_qty*sizeof(bbs_menu_option_t));
  free(option_array);

// load default styles and colours
  ret->format.edges.x_margin = edges.x_margin;
  ret->format.edges.y_margin = edges.y_margin;

  ret->format.colors.foreground = colors.foreground;
  ret->format.colors.background = colors.background;
  ret->format.colors.edges_background = colors.edges_background;
  ret->format.colors.edges_foreground = colors.edges_foreground;
  ret->format.colors.style = colors.style;

  bbs_char_load(ret->format.edges.roof, edges.roof, colors.style, colors.edges_foreground, colors.edges_background);
  bbs_char_load(ret->format.edges.walls, edges.walls, colors.style, colors.edges_foreground, colors.edges_background);
  bbs_char_load(ret->format.edges.floor, edges.floor, colors.style, colors.edges_foreground, colors.edges_background);


  return ret;
}

bbs_menu_t* bbs_menu_container(){
  return malloc(sizeof(bbs_menu_t));
}

void bbs_menu_delete(bbs_menu_t *menu)
{
  bbs_menu_t *next = NULL;

  while (menu != NULL){
    next = menu->next;

    if (menu->child)
      bbs_menu_delete(menu->child);

    free(&menu->format);
    free(&menu->option);
    free(&menu->n_options);
    free(&menu->option_max_len);
    free(&menu->prev);
    free(&menu->next);
    free(&menu->father);
    free(&menu->child);
    free(menu);

    menu = next;

  }

}

bool bbs_add_menu_to_menu(bbs_menu_t *father,bbs_menu_t *child, int assosiated_option){

  if(!father)
    return false;
  if(!child)
    return false;

  bbs_menu_t *last_child = father->child;
  int n_menu = 0;

  if(last_child != NULL){

    while (last_child->next != NULL){
      n_menu++;
      last_child = last_child->next;
    }

    n_menu++;
    child->prev = last_child;
    last_child->next = child;
  }
  else{
    child->prev = NULL;
    father->child = child;
  }

  child->next = NULL;
  child->father = father;

  if(assosiated_option != UNKNOW_OPTION)
    father->option[assosiated_option].associated_menu = n_menu;

  return true;
}

bool bbs_is_char(const char *str)
{
  if(str[1] == '\0')
    return false;

  return (bbs_strlen(str) == 1) ? true : false;
}

static void bbs_menu_print_char_line(const bbs_menu_t *menu, const char *str)
{
    bbs_print_line( 1 + menu->format.edges.x_margin + menu->option_max_len + menu->format.edges.x_margin + 1, str);
}

static void bbs_menu_atach_char(char *buf, const bbs_menu_t *menu, const char *str)
{

  if(bbs_is_char(str)){
    strcat(buf, str);
  }
  else{
    char aux[MAX_ESCAPE_GRAPH_LEN]="";
    strncat(aux, str, 1);

    bbs_str_colour(aux, menu->format.colors.style, menu->format.colors.edges_foreground, menu->format.colors.edges_background);
    strcat(buf, aux);
  }

}

static void bbs_menu_atach_string_center(char *buf, const bbs_menu_t *menu, const char *str, int len)
{
  if(!menu)
    return;
  if(!buf)
    return;
  if(!str)
    return;
  if(!len)
    return;

  int space_to_fill = len - bbs_strlen(str);
  char aux_buf[MAX_SCREEN_HORIZONTAL_SIZE - 2] = "";
  char back_str_begin[MAX_ESCAPE_GRAPH_LEN] = "";

  bbs_str_colour(back_str_begin, menu->format.colors.style, menu->format.colors.foreground, menu->format.colors.background);
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
    bbs_str_colour(aux_str, menu->format.colors.style, menu->format.colors.foreground, menu->format.colors.background);
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

void bbs_cursor_move(int x, int y){
  printf("\033[%d;%dH",y,x);
}

void bbs_screen_clear()
{
  puts("\033[2J");
}

void bbs_screen_get_size(int *x, int *y)
{
  get_screen_size(x, y);
}

void bbs_menu_show(const bbs_menu_t *menu)
{
  bbs_menu_show_at(menu,0,0);
}

void bbs_menu_show_center(const bbs_menu_t *menu){

  if(!menu)
    return;

  int x_scr_len=0, y_scr_len=0;

  bbs_screen_get_size(&x_scr_len, &y_scr_len);

  bbs_menu_show_at(menu, (x_scr_len - menu->option_max_len - 2)/2, (y_scr_len - menu->n_options - 2)/2 );

}

static void bbs_menu_print_row(const bbs_menu_t *menu, char *str, int x_pos, int y_pos){

  if(!menu)
    return;
  if(!str)
    return;
  if(!x_pos)
    return;
  if(!y_pos)
    return;

  char buf[MAX_SCREEN_HORIZONTAL_SIZE] = "";

  bbs_menu_atach_char(buf, menu, menu->format.edges.walls);
  bbs_menu_atach_string_center(buf, menu, str, menu->option_max_len + 2*menu->format.edges.x_margin);
  bbs_menu_atach_char(buf, menu, menu->format.edges.walls);

  bbs_cursor_move(x_pos, y_pos);
  printf("%s\n", buf);
}

void bbs_menu_show_at(const bbs_menu_t *menu, int x_pos, int y_pos){

  if(!menu)
    return;
  if(!x_pos)
    return;
  if(!y_pos)
    return;

  int row = y_pos;

  bbs_cursor_move(x_pos, row);
  bbs_menu_print_char_line(menu, menu->format.edges.roof);

  for(int y=0; y<menu->format.edges.y_margin; y++){
    row++;
    bbs_menu_print_row(menu,"",x_pos,row);
  }

  for (int y = 0; y < menu->n_options; y++){
    row++;
    bbs_menu_print_row(menu,menu->option[y].name,x_pos,row);
  }

  for(int y=0; y<menu->format.edges.y_margin; y++){
    row++;
    bbs_menu_print_row(menu,"",x_pos,row);
  }

  row++;
  bbs_cursor_move(x_pos, row);
  bbs_menu_print_char_line(menu, menu->format.edges.floor);
}

static bbs_menu_t* bbs_get_child_menu_from_index(const bbs_menu_t *menu, int index){

  if(!menu)
    return NULL;
  if(!menu->child)
    return NULL;

  bbs_menu_t *ret = menu->child;

  for(int k=0; k<index; k++){
    ret = ret->next;
  }

  return ret;
}

static bool bbs_exec_key(bbs_menu_t *menu, int *actual_line,  int *previous_line){

  bool ret = true;
  char ch = getch();

  switch(ch){

    case 'w':
     *previous_line = *actual_line;
     *actual_line = (*actual_line == 0) ? menu->n_options - 1 : *actual_line - 1;
    break;

    case 's':
      *previous_line = *actual_line;
      *actual_line = (*actual_line == (menu->n_options - 1)) ? 0 : *actual_line + 1;
    break;

    case '\r':
      if(menu->option[*actual_line].associated_menu != UNKNOW_MENU){
        bbs_menucpy(menu, bbs_get_child_menu_from_index(menu, menu->option[*actual_line].associated_menu));
        *actual_line = 0;
        *previous_line = 0;
      }
    break;

    case '\033':
      if(menu->father != NULL){
        bbs_menucpy(menu, menu->father);
        *actual_line = 0;
        *previous_line = 0;
      }
      break;
      
    default:
      ret = false;
  }

  return ret;
}

void *bbs_menucpy(bbs_menu_t *to, const bbs_menu_t *from){
  return memcpy(to,from,sizeof(bbs_menu_t));
}

void bbs_menu_exec_line_change(bbs_menu_t *actual_menu,char *actual_line_str,char *buf ,int actual_sel_line){

  strcpy(buf, actual_line_str);
  bbs_str_colour(buf, actual_menu->format.colors.style, actual_menu->format.colors.background, actual_menu->format.colors.foreground);
  actual_menu->option[actual_sel_line].name = buf;

  bbs_screen_clear();
  bbs_menu_show_center(actual_menu);

}

void bbs_start(const bbs_menu_t *menu)
{
  bbs_menu_t *actual_menu;
  int actual_sel_line = 0;
  int window_x_len = 0,window_y_len = 0;

  actual_menu = bbs_menu_container();
  bbs_menucpy(actual_menu, menu);

  char buf[MAX_MENU_OPTION_LEN];
  char *actual_line_str = actual_menu->option[actual_sel_line].name;


  bbs_menu_exec_line_change(actual_menu,actual_line_str,buf ,actual_sel_line);

  for (;;){

    if(key_is_pressed()){
      switch(getch()){

        case 'w':
          actual_menu->option[actual_sel_line].name = actual_line_str;
          actual_sel_line = (actual_sel_line == 0) ? actual_menu->n_options - 1 : actual_sel_line - 1;
          actual_line_str = actual_menu->option[actual_sel_line].name;
          bbs_menu_exec_line_change(actual_menu,actual_line_str,buf ,actual_sel_line);
        break;


        case 's':
          actual_menu->option[actual_sel_line].name = actual_line_str;
          actual_sel_line = (actual_sel_line == (actual_menu->n_options - 1)) ? 0 : actual_sel_line + 1;
          actual_line_str = actual_menu->option[actual_sel_line].name;
          bbs_menu_exec_line_change(actual_menu,actual_line_str,buf ,actual_sel_line);
        break;

        case '\r':
          if(actual_menu->option[actual_sel_line].associated_menu != UNKNOW_MENU){
            bbs_menucpy(actual_menu, bbs_get_child_menu_from_index(actual_menu, actual_menu->option[actual_sel_line].associated_menu));
            actual_sel_line = 0;
            actual_line_str = actual_menu->option[actual_sel_line].name;
            bbs_menu_exec_line_change(actual_menu,actual_line_str,buf ,actual_sel_line);
          }
        break;

        case '\033':
          if(actual_menu->father != NULL){
            bbs_menucpy(actual_menu, actual_menu->father);
            actual_sel_line = 0;
            actual_line_str = actual_menu->option[actual_sel_line].name;
            bbs_menu_exec_line_change(actual_menu,actual_line_str,buf ,actual_sel_line);
          }
        break;

      default:
        ;
      }
    }

//    msleep(10);
//    bbs_screen_get_size(&window_x_len,&window_y_len);
//
//    if( bbs_window_is_resized(window_x_len,window_y_len) ){
//      bbs_screen_clear();
//      bbs_menu_show_center(actual_menu);
//    }

  }

  bbs_menu_delete(actual_menu);
}


















#include <stdlib.h>
#include <stdbool.h>
#include <bbs.h>

bbs_menu_colour_t aformat = {.background = COLOUR_BLACK,.foreground = COLOUR_RED,.edges_background = COLOUR_BLACK,.edges_foreground = COLOUR_GREEN,
    .style = STYLE_DISABLED };

bbs_menu_edges_t aedge = { .roof = "~", .walls = "|", .floor = "~", .x_margin = 3, .y_margin = 1};

bbs_menu_colour_t bformat = {.background = COLOUR_RED,.foreground = COLOUR_YELLOW,.edges_background = COLOUR_BLACK,.edges_foreground = COLOUR_GREEN,
    .style = STYLE_ITALIC };

bbs_menu_edges_t bedge = { .roof = "_", .walls = "|", .floor = "_", .x_margin = 4, .y_margin = 2};

bbs_menu_colour_t cformat = {.background = COLOUR_WHITE,.foreground = COLOUR_BLACK,.edges_background = COLOUR_WHITE,.edges_foreground = COLOUR_BLACK,
    .style = STYLE_BOLD };

bbs_menu_edges_t cedge = { .roof = "-", .walls = "|", .floor = "-", .x_margin = 5, .y_margin = 3};

//int pepe=0;
//
//void mas(){
//  pepe++;
//}

void main()
{

  char abuf[5][40] = { "hola", "AHHHHHHHH", "1234", "mi dios me vio y se inibio", "nul" };
  void (*aptr[5])(void) = {NULL,NULL,NULL,NULL,NULL};
  bool a_arr[5] = {false,false,false,false,false};
  char bbuf[2][40] = { "menub", "xd"};
  void (*bptr[2])(void) = {NULL,NULL,NULL,NULL,NULL};
  bool b_arr[2] = {false,false};
  char cbuf[10][40] = { "hola", "AHHHHHHHH", "1234", "mi dios me vio y se inibio", "nul" ,"hola", "AHHHHHHHH", "1234", "mi dios me vio y se inibio", "nul"};
  void (*cptr[10])(void) = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
  bool c_arr[10] = {false,false,false,false,false,false,false,false,false,false};

  bbs_menu_option_t ap[5];
  bbs_menu_option_t bp[2];
  bbs_menu_option_t cp[10];


//  bbs_str_colour(buf[0], STYLE_BOLD, COLOUR_RED, COLOUR_BLACK);
//  bbs_str_colour(buf[3], STYLE_BOLD, COLOUR_BLUE, COLOUR_WHITE);
//  bbs_str_colour(edge.roof, STYLE_ITALIC, COLOUR_BLUE, COLOUR_CYAN);
//  bbs_str_colour(edge.walls, STYLE_BOLD, COLOUR_RED, COLOUR_GREEN);

  bbs_option_menu_new(ap,abuf,40,aptr,a_arr,5);
  bbs_menu_t *a = bbs_menu_new(ap, 5, aformat, aedge);

  bbs_option_menu_new(bp,bbuf,40,bptr,b_arr,2);
  bbs_menu_t *b = bbs_menu_new(bp, 2, bformat, bedge);

  bbs_option_menu_new(cp,cbuf,40,cptr,c_arr,10);
  bbs_menu_t *c = bbs_menu_new(cp, 10, cformat, cedge);

  bbs_add_menu_to_menu(a, b, 0);
  bbs_add_menu_to_menu(a, c, 2);

  bbs_screen_clear();
  bbs_start(a);


}


#include <bbs.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <utils.h>

void main()
{

  char buf[5][40] = { "hola", "AHHHHHHHH", "1234", "mi dios me dio y se inibio", "null" };

  bbs_str_colour(buf[0], STYLE_BOLD, COLOR_RED, COLOR_BLACK);
  bbs_str_colour(buf[3], STYLE_BOLD, COLOR_BLUE, COLOR_WHITE);

  menu_t *a = bbs_menu_new(buf, 5, 40, COLOR_RED, COLOR_BLACK, COLOR_BLUE, STYLE_ITALIC);

  char ch1[20] = { "*" };
  char ch2[20] = { "*" };
  char ch3[20] = { "*" };

  bbs_str_colour(ch1, STYLE_ITALIC, COLOR_BLUE, COLOR_CYAN);
  bbs_str_colour(ch2, STYLE_BOLD, COLOR_RED, COLOR_BLACK);
  bbs_str_colour(ch3, STYLE_REVERSE, COLOR_RED, COLOR_BLACK);

  bbs_menu_show(a, 0, 0, ch1, ch2, ch3);
  // printf("%d",fs_array_maxstr(a,3,20));

}


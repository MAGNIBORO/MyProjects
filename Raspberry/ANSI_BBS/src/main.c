#include <bbs.h>

void main()
{

  char buf[5][40] = { "hola", "AHHHHHHHH", "1234", "mi dios me vio y se inibio", "nul" };

  bbs_str_colour(buf[0], STYLE_BOLD, COLOUR_RED, COLOUR_BLACK);
  bbs_str_colour(buf[3], STYLE_BOLD, COLOUR_BLUE, COLOUR_WHITE);

  bbs_menu_colour_t format =
  { .background = COLOUR_BLACK,
    .foreground = COLOUR_GREEN,
    .edges_background = COLOUR_PURPLE,
    .edges_foreground = COLOUR_CYAN,
    .style = STYLE_BOLD };

  bbs_menu_t *a = bbs_menu_new(buf, 5, 40, format);

  char ch1[20] = { "*" };
  char ch2[20] = { "*" };
  char ch3= '*';

  bbs_str_colour(ch1, STYLE_ITALIC, COLOUR_BLUE, COLOUR_CYAN);
  bbs_str_colour(ch2, STYLE_BOLD, COLOUR_RED, COLOUR_BLACK);
//  bbs_str_colour(ch3, STYLE_REVERSE, COLOUR_RED, COLOUR_BLACK);

  bbs_menu_show(a, 0, 0, ch1, ch2, &ch3);

}


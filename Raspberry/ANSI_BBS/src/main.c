#include <bbs.h>

bbs_menu_colour_t format = {
    .background = COLOUR_BLACK,
    .foreground = COLOUR_RED,
    .edges_background = COLOUR_BLACK,
    .edges_foreground = COLOUR_GREEN,
    .style = STYLE_DISABLED };

bbs_menu_edges_t edge = { .roof = "~", .walls = "|", .floor = "~"};

void main()
{

  char buf[5][40] = { "hola", "AHHHHHHHH", "1234", "mi dios me vio y se inibio", "nul" };

  bbs_menu_t *a = bbs_menu_new(buf, 5, 40, format, edge);

//  bbs_str_colour(buf[0], STYLE_BOLD, COLOUR_RED, COLOUR_BLACK);
//  bbs_str_colour(buf[3], STYLE_BOLD, COLOUR_BLUE, COLOUR_WHITE);
//  bbs_str_colour(edge.roof, STYLE_ITALIC, COLOUR_BLUE, COLOUR_CYAN);
//  bbs_str_colour(edge.walls, STYLE_BOLD, COLOUR_RED, COLOUR_BLACK);

  bbs_menu_t *b = bbs_menu_new(buf, 5, 40, format, edge);
  bbs_menu_t *c = bbs_menu_new(buf, 5, 40, format, edge);
  bbs_add_menu_to_menu(b, c);
  bbs_add_menu_to_menu(a, b);

  bbs_screen_clear();
  bbs_menu_show_center((b->child));


}


#include <bbs.h>

bbs_menu_colour_t format = { .background = COLOUR_RED, .foreground = COLOUR_GREEN, .edges_background = COLOUR_PURPLE, .edges_foreground = COLOUR_CYAN,
    .style = STYLE_BOLD };

bbs_menu_edges_t edge = { .roof = "_", .walls = "|", .floor = "_"
};
bbs_menu_edges_t edgea = { .roof = "*", .walls = "*", .floor = "_" };

void main()
{

  char buf[5][40] = { "hola", "AHHHHHHHH", "1234", "mi dios me vio y se inibio", "nul" };

  bbs_menu_t *a = bbs_menu_new(buf, 5, 40, format, edge);

  bbs_str_colour(buf[0], STYLE_BOLD, COLOUR_RED, COLOUR_BLACK);
  bbs_str_colour(buf[3], STYLE_BOLD, COLOUR_BLUE, COLOUR_WHITE);
  bbs_str_colour(edge.roof, STYLE_ITALIC, COLOUR_BLUE, COLOUR_CYAN);
//  bbs_str_colour(edge.walls, STYLE_BOLD, COLOUR_RED, COLOUR_BLACK);

  bbs_menu_t *b = bbs_menu_new(buf, 5, 40, format, edge);
  bbs_menu_t *c = bbs_menu_new(buf, 5, 40, format, edgea);
  bbs_add_menu_to_menu(b, c);
  bbs_add_menu_to_menu(a, b);

  bbs_menu_show((b->child));

}


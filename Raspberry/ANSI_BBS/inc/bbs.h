#ifndef _BBS_H_
#define _BBS_H_

#include <stdbool.h>

#define MAX_SCREEN_HORIZONTAL_SIZE 200
#define MAX_SCREEN_VERTICAL_SIZE 60

#define MAX_MENU_OPTIONS (MAX_SCREEN_HORIZONTAL_SIZE+1)
#define MAX_MENU_OPTION_LEN (MAX_SCREEN_VERTICAL_SIZE+1)

typedef enum
{
  COLOUR_INVALID = -1,
  COLOUR_BLACK,
  COLOUR_RED,
  COLOUR_GREEN,
  COLOUR_YELLOW,
  COLOUR_BLUE,
  COLOUR_PURPLE,
  COLOUR_CYAN,
  COLOUR_WHITE,
  COLOUR_END
} colour_t;

typedef enum
{
  STYLE_INVALID = -1,
  STYLE_DISABLED,
  STYLE_BOLD,
  STYLE_GREY,
  STYLE_ITALIC,
  STYLE_UNDERSCORE,
  STYLE_BLINK,
  STYLE_UNUSED,
  STYLE_REVERSE,
  STYLE_CONCEALED,
  STYLE_END,
} style_t;

typedef struct
{
  colour_t background;
  colour_t foreground;
  colour_t edges_background;
  colour_t edges_foreground;
  style_t style;
} bbs_menu_colour_t;

typedef struct
{
  bbs_menu_colour_t colors;
  char options[MAX_MENU_OPTIONS][MAX_MENU_OPTION_LEN];
  int n_options;
  int option_max_len;
} bbs_menu_t;

bool bbs_is_char(const char *str);
bool bbs_is_string(const char *str);

int bbs_string_escape_len(const char *str);
bool bbs_str_colour(char *buf, style_t sty, colour_t for_col, colour_t back_col);

bbs_menu_t* bbs_menu_new(const char *str_array, int array_len, int array_str_len, bbs_menu_colour_t colors);
void bbs_menu_delete(bbs_menu_t *menu);
void bbs_menu_show(const bbs_menu_t *menu, int x, int y,const char *roof, const char *walls, const char *floor);
void bbs_screen_clear();

void bbs_start();

#endif

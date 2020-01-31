#ifndef _BBS_H_
#define _BBS_H_

#include <stdbool.h>

#define MAX_SCREEN_HORIZONTAL_SIZE 1360
#define MAX_SCREEN_VERTICAL_SIZE 768

#define MAX_MENU_OPTIONS 10
#define MAX_MENU_OPTION_LEN 500

typedef enum
{
  COLOR_INVALID = -1,
  COLOR_BLACK,
  COLOR_RED,
  COLOR_GREEN,
  COLOR_YELLOW,
  COLOR_BLUE,
  COLOR_PURPLE,
  COLOR_CYAN,
  COLOR_WHITE,
  COLOR_END,
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
  colour_t foreground;
  colour_t background;
  colour_t edges;
  style_t style;
  char options[MAX_MENU_OPTIONS][MAX_MENU_OPTION_LEN];
  int n_options;
  int option_max_len;
} menu_t;

bool bbs_str_colour(char *buf, style_t sty, colour_t for_col, colour_t back_col);

#endif

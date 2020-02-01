#include <windows.h>

void get_scree_size(int *x, int *y)
{

  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  *x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
  *y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

}

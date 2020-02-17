#include <stdlib.h>
#include <stdbool.h>
#include <bbs.h>


bbs_menu_colour_t format = {.background = COLOUR_WHITE,
    .foreground = COLOUR_BLACK,
    .edges_background = COLOUR_WHITE,
    .edges_foreground = COLOUR_BLACK,
    .style = STYLE_BOLD };

bbs_menu_edges_t edge = { .roof = "-", .walls = "|", .floor = "-", .x_margin = 5, .y_margin = 3};

char sum[10];
int x=0,y=0;

void suma(void){
  bbs_itoa(sum,x+y);
}
void resta(void){
  bbs_itoa(sum,x-y);
}
void division(void){
  bbs_itoa(sum,x/y);
}
void multiplicacion(void){
  bbs_itoa(sum,x*y);
}

void asignar_x1(char * x1){
  x = atoi(x1);
}
void asignar_x2(char * x2){
  y = atoi(x2);
}




void main()
{

  char *abuf[3] = { "Ingresar numeros", "Operacion", "Ver resultado"};
  void (*aptr[3])(char*) = {NULL,NULL,NULL};
  bool a_arr[3] = {false,false,false};

  char *bbuf[4] = { "Numero 1","","Numero 2",""};
  void (*bptr[4])(char*) = {NULL,asignar_x1,NULL,asignar_x2};
  bool b_arr[4] = {false,true,false,true};

  char *cbuf[4] = { "Sumar", "Restar", "Dividir", "Multiplicar"};

  void (*cptr[4])(char*);
  cptr[0] = (void(*)(char*))suma;
  cptr[1] = (void(*)(char*))resta;
  cptr[2] = (void(*)(char*))division;
  cptr[3] = (void(*)(char*))multiplicacion;

  bool c_arr[4] = {false,false,false,false};

  char *dbuf[2] = { "Resultado", sum};
  void (*dptr[2])(char*) = {NULL,NULL};
  bool d_arr[2] = {false,false};

  bbs_menu_option_t ap[3];
  bbs_menu_option_t bp[4];
  bbs_menu_option_t cp[4];
  bbs_menu_option_t dp[2];

  bbs_option_menu_new(ap,abuf,aptr,a_arr,3);
  bbs_menu_t *a = bbs_menu_new(ap, 3, format, edge);

  bbs_option_menu_new(bp,bbuf,bptr,b_arr,4);
  bbs_menu_t *b = bbs_menu_new(bp, 4, format, edge);

  bbs_option_menu_new(cp,cbuf,cptr,c_arr,4);
  bbs_menu_t *c = bbs_menu_new(cp, 4, format, edge);

  bbs_option_menu_new(dp,dbuf,dptr,d_arr,2);
  bbs_menu_t *d = bbs_menu_new(dp, 2, format, edge);

  bbs_add_menu_to_menu(a, b, 0);
  bbs_add_menu_to_menu(a, c, 1);
  bbs_add_menu_to_menu(a, d, 2);

  bbs_screen_clear();
  bbs_start(a);


}


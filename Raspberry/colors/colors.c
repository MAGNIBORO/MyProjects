#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <D:\MIS_COSAS\MyProjects\Raspberry\colors\colors.h>

char *colour_parameters_str(style_t sty, color_t for_col , color_t back_col){

  char *buf;

  if(COLOR_END <=back_col || back_col <= COLOR_INVALID) {
    return NULL;
  }
  if(COLOR_END <=for_col || for_col <= COLOR_INVALID) {
    return NULL;
  }
  if(STYLE_END <=sty || sty <= STYLE_INVALID) {
    return NULL;
  }

  buf= malloc(6*sizeof(char));

  for(int k= STYLE_INVALID +1 ; k < STYLE_END ; k++){
    if(sty == k){
      strcat(buf, itoa(k,NULL,10));
      strcat(buf,";");
      break;
    }
  }

  for(int k= COLOR_INVALID +1 ; k < COLOR_END ; k++){
    if(for_col == k){
      strcat(buf, itoa(30+k,NULL,10));
      strcat(buf,";");
      break;
    }
  }

  for(int k= COLOR_INVALID +1 ; k < COLOR_END ; k++){
    if(back_col == k){
      strcat(buf, itoa(40+k,NULL,10));
      break;
    }
  }

  return buf;

}
//TODO improve style to support combination of styles
char *colour_str(char const *str, style_t sty, color_t for_col , color_t back_col){

  char *buf;

  if(!str){
    puts("invalid string"); 
    return NULL;
  }
  if(COLOR_END <=back_col || back_col <= COLOR_INVALID) {
    puts("invalid background color"); 
    return NULL;
  }
  if(COLOR_END <=for_col || for_col <= COLOR_INVALID) {
    puts("invalid foreground color"); 
    return NULL;
  }
  if(STYLE_END <=sty || sty <= STYLE_INVALID) {
      puts("invalid style"); 
    return NULL;
  }

//TODO dinamic malloc depending of style and color active
  buf = malloc(  8 + strlen(str)*sizeof(char) + 4 );

  strcat(buf,"\033[");
  strcat(buf, colour_parameters_str(sty,for_col,back_col) );
  strcat(buf,"m");
  strcat(buf,str);
  strcat(buf,"\033[m");
  
  return buf;
}

void main(void){

//      printf("\033[%dm %3d\033[m", n, n);

  char *str = "hola";

  printf(str);

  char *col = colour_str(str, STYLE_ITALIC, COLOR_RED, COLOR_WHITE);

  printf(col);
}
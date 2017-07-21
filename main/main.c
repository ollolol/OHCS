/* 
  This is the main file of OHCS
  Made by Hsiaosvideo
  2017/07/21
*/
#include "../include/main.h"
#include "../include/argv.h"
char file = 0;
char R[100];
char *ReadFile = R;
int main(int argc, char* argv[]){
  for(int a = 0;a < argc;a++){
    argvCheck(argv[a]);
  }
  int r = printf("%s\n",ReadFile);
  if(!r){
    printf("%s\n",ReadFile);
    return -1;
  }
  return 0;
}

#include "include/argv.h"
auto char file = 0;
extern char[] ReadFile;
int argvCheck(char[] argv){
  switch (argv[0]){
      case '-':
      argvCharCheck(argv[]);
      default:
      if(file == 1){
        *ReadFile = *argv;
      }
  }
}
int argvCharCheck(char[] argv){
  for(int a = 1;;a++){
    switch (argv[a]){
        case 'f':
        file = 1;
        break;
        
    }
  }
}

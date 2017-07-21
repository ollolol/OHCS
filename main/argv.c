#include "../include/argv.h"
extern char file;
extern char *ReadFile;
int argvCheck(char* argv){
  switch (argv[0]){
      case '-':
      argvCharCheck(argv);
      break;
      default:
      if(file == 1){
        ReadFile = argv;
        file = 0;
      }
  }
  return 0;
}
int argvCharCheck(char* argv){
  int b = 1;
  for(int a = 1;;a++){
    switch (argv[a]){
        case 'f':
        file = 1;
        break;
        case '\0':
        b = 0;
        break;
    }
    if(b){
      break;
    }
  }
  return 0;
}

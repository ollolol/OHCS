/*
This file is part of Ollolol and Hsiaosvideo Cryptography System.

    Ollolol and Hsiaosvideo Cryptography System is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    Ollolol and Hsiaosvideo Cryptography System is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Ollolol and Hsiaosvideo Cryptography System.  If not, see <http://www.gnu.org/licenses/>.
*/
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


/*
    Copyright (C) 2017 CHAW-HUNG, HSIAO
---------------------------------------------------------------------------------------------------------------
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
#include "../include/bigunsigned.h"
unsigned int carry = 0;
void plus(unsigned int* return_value, unsigned int* a, unsigned int* b){
  unsigned int j[127];
  unsigned int d;
  unsigned int f = a[127];
  unsigned int g = b[127];
  unsigned int h = a[127] >= b[127] ? a[127] : b[127];
  for(unsigned int c = 0; c < h; c++){
    j[c] = (f-c-1 >= 0 ? a[f-c-1] : 0) + (g-c-1 >= 0 ? b[g-c-1] : 0);
  }
  return_value[127] = h;
  for(int i = 0; i < h; i++){
    return_value[i] = j[h - i - 1];
  }
  for(int i = h - 1; i > 0; i--){
    return_value[i] += carry;
    carry = 0;
    if(return_value[i] >= 10){
      carry = 1;
      return_value[i] -= (return_value[i] / 10) * 10;    
    }
  }
  if(carry){
    ++return_value[127];
    for(int a = return_value[127]; a>0; --a){
      return_value[a+1] = return_value[a];
    }
    return_value[0] = 1;
  }


}

void printBig(unsigned int* a){
  for(unsigned int b = 0; b < a[127]; b++){
    printf("%u", a[b]);
  }
  printf("\n");
}
void scanBig(char* tmp, unsigned int* a){

  scanf("%s", tmp);
  printf("You enter: ");
  int c = printf("%s\n", tmp);
  --c;
  if(c > 127){
    return;
  }
  for(unsigned int b = 0; b < c; b++){
    a[b] = (unsigned int)tmp[b];
  }

  for(unsigned int b = 0; b < c; b++){
    a[b] -= 48;
  }
  a[127] = c;
}



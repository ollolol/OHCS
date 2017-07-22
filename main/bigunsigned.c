
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
void plus(unsigned int* return_value, unsigned int* a, unsigned int* b){
  unsigned int j[127];
  unsigned int d;
  unsigned int carry = 0;
  unsigned int f = a[127];
  unsigned int g = b[127];
  unsigned int h = a[127] >= b[127] ? a[127] : b[127];
  for(unsigned int c = 0; c < h; c++){
    j[c] = a[f-c-1] + b[g-c-1] + carry;
    d = j[c] % 10;
    carry = j[c] - d;
    carry /= 10;
    j[c] -= carry;
  }
  return_value[127] = h;
  for(int i = 0; i < h; i++){
    return_value[i] = j[h - i - 1];
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



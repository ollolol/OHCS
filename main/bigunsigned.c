

#include "../include/bigunsigned.h"
extern int R_Value[128];
unsigned int* plus(unsigned int* a, unsigned int* b){
  unsigned int d;
  unsigned int carry = 0;
  for(unsigned int c = 0; c < 128; c++){
    R_Value[c] = a[c] + b[c] + carry;
    d = R_Value[c] % 10;
    carry = R_Value[c] - d;
    carry /= 10;
    R_Value[c] -= carry;
  }
  return R_Value;
}
void printBig(unsigned int* a){
  for(unsigned int b = 0; b < a[127]; b++){
    printf("%u", a[b]);
  }
  printf("\n");
}
void scanBig(unsigned int* a){
  char str[127];

  scanf("%s", str);
  printf("You enter: ");
  int c = printf("%s\n", str);
  --c;
  if(c > 127){
    return;
  }
  for(unsigned int b = 0; b < c; b++){
    a[b] = (unsigned int)str[b];
  }

  for(unsigned int b = 0; b < c; b++){
    a[b] -= 48;
  }
  a[127] = c;
}


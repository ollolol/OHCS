
#include <../include/bigunsigned.h>
unsigned int* plus(unsigned int* a, uint32_t b){
  unsigned int R_Value[128];
  unsigned int d;
  unsigned int carry = 0;
  for(unsigned int c = 0, c < 128; c++){
    R_Value[c] = a[c] + b[c] + carry;
    d = R_Value[c] % 10;
    carry = R_Value[c] - d;
    carry /= 10;
    R_Value[c] -= carry;
  }
  return R_Value;
}
void printBig(unsigned int* a){
  for(unsigned int b = 0; b < 128; b++){
    printf("%u", a[b]);
  }
}
void scanBig(unsigned int* a){
  char str[128];
  scanf("%s", str);
  for(unsigned int b = 0; b < 128; b++){    
    a[b] = (unsigned int)str[b];
  }
}

#include <stdio.h>

void fun(int x){
  x = x + 5;
}


int main(){
  int x = 5;
  fun(x);
  printf("%d\n", x);
  return 0;
}

#include <stdio.h>
#include <stdiolib.h>

int main(){

  return 0;

  //syntax is to make constant all uppercase
  const int num = 5;
  printf("%d\n", num);

  //num = 8;
  //printf("%d", num);
  //this now throws an error, as a constant can't be changed

  /*
  *technically constant because text more or less exists, it can't really
  *be changed or modified, it just is
  */
  printf("Hello");


}

#include <stdio.h>
#include <stdiolib.h>

int main(){

  //prints out a float, and can do additional math in the print statement
  printf("%f", 5.0 + 8.9);

  //takes number a to the b power
  printf("%f", pow(2, 3));

  //square root a numbers
  printf("%d", sqrt(36));

  //gives next highest number, returns 37
  printf("%f", ceil(36.356));

  //always rounds down, returns 36
  printf("%f", floor(36.356));



  return 0;
}

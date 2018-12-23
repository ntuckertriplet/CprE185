#include <stdio.h>
#include <stdlib.h>

int main(){

  double firstNum;
  double secondNum;

  //records first num
  printf("Enter first number: ");
  scanf("%lf", &firstNum);

  //records second num
  printf("Enter second number: ");
  scanf("%lf", &secondNum);

  printf("Answer: %f", firstNum + secondNum);



  return 0;
}

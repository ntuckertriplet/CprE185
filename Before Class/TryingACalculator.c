#include <stdio.h>
#include <stdlib.h>

int main(){

  double firstNumber;
  double secondNumber;
  double answer;
  int operation;

  printf("Enter a number: ");

  scanf("%lf", &firstNumber);

  printf("Enter a second number: ");

  scanf("%lf", &secondNumber);

  printf("Enter the operation: 1 for adding, 2 for subtracting, 3 for multiplying, 4 for dividing");

  scanf("%d", &operation);

  (operation == 1) ? answer = firstNumber + secondNumber :
  (operation == 2) ? answer = firstNumber - secondNumber :
  (operation == 3) ? answer = firstNumber * secondNumber :
  answer = firstNumber / secondNumber;

  printf("%f", answer);

  return 0;
}

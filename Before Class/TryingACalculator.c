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

  printf("Enter the operation");

  scanf(" %c", &operation);

  if(operation == '+'){
    printf("%f", firstNumber + secondNumber);
  } else if (operation == '-'){
    printf("%f", firstNumber - secondNumber);
  } else if (operation == '*'){
    printf("%f", firstNumber * secondNumber);
  } else if (operation == '/'){
    printf("%f", firstNumber / secondNumber);
  }

  return 0;
}

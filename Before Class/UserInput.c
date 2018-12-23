#include <stdio.h>
#include <stdlib.h>

int main(){

  int userAge;
  printf("Enter your age: "\n;

  //this is a pointer to get user input in
  scanf("%d", &userAge);
  //scanning for doubles is %lf

  printf("You are %d years old", userAge);


  char grade;
  printf("Enter your grade: "\n;

  scanf("%c", &grade);

  printf("Your grade is %c", grade);


  
  return 0;
}

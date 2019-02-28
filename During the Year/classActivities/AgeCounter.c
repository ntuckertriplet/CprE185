#include <stdio.h>

int main() {
  int userAge;
  do {
      printf("Enter your age: ");
      scanf("%d", &userAge);
  } while (userAge < 0 || userAge > 130);

  printf("Your age is: %d", userAge);
  return 0;
}

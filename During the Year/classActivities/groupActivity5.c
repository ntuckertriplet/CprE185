#include <stdio.h>
#include <stdlib.h>

int main(){

  int user_num;
  int user_size;

  printf("Enter the number of elements: ");
  scanf("%d", &user_size);

  int *user_array = malloc(sizeof(user_size) * sizeof(int));

  for (int i = 0; i < user_size; i++) {
    printf("Enter number: %d", i + 1);
    scanf("%d", &user_array[i]);
  }

  int highest_value = user_array[0];
  for (int i = 1; i < user_size; i++){
    if (highest_value < user_array[i]) {
      highest_value = user_array[i];
    }
  }

  printf("The largest number is: %d\n", highest_value);

  return 0;
}
/*
jonathan huser
nathan Tucker
colton urbaitis
ian haltewick
eddie kilgore
*/

#include <stdio.h>

int summ(int a){
  if(a == 1){
    return 1;
  } else {
    return (a + summ(a - 1));
  }
}


int main(){

  int num_to_sum = 0;
  printf("Enter a number to calc summation: ");
  scanf("%d", &num_to_sum);
  printf("sum: %d\n", summ(num_to_sum));
  return 0;
}

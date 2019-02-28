#include <stdio.h>

int main(){

  int myArray[] = {5, 7, 38, 5, 6, 21, 90};
  int x = 0;
  int y = 0;
  for (int i = 0; myArray[i]; i++){
    if(y < myArray[i]){
      y = myArray[i];
    }

    if((x> myArray[i]) && (x != y)){
      x = myArray[i];
    }
  }

  printf("%d %d\n", x, y);
  return 0;
}

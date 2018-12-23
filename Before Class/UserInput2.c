#include <stdio.h>
#include <stdlib.h>

int main(){

  char name[20];
  printf("Enter your name: "\n);

  //if you enter in a first and last name, it will only grab
  //up to the first space. John Smith returns John
  //
  //scanf("%s", name);

  //snags a whole line
  ///stdin is just standard input
  fgets(name, 20, stdin);


  printf("Your name is: ", %s);

  return 0;
}

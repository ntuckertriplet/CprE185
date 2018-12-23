#include <stdio.h>//including libraries
#include <stdlib.h>

int main(){//main method

  char characterName[] = "john";
  int characterAge = 35;
  printf("There once was a man named %s\n", characterName);
  printf("He was %d years old\n", characterAge);
  printf("He liked the name %s\n", characterName);

  characterAge = 25;//variable gets new value from initial variable
  printf("But he did not like being %d years old\n", characterAge);
  return 0;

}

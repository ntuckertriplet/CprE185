#include <stdio.h>

int main(){

  char password[100];
  char secondPassword[100];
  int validPassword = 0;
  int same = 0;
  int validLength = 0;
  int lower = 0;
  int upper = 0;
  int number = 0;
  int symbol = 0;


  printf("Enter a password that's at least 4 digits, has a lowercase letter, uppercase letter, a symbol, and a number: \n")
  scanf("%s", password);

  while(validLength == 0){
    if(strlen(password) < 4){
      printf("Enter a longer password: \n");
      scanf("%s", password);
    } else {
      validLength = 1;
      printf("Enter the password again: \n");
      scanf("%s", secondPassword);
    }
  }

  while(same = 0){
    if(strcmp(password, secondPassword) != 0){
      printf("Passwords do not match. Try again: \n");
      scanf("%s", secondPassword);
    } else {
      same = 1;
    }
  }

  while(validPassword = 0;){
    for(int i = 0; password[i]; i++){
      if(isupper(password[i])){
        upper = 1;
      } else if (issymbol(password[i])){
        symbol = 1;
      } else if (islower(password[i])){
        lower = 1;
      } else if (isnumber(password[i])){
        number = 1;
      }
    }
    if(upper == 1 && symbol == 1 && lower == 1 && number == 1){
      validPassword = 1;
    } else {
      printf("invalid");
    }
  }

  printf("Success");

  return 0;
}

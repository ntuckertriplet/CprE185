#include <stdio.h>

int main(){
  //holders for the password and comparator password
  char password[100];
  char secondPassword[100];

  //overall valid password length and uniquiness
  int validPassword = 0;
  int validLength = 0;

  //flags for checking if two entries are the same, and if they contain each of
  //the uniqueness parameters. At least one uppercase, one lowercase, one number,
  //and one symbol to be valid inputs
  int same = 0;
  int lower = 0;
  int upper = 0;
  int number = 0;
  int symbol = 0;


  printf("Enter a password of at least 4 digits, \nhas a lowercase letter, uppercase letter, a symbol, and a number: \n")
  scanf("%s", password);

  //checking to see that the initial password is at least long enough
  while(validPassword == 0){
    while(validLength == 0){
      if(strlen(password) < 4){
        printf("Password too short, try again: \n");
      } else {
        //password is long enough, flagged to 1
        validLength = 1;
      }
    }


    //now checks to see that password is unique enough
    for (int i = 0; password[i]; i++) {
      if(islower(password[i])){
        lower = 1;
      } else if (isupper(password[i])){
        upper = 1;
      } else if (isnumber(password[i])){
        number = 1;
      } else if (issymbol(password[i])){
        symbol = 1;
      }
    }
    //if any are 0, or not true, the overall result will be 0
    if((lower*upper*number*symbol) == 0){
      printf("Enter a stronger password: \n");
    } else {
      //strong enough, exits loop
      validPassword = 1;
    }
  }


  //prompts the user to enter password again
  printf("Enter the password again: \n");
  scanf("%s", secondPassword);
  while(same == 0){
    //if they are the same, flagged as true, exits loop
    if(strcmp(password, secondPassword) == 0){
      same = 1;
      printf("Success");
    } else {
      //prompts to try again
      printf("Passwords not same, try again: \n");
      scanf("%s", secondPassword);
    }
  }
  return 0;
}

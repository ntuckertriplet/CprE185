#include <stdio.h>
#include <stdlib.h>


void checkDivisible(int input, int checkNumber) {
    (input % checkNumber == 0) ?  printf("%d: yes\n", checkNumber) :  printf("%d: no\n", checkNumber);
}

int main(int argc, char *argv[]) {

   for (int i = 2; i < 6; i++) {
       checkDivisible(atoi(argv[0]), i);
   }
   printf("%d", atoi(argv[0]));
}
if(input != 'a' || input != 'b' || input != 'd') [
    
]
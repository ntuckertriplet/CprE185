/*-----------------------------------------------------------------------------
-                             SE 185 Lab 05
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/
#include <stdio.h>

/* This program outputs if a integer will divide into another integer with no remainder*/

int main() {
    int i, j;

    printf("Enter an integer: ");
    scanf("%d", &i);

    //Needed another " in the expression
    printf("Enter another integer: ");

    //scanf statement needs a semicolon after the expression
    scanf("%d", &j);

    if (j % i == 0) {
        printf("%d divides %d\n", i, j);

    //There needed to be parens before and after the else expression
    }else{

        //printf was misspelled as pritf
        printf("%d does not divide %d\n", i, j);
        printf("%d %% %d is %d\n", j, i, (j % i) );
    }

    return 0;
}

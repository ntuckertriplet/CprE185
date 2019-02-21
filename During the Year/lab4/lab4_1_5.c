/*-----------------------------------------------------------------------------
-                             SE 185 Lab 05
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/
#include <stdio.h>

/* This progam calculates the sum of 1 to x, where x is a user input */

int sum_funct(int n);

//don't make a prototype of main
//int main();

int main()
{
    int input;

    printf("Please input a number from to sum up to: ");

    scanf("%d", &input);

    printf("The sum of 1 to %d is %d\n", input, sum_funct(input));

}

/*
You definitely can't have two main functions, 
this is all on one line, it doesn't return 0 as an int main,
 and it's just a print statement
*/
//int main(){printf("Sum is 32!\n");}

int sum_funct(int n)
{
    return (n*(n+1))/2;
}

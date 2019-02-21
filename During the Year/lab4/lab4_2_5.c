/*-----------------------------------------------------------------------------
-                             SE 185 Lab 05
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/
#include <stdio.h>

/* This program takes in a number from the user and checks if it is
 * a whole number. It also should print if the number is a
 * postive, negative, or zero number.
 * Ex.
 *      input:  num = 5
 *      output: 5 is a postive and 5 is non-negative and 5 is non-zero and 5 is a whole number.*/

int isPositive(double n);

int isNegative(double n);

int isZero(double n);

int main()
{
    //num should be a double to account for non whole numbers
    double num;

    printf("Please type a number between -1000 and 1000: ");
    scanf("%lf", &num);

    //|| operator, not |
    if(num > 1000 || num < -1000)
    {
        printf("Number is out of range!\n");
        return -1;
    }

    //the or operator is ||, not a single |, and the && operator, not &
    if( ( isPositive(num) && !isNegative(num) )  || isZero(num) )
    {
        printf("%lf is a whole number.\n", num);
    }
    else
    {
        printf("%lf is non-whole number.\n", num);
    }

    return 0;
}

int isPositive(double n)
{
    if(n>0)
    {
        printf("%lf is postive and ", n);
        return 1;
    }
    else
    {
        printf("%lf is non-postive and ", n);
        return 0;
    }
}

int isNegative(double n)
{
    if(n<0)
    {
        printf("%lf is negative and ", n);
        return 1;
    }
    else
    {
        printf("%lf is non-negative and ", n);
        return 0;
    }
}

int isZero(double n)
{
    if(n==0)
    {
        printf("%lf is zero and ", n);
        return 1;
    }
    else
    {
        printf("%lf is non-zero and ", n);
        return 0;
    }
}

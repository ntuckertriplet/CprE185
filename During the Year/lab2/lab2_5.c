/*-----------------------------------------------------------------------------
-					          SE 185 Lab 02
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name:Nate Tucker
- 	Section:B
-	NetID:njtucker
-	Date:7 February 2019
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-				  Implementation
-----------------------------------------------------------------------------*/
int main()
{
    double a, b, c;
    double filler;
    /* Put your code after this line */ 
	printf("Enter the base of the triange: ");
	scanf("%lf", &a);
	printf("Enter the height of the triangle: ");
	scanf("%lf", &b);
	

    /*  This next line will calculate the square root of whatever value is
        inside the parenthesis and assigns it to the variable filler. */
    filler = sqrt(pow(a, 2) + pow(b, 2));

	printf("The hypotenuse of a triangle is %.2lf\n", filler);

	

    return 0;


}


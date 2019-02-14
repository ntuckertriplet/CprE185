/*-----------------------------------------------------------------------------
-					          SE 185 Lab 03
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name:Nathan Tucker
- 	Section:2
-	NetID:njtucker
-	Date:13 February 2019
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/
#define TRUE 1


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/
/* Put your function prototypes here */
double mag(double x, double y, double z);
int minutes(int t);
int seconds(int t);
int millis(int t);


/*-----------------------------------------------------------------------------
-							Implementation
-----------------------------------------------------------------------------*/
int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t;
    double  ax, ay, az;


    while (TRUE) {
        scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az);

/* CODE SECTION 0 */
        printf("Echoing output: %d.%2d, %lf, %7.4lf, %7.4lf\n", (t/1000), t%1000, ax, ay, az);
/* 	CODE SECTION 1 */
        printf("At %d ms, the acceleration's magnitude was: %lf\n", t, mag(ax, ay, az));

/* 	CODE SECTION 2 */
        
    printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n",
        minutes(t), seconds(t), millis(t), mag(ax,ay,az));
    

    }

  return 0;
}

/* Put your functions here */
double mag(double x, double y, double z) {
    //Step 8, uncomment and modify the next line
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

int seconds(int t){
	return(t/1000) % 60;
}

int minutes(int t){
	return((t/1000) / 60);
}

int millis(int t){
	return(t%1000);
}

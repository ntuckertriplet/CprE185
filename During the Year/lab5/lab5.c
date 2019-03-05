/*-----------------------------------------------------------------------------
-					          SE 185 Lab 04
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name: Nate Tucker
- 	Section: 2
-	NetID: njtucker
-	Date: 27 February 2019
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
#define FALSE 0

/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/
int close_to(double, double, double);
double mag(double, double, double);
int orientation(double, double, double);
int print(int, int);

/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;
	int lastRead = 0;


    while (b1 != 1) {
        scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );

        /* printf for observing values scanned in from ds4rd.exe, be sure to comment or remove in final program */
        //printf("Echoing output: %d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n", t, ax, ay, az, gx, gy, gz, b1, b2, b3, b4);

        /* It would be wise (mainly save time) if you copy your code to calculate the magnitude from last week
         (lab 3).  You will also need to copy your prototypes and functions to the appropriate sections
         in this program. */

		 if(close_to(.04, .1, mag(ax, ay, az))){
			print(orientation(gx, gy, gz), lastRead);
		 }

        //printf("At %d ms, the acceleration's magnitude was: %f\n", t, mag(ax, ay, az));

    }

    return 0;
}

/* Put your functions here */
double mag(double ax, double ay, double az){
	return sqrt(pow(ax,2) + pow(ay,2) + pow(az,2));
}

int close_to(double tolerance, double point, double value){
	if(value < (tolerance + point) && value > (point - tolerance))
		return 1;

	return 0;
}

int orientation(double gx, double gy, double gz){
	if(close_to(.2, 1.0, gy)){
		return 1;
	} else if (close_to(.2, -1.0, gy)) {
		return 2;
	} else if (close_to(.2, 1.0, gx)) {
		return 3;
	} else if (close_to(.2, -1.0, gx)) {
		return 4;
	} else if (close_to(.2, -1.0, gz)) {
		return 5;
	} else if (close_to(.2, 1.0, gz)) {
		return 6;
	} else {
		return 0;
	}
}

int print(int orient, int lastOrient){
	if(orient != lastOrient){
		switch(orient){
			case 1:
			printf("Top\n");
			break;

			case 2:
			printf("Bottom\n");
			break;

			case 3:
			printf("Left\n");
			break;

			case 4:
			printf("Right\n");
			break;

			case 5:
			printf("Front\n");
			break;

			case 6:
			printf("Back\n");
			break;
		}
	}
	lastOrient = orient;
}

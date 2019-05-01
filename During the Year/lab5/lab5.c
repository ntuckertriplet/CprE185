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
int orientation(double);

/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;
	  int flag = 0;


    while (b1 != 1) {
        scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );

        /* printf for observing values scanned in from ds4rd.exe, be sure to comment or remove in final program */
        //printf("Echoing output: %d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n", t, ax, ay, az, gx, gy, gz, b1, b2, b3, b4);

        /* It would be wise (mainly save time) if you copy your code to calculate the magnitude from last week
         (lab 3).  You will also need to copy your prototypes and functions to the appropriate sections
         in this program. */

		 if(close_to(.1, 0.0, gx)){
			if(close_to(.1, 1.0, gy)) {
        if(close_to(.1, 0.0, gz)) && flag != 1 {
          orientation(1);
          flag = 1;
        }
      }
		 }

     if(close_to(.1, 0.0, gx)){
			if(close_to(.1, -1.0, gy)) {
        if(close_to(.1, 0.0, gz)) && flag != 2 {
          orientation(2);
          flag = 2;
        }
      }
		 }

     if(close_to(.1, 0.0, gx)){
			if(close_to(.1, 0.0, gy)) {
        if(close_to(.1, -1.0, gz)) && flag != 3 {
          orientation(3);
          flag = 3;
        }
      }
		 }

     if(close_to(.1, 0.0, gx)){
			if(close_to(.1, 0.0, gy)) {
        if(close_to(.1, 1.0, gz)) && flag != 4 {
          orientation(4);
          flag = 4;
        }
      }
		 }

     if(close_to(.1, 1.0, gx)){
			if(close_to(.1, 0.0, gy)) {
        if(close_to(.1, 0.0, gz)) && flag != 5 {
          orientation(5);
          flag = 5;
        }
      }
		 }

     if(close_to(.1, -1.0, gx)){
			if(close_to(.1, 0.0, gy)) {
        if(close_to(.1, 0.0, gz)) && flag != 6 {
          orientation(2);
          flag = 6;
        }
      }
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
  int close;
  (value <= (tolerance + point) && value >= (point - tolerance)) ? close = 1 : close = 0;
  return close;
	// if(value <= (tolerance + point) && value >= (point - tolerance)){
	// 	return 1;
  // } else {
	//   return 0;
  // }
}

void orientation(int direction){
  (direction == 1) ? printf("TOP") :
  (direction == 2) ? printf("BOTTOM") :
  (direction == 3) ? printf("RIGHT") :
  (direction == 4) ? printf("LEFT") :
  (direction == 5) ? printf("FRONT") : printf("BACK") ;
}

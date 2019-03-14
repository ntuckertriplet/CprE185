/*-----------------------------------------------------------------------------
-					          SE 185 Lab 07
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name:
//./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b -j -g | ./lab7
- 	Section:
-	NetID:
-	Date:
-
-   This file provides the outline for your program
-   Please implement the functions given by the prototypes below and
-   complete the main function to make the program complete.
-   You must implement the functions which are prototyped below exactly
-   as they are requested.
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
#define PI 3.141592653589

/* NO GLOBAL VARIABLES ALLOWED */


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------
    PRE: Arguments must point to double variables or int variables as appropriate
    This function scans a line of DS4 data, and returns
    True when left button is pressed
    False Otherwise
    POST: it modifies its arguments to return values read from the input line.
------------------------------------------------------------------------------------*/
int read_input( int* time,
                double* g_x, double* g_y, double* g_z,
                int* button_T, int* button_C, int* button_X, int* button_S,
                int* l_joy_x, int* l_joy_y, int* r_joy_x, int* r_joy_y ){
					int a;
					//scanf("%d",a);
					//printf("Hi %x %d", time, a);
					scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d,",&a, g_x, g_y, g_z, button_T, button_C, button_X, button_S,
					l_joy_x, l_joy_y, r_joy_x, r_joy_y);
					//printf("%d %lf %lf %lf %d %d %d %d %d %d %d %d\n",a,*g_x, *g_y, *g_z, *button_T, *button_C, *button_X, *button_S,
					//*l_joy_x, *l_joy_y, *r_joy_x, *r_joy_y);
					
					if(*button_C == 1){
						return 0;
					}
					else{
						return 1;
					}
				}

/*-----------------------------------------------------------------------------
    PRE: ~(-1.0) <= mag <= ~(1.0)
    This function scales the roll/pitch value to fit on the screen.
    Input should be capped at either -1.0 or 1.0 before the rest of your
    conversion.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleMagForScreen(double rad){
	return (int)((((asin(rad) + PI /2) / PI) * 78)-39);
}

/*-----------------------------------------------------------------------------
    PRE: -128 <= mag <= 127
    This function scales the joystick value to fit on the screen.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleJoyForScreen(int rad){
	return (int)((((rad + 128.0) / 255.0) * 78)-39);
}

/*----------------------------------------------------------------------------
    PRE: -39 <= number <= 39
    Uses print_chars to graph a number from -39 to 39 on the screen.
    You may assume that the screen is 80 characters wide.
----------------------------------------------------------------------------*/
void graph_line(int number){
		
}

/*-----------------------------------------------------------------------------
    PRE: num >= 0
    This function prints the character "use" to the screen "num" times
    This function is the ONLY place printf is allowed to be used
    POST: nothing is returned, but "use" has been printed "num" times
-----------------------------------------------------------------------------*/
void print_chars(int num, char use){
	if(num > 0){
		for(int j = 0; j < 39; j++){
			printf(" ");
		}
		for(int j = 0; j < num; j++){
			printf("r");
		}
	}
	else if(num < 0){
		for(int j = 0; j < 39 + num; j++){
			printf(" ");
		}
		for(int j = 39 + num; j < 40; j++){
			printf("l");
		}
	}
	else{
		for(int j = 0; j < 39; j++){
			printf(" ");
		}
		printf("0");
	}
	printf("\n");
}


/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
int main()
{
    double x, y, z;                     /* Values of x, y, and z axis*/
    int t;                              /* Variable to hold the time value */
    int b_Up, b_Down, b_Left, b_Right;  /* Variables to hold the button statuses */
    int j_LX, j_LY, j_RX, j_RY;         /* Variables to hold the joystick statuses */
    int scaled_pitch, scaled_roll; 	    /* Value of the roll/pitch adjusted to fit screen display */
    int scaled_joy;                     /* Value of joystick adjusted to fit screen display */

    /* Put pre-loop preparation code here */
	int runOrNo = 1;
	int buttonPushed = 0;//bool
	int state = 0;//0 == right-left//1= front-back//2= joystick
    do
    {
        /* Scan a line of input */
		runOrNo = read_input(&t,&x,&y,&z,&b_Up,&b_Right, &b_Down,&b_Left, &j_LX, &j_LY, &j_RX,&j_RY);
		
		//scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d,",&t,&x,&y,&z,&b_Up,&b_Right, &b_Down,&b_Left, &j_LX, &j_LY, &j_RX,&j_RY);
		//printf("%d %lf %lf %lf %d %d %d %d %d %d %d %d \n",t,x,y,z,b_Up,b_Right, b_Down,b_Left, j_LX, j_LY, j_RX,j_RY);
        /* Calculate and scale for pitch AND roll AND joystick */

        /* Switch between roll, pitch, and joystick with the up, down, and right button, respectivly */
		if(b_Left == 1){
			buttonPushed = 1;
		}
		else if(buttonPushed && b_Left != 1){
			if(state == 2){
				state = 0;
			}
			else{
				state++;
			}
			buttonPushed = 0;
		}
		

        /* Output your graph line */
		if(state == 0){
			print_chars(scaleMagForScreen(x),' ');
		}
		else if(state == 1){
			print_chars(scaleMagForScreen(y),' ');
		}
		else if(state == 2){
			print_chars(scaleJoyForScreen(j_RY),' ');
		} 


        fflush(stdout);

    } while (runOrNo); /* Modify to stop when left button is pressed */ //Bonus also requires the use of the left button so ????

    return 0;

}

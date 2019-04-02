/*-----------------------------------------------------------------------------
-					          SE 185 Lab 07
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name: Nate Tucker
- Section: B
-	NetID: njtucker
-	Date: 27 March 2019
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
#include <math.h>


/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
#define PI 3.141592653589
#define TRUE 1
#define FALSE 0

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
                int* l_joy_x, int* l_joy_y, int* r_joy_x, int* r_joy_y );

/*-----------------------------------------------------------------------------
    PRE: ~(-1.0) <= mag <= ~(1.0)
    This function scales the roll/pitch value to fit on the screen.
    Input should be capped at either -1.0 or 1.0 before the rest of your
    conversion.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleMagForScreen(double rad);

/*-----------------------------------------------------------------------------
    PRE: -128 <= mag <= 127
    This function scales the joystick value to fit on the screen.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleJoyForScreen(int rad);

/*----------------------------------------------------------------------------
    PRE: -39 <= number <= 39
    Uses print_chars to graph a number from -39 to 39 on the screen.
    You may assume that the screen is 80 characters wide.
----------------------------------------------------------------------------*/
void graph_line(int number);

/*-----------------------------------------------------------------------------
    PRE: num >= 0
    This function prints the character "use" to the screen "num" times
    This function is the ONLY place printf is allowed to be used
    POST: nothing is returned, but "use" has been printed "num" times
-----------------------------------------------------------------------------*/
void print_chars(int num, char use);

double pitch(double z_mag);

double roll(double x_mag);


/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/

//./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -g -b -j | ./lab7.exe

int main()
{
	int time;
	double g_x, g_y, g_z;                       // magnitude values of x, y, and z
	int b_Triangle, b_X, b_Square, b_Circle;    // variables to hold the button statuses
	double roll_rad, pitch_rad;                 // value of the roll measured in radians
	int l_joy_x, l_joy_y, r_joy_x, r_joy_y;  // value of the roll adjusted to fit screen display
	
	int lastPressed = 0, set = 0;
	do{
		
		
		read_input(&time, &g_x, &g_y, &g_z, &b_Triangle, &b_Circle, &b_X, &b_Square, &l_joy_x, &l_joy_y, &r_joy_x, &r_joy_y);
		if (set == 0 && b_Circle == 1) {
			lastPressed = (lastPressed + 1) % 3;
			set = 1;
		}
	
		if (b_Circle == 0) {
			set = 0;
		}
		
		if (lastPressed == 0) {
			graph_line(scaleMagForScreen(roll(g_x)));
		}if (lastPressed == 1){
			graph_line(scaleMagForScreen(pitch(g_y)));
		}if (lastPressed == 2) {
			graph_line(scaleJoyForScreen(r_joy_x));
		}

		fflush(stdout);	


		
	} while (b_Square != 1); // Modify to stop when the square button is pressed
	return 0;
}

/*
This function scans a line of DS4 data, and returns
True when left button is pressed
False Otherwise
*/
int read_input(int* time, double* g_x, double* g_y, double* g_z, int* button_T, int* button_C, int* button_X, int* button_S, int* l_joy_x, int* l_joy_y, int* r_joy_x, int* r_joy_y ){
	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d", time, g_x, g_y, g_z, button_T, button_C, button_X, button_S, l_joy_x, l_joy_y, r_joy_x, r_joy_y);
	if(*button_S == 0) {
		return FALSE;
	}
	return TRUE;
}

/*
This function scales the roll/pitch value to fit on the screen.
Input should be capped at either -1.0 or 1.0 before the rest of your
conversion.
*/
int scaleMagForScreen(double rad) {
	return (39 / (PI / 2.0)) * rad;
}

/* This function scales the joystick value to fit on the screen. */
int scaleJoyForScreen(int joystick_VAL) {
	return joystick_VAL / 5;

}

double pitch(double z_mag) {
	if (z_mag > 1) {
		z_mag = 1;
	}else if (z_mag < -1) {
		z_mag = -1;
	}
	return (-1) * (z_mag);
}

double roll(double x_mag) {
	if (x_mag > 1) {
		x_mag = 1;
	}else if (x_mag < -1) {
		x_mag = -1;
	}
	return (-1) * asin(x_mag);
}

/*
Uses print_chars to graph a number from -39 to 39 on the screen.
You may assume that the screen is 80 characters wide.
*/
void graph_line(int number) {
	if (number == 0) {
		print_chars(39, ' ');
		print_chars(1, '0');
	}
	if (number > 0) {
		print_chars(39, ' ');
		print_chars(number, 'R');
		
	}else {
		print_chars(39 + number, ' ');
		print_chars(-number, 'L');
	}
	print_chars(1, '\n');
	fflush(stdout);
}


/*
This function prints the character "use" to the screen "num" times
This function is the ONLY place printf is allowed to be used
*/
void print_chars(int num, char use) {
	for (int i = 0; i < num; i++) {
		printf("%c", use);
	}
	
}

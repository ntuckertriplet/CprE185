/*-----------------------------------------------------------------------------
-					  		SE 185 Lab 08
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name:
- Section:
-	NetID:
-	Date:
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>


/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
/* Mathmatical constants */
#define PI 3.14159

/* 	Screen geometry
    Use ROWS and COLUMNS for the screen height and width (set by system)
    MAXIMUMS */
#define COLUMNS 100
#define ROWS 80

/* 	Character definitions taken from the ASCII table */
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

/*	Number of samples taken to form an moving average for the gyroscope data
    Feel free to tweak this. */
#define NUM_SAMPLES 10


/*-----------------------------------------------------------------------------
-								Static Data
-----------------------------------------------------------------------------*/
/* 2D character array which the maze is mapped into */
char MAZE[COLUMNS][ROWS];


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*	POST: Generates a random maze structure into MAZE[][]
    You will want to use the rand() function and maybe use the output %100.
    You will have to use the argument to the command line to determine how
    difficult the maze is (how many maze characters are on the screen). */
void generate_maze(int difficulty);

/*	PRE: MAZE[][] has been initialized by generate_maze()
    POST: Draws the maze to the screen */
void draw_maze(void);

/*	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y */
void draw_character(int x, int y, char use);

/*	PRE: -1.0 < mag < 1.0
    POST: Returns tilt magnitude scaled to -1.0 -> 1.0
    You may want to reuse the roll function written in previous labs. */
double calc_roll(double mag);

/* 	Updates the buffer with the new_item and returns the computed
    moving average of the updated buffer */
double m_avg(double buffer[], int avg_size, double new_item);


/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
/*	Main - Run with './ds4rd.exe -t -g -b' piped into STDIN */
void main(int argc, char* argv[])
{
	
	double x[200], y[200], z[200];
    double new_x, new_y, new_z;
    double avg_x, avg_y, avg_z;
	int button_t, button_c, button_x, button_s;
	int t = 0, update_time;
	int i = 0, j = 0;


	if (argc != 2 )
	{
		printw("You must enter the difficulty level on the command line.");
		refresh();
		return;
	}
	else
	{
	/* 	Setup screen for Ncurses
		The initscr functionis used to setup the Ncurses environment
		The refreash function needs to be called to refresh the outputs
		to the screen */
		initscr();
		refresh();

		/* WEEK 2 Generate the Maze */
		generate_maze(1);
		draw_maze();
		draw_character(0, 0, AVATAR);

		/* Read gyroscope data and fill the buffer before continuing */
		while(t < 1000) {
			//scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &new_x, &new_y, &new_z, &button_t, &button_c, &button_x, &button_s);
		}
		/* Event loop */
		do
		{
			
			/* Read data, update average */
			//scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &new_x, &new_y, &new_z, &button_t, &button_c, &button_x, &button_s);
			avg_x = m_avg(x, NUM_SAMPLES, new_x);
			avg_y = m_avg(y, NUM_SAMPLES, new_y);
			avg_z = m_avg(z, NUM_SAMPLES, new_z);

			/* Is it time to move?  if so, then move avatar */
			if (avg_x > 0) {
				draw_character(i + 1, j + 1, AVATAR);
				MAZE[i][j] = EMPTY_SPACE;
				refresh();
			}
			
			int wait = 0;
			int waitlonger = 0;
			while(wait < 100000) {
				while (waitlonger < 100000) {
					
				}
			}
			
			
		} while(1); // Change this to end game at right time

			/* Print the win message */


			/* This function is used to cleanup the Ncurses environment.
			Without it, the characters printed to the screen will persist
			even after the progam terminates */
			endwin();

		}

			printf("YOU WIN!\n");
}

double m_avg(double buffer[], int avg_size, double new_item)
{
	double output = 0;
	
	for(int i = 0; i < avg_size; i++) {
		output = output + buffer[i];
	}
	
	output /= avg_size;
	
	for (int i = 0; i < avg_size; i++) {
		buffer[i] = buffer[i + 1];
	}
	
	buffer[avg_size - 1] = new_item;
    return output;
}


/* 	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y
    THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
    DO NOT NEED TO CHANGE THIS FUNCTION. */
void draw_character(int x, int y, char use)
{
    mvaddch(y,x,use);
    refresh();
}


void draw_maze(){

	for(int i = 0; i < COLUMNS; i++) {
		for(int j = 0; j < ROWS; j++) {
			MAZE[i][j] = ' ';
		}
	}
	refresh();
}

void generate_maze(int difficulty){
	for(int i = 0; i < COLUMNS; i ++) {
		for(int j = 0; j < ROWS; j ++) {
			MAZE[i][j] = ' ';
		}
	}
	refresh();
}

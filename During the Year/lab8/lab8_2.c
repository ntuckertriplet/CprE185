/*-----------------------------------------------------------------------------
-					  		SE 185 Lab 08
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name: Nathan Tucker
- Section: B
-	NetID: njtucker
-	Date:
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <time.h>


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
int main(int argc, char* argv[])
{
	int loss = 0;
	int row = 0, col = COLUMNS / 2, buffer, sideBuffer, timeIn;
	double gX, gY, gZ;

	if (argc <2) { printf("You forgot the difficulty\n"); return 1;}
	int difficulty = atoi(argv[1]); // get difficulty from first command line arg
	// setup screen
	initscr();
	refresh();

	srand(time(NULL));
	// Generate and draw the maze, with initial avatar
	generate_maze(difficulty);
	draw_maze();
	refresh();
	// Read gyroscope data to get ready for using moving averages.
	scanf("%d, %lf, %lf, %lf", &timeIn, &gX, &gY, &gZ);
	buffer = sideBuffer = timeIn;
	// Event loop

	do
	{
		// Read data, update average
		scanf("%d, %lf, %lf, %lf", &timeIn, &gX, &gY, &gZ);
		// Is it time to move?  if so, then move avatar
		if (timeIn - sideBuffer > 50) {																								//time to move
			if (calc_roll(gX) > .2 && col < COLUMNS && MAZE[row][col + 1] != WALL){  				//Right move
				col++;
				draw_character(col, row, AVATAR);																					//Draw charactar
				draw_character(col - 1, row, ' ');																				//erase previouse

				sideBuffer = timeIn;
			}
			else if (calc_roll(gX) < -.2 && col > 0 && MAZE[row][col - 1] != WALL){					//Left move
				col--;
				draw_character(col, row, AVATAR);																					//Draw charactar
				draw_character(col + 1, row, ' ');																				//erase previouse

				sideBuffer = timeIn;
			}
		}
		if (timeIn - buffer > 500 && MAZE[row + 1][col] != WALL) {										//Time to move down / can i move down
			row++;
			draw_character(col, row, AVATAR);																						//Draw charactar
			draw_character(col, row - 1, ' ');																					//erase previouse
			buffer = timeIn;
		}

		// Check if loss
		if (MAZE[row + 1][col] == WALL && MAZE[row][col - 1] == WALL && MAZE[row][col + 1] == WALL) {
			sleep(1);
			loss = 1;
			break;

		}
	} while(row < ROWS); // Change this to end game at right time

	// Print the win message
	endwin();
	system("CLEAR");
	if (loss) {
		for (int i = 0; i < row / 2; i++){
			printf("YOU LOST!!!! \t\t(╯°□°）╯︵ ┻━┻\n");
		}
		printf("You lasted %d rows and %lf seconds, %02.1lf%%",row, (double)timeIn / 1000.0, 100 * ((double)row / (double)ROWS));
	}
	else printf("YOU WIN!\n");																												//announce win
	fflush(stdout);
	return 0;
}


double m_avg(double buffer[], int avg_size, double new_item)
{
	double output = 0;
	
	for(int i = 0; i < avg_size; i++) {
		output += buffer[i];
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
void draw_character(int x, int y, char use){
    mvaddch(y,x,use);
    refresh();
}


void generate_maze(int difficulty){
	for(int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			MAZE[i][j] = rand() % 100 < difficulty ? WALL : EMPTY_SPACE;
		}
	}
}

void draw_maze(void){
	for(int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			mvaddch(i, j, MAZE[i][j]);
		}
	}
}

double calc_roll(double x_mag){
	if (x_mag > 1) {
		x_mag = 1;
	}
	else if(x_mag < -1) {
		x_mag = -1;
	}

	return (-1) * asin(x_mag);
}

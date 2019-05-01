// WII-MAZE Skeleton code written by Jason Erbskorn 2007
// Edited for ncurses 2008 Tom Daniels
// Updated for Esplora 2013 TeamRursch185
// Updated for DualShock 4 2016 Rursch


// Headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>

// Mathematical constants
#define PI 3.14159

// Screen geometry
// Use ROWS and COLS for the screen height and width (set by system)
// MAXIMUMS
#define NUMCOLS 100
#define NUMROWS 72

// Character definitions taken from the ASCII table
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '


// 2D character array which the maze is mapped into
char MAZE[NUMROWS][NUMCOLS];

int close_to(double tolerance, double point, double value){
	if ((value < (tolerance + point))&&(value > (point - tolerance))){
		return 1;
	}else
		return 0;
}

// POST: Generates a random maze structure into MAZE[][]
//You will want to use the rand() function and maybe use the output %100.  
//You will have to use the argument to the command line to determine how 
//difficult the maze is (how many maze characters are on the screen).
void generate_maze(int difficulty){
	int i, j, k;
	for (i = 0; i < NUMROWS; i++){
		for (j = 0; j < NUMCOLS; j++){
			if (j == 0 || j == (NUMCOLS - 1)){
				MAZE[i][j] = WALL;
			}else{
				k = rand() % 100;
				if (k < difficulty){
					MAZE[i][j] = WALL;
				}else{
					MAZE[i][j] = EMPTY_SPACE;
				}
			}
		}
	}
}


void draw_character(int x, int y, char use); 
// PRE: MAZE[][] has been initialized by generate_maze()
// POST: Draws the maze to the screen 
void draw_maze(void){
	for (int i = 0; i < NUMROWS; i++){
		for (int j = 0; j < NUMCOLS; j++){
			draw_character(i, j, MAZE[i][j]);
		}
	}
	refresh();
}

// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
void draw_character(int x, int y, char use){
	mvaddch(x, y, use);
	refresh();
}

// PRE: -1.0 < x_mag < 1.0
// POST: Returns tilt magnitude scaled to -1.0 -> 1.0
// You may want to reuse the roll function written in previous labs.  
/*double roll(double x_mag){
	if (close_to(.01, 1, x_mag)){
		x_mag = 1.0;
	}
	else if (close_to(.01, -1, x_mag)) {
		
		x_mag = -1.0;
	}
	
	return asin(x_mag);
}*/

float calc_roll(float x_mag){
	if (close_to(.01, 1, x_mag)){
		x_mag = 1.0;
	}
	else if (close_to(.01, -1, x_mag)) {
		
		x_mag = -1.0;
	}
	
	return asin(x_mag);
}

// Main - Run with './ds4rd.exe -t -g -b' piped into STDIN
int main(int argc, char* argv[])
{
	if (argc <2) { printf("You forgot the difficulty\n"); return 1;}
	int difficulty = atoi(argv[1]); // get difficulty from first command line arg
	// setup screen    
	initscr();
	refresh();
	
	double gx, gy, gz;
	int diffT, oldT, newT;
	int t, row, col, lost;
	int count, count2;
	row = 0;
	col = NUMCOLS/2;
	// Generate and draw the maze, with initial avatar
	generate_maze(difficulty);
	draw_maze();
	draw_character(row, col, AVATAR);
	
	
	// Read gyroscope data to get ready for using moving averages.    

	// Event loop
	while(row != NUMROWS - 1)
	{

		// Read data, update average
		scanf("%d, %lf, %lf, %lf", &newT, &gx, &gy, &gz);
		// Is it time to move?  if so, then move avatar
		//printf("%d", t);
		
		
		diffT = newT - oldT;
		
		if (MAZE[row + 1][col] != WALL){//Can we move down?
			if (diffT >= 500){
				row++;
				draw_character(row, col, AVATAR);
				draw_character(row - 1, col, EMPTY_SPACE);
				oldT = newT;
			}		
		}
		if (MAZE[row][col+1] != WALL){//Can we move Right?
			if (diffT >= 350){
				if (close_to(.6, -1, calc_roll(gx))){
					col++;
					draw_character(row, col, AVATAR);
					draw_character(row, col - 1, EMPTY_SPACE);
					oldT = newT;
				}
			}
		}	
		if (MAZE[row][col - 1] != WALL){//Can we move left?
			if (diffT >= 350){
				if (close_to(.6, 1, calc_roll(gx))){
					col--;
					draw_character(row, col, AVATAR);
					draw_character(row, col + 1, EMPTY_SPACE);
					oldT = newT;
				}
			}
		}
		if (MAZE[row + 1][col] == WALL && MAZE[row][col + 1] == WALL && MAZE[row][col - 1] == WALL){//Are we stuck in a bucket?
			lost = 1;
			sleep(2);
			break;
		}
		//while(1); // Change this to end game at right time 
	}
	// Print the win message
	endwin();
	if (lost){//Did we lose?
		printf("You lost idiot");
	}else{//Did we win?
		printf("YOU WIN!\n");
	}
	return 0;
}



// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
//THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
//
//    >>>>DO NOT CHANGE THIS FUNCTION.<<<<



// Lab 9 DS4Talker Skeleton Code
// ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b -j -bt
// ./ds4rd.exe -d 054c:09CC -D DS4_BT -t -b -j -bt
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses.h>
#define WORDLENGTH 11
#define MAXWORDS 100
#define DEBUG 0   // set to 0 to disable debug output


// modifies str to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* s);

// Reads words from the file into WL and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int read_words(char* wl[MAXWORDS], char* filename);

int screenToIndex(int y, int x) {
	return (x / 15) + (y *5);
}

void printInterface(char* words[]) {
	int p = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 75; j+=15) {
			mvprintw(i, j, "%15s ", words[p]);
			refresh();
			p++;
		}
	}
}

/* pass in the selected element, the original sentence to change, the word to add, and whether to shift */
void trianglePressed(char* select, char* sentenceToChange, char* word, int shift) {
	select = (char*)(malloc((strlen(word) + 1)* sizeof(char)));
	char* temp = (char*)(malloc(strlen(word)));
	strcpy(temp, word);
	select = temp;
	if (shift) {
		select[0] = toupper(select[0]);
	}
	char final[] = " ";
	strcat(final, select);
	strcat(sentenceToChange, final);
	free(temp);

}

/* pass in the selected element, the original sentence to change, the word to add, and whether to shift */
void squarePressed(char* select, char* sentenceToChange, char* word, int shift) {
	select = (char*)malloc((strlen(word) + 1* sizeof(char)));
	char* temp = (char*)(malloc(strlen(word)));
	strcpy(temp, word);
	select = temp;
	strcat(sentenceToChange, select);
	free(temp);
}
/* 
void XPressed(char* select, char* sentenceToChange) {
	
	char* undo = sentenceToChange;
	
	while (undo != NULL) {
		undo = strstr(undo, select);
		
		if (undo != NULL) {
			undo += sizeof(select) - 1;
		}
	}
	strcpy(undo, "");
	
	free(undo);
} */

int main(int argc, char* argv[]) {
	char* wordslist[MAXWORDS];
	int wordCount;
	int i;
	wordCount = read_words(wordslist, argv[1]);

	/* simple debug function to see if wordslist was read 
	if (DEBUG) {
		printf("Read %d words from %s \n",wordCount, argv[1]);
	}
	*/
	int time, triangle, circle, x, square, rightDown, leftDown, option, share, l2, r2, l1, r1;
	int lVertical, rHorizontal, rVertical, lHorizontal; 
	initscr();
	refresh();
	int row = 0;
	int col = 1;
	int rowA = 0; int colA = 8; int lastrowA = 0; int lastcolA = 8;
	int buffer = 0; int buttonBuffer = 0;
	int tri = 0; int s = 0; int cross = 0; int circ = 0; int clear;
	
	/* prints out the nice, neat word list interface */
	printInterface(wordslist);
	
	mvaddch(rowA, colA, '*');
	refresh();
	
	char sentence[80] = "";
	char* selected[80];
	
	int k = 0;
	
	do {
		scanf(" %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			&time, &triangle, &circle, &x, &square, &rightDown, &leftDown, &option, &share, &l2, &r2, &l1, &r1, &lHorizontal,
			&lVertical, &rHorizontal, &rVertical);
		
		/* this tracks movement. every 150ms, if the joy values are high enough, move in the corresponding direction */
		if (time - buffer > 150) {
			if (rHorizontal < -50 && lastcolA > 15) {
				colA -= 14;
			}else if (rHorizontal > 50 && lastcolA < 60){
				colA += 14;
			}
			if (rVertical > 50 && lastrowA < 14) {
				rowA++;
			}else if (rVertical < -50 && lastrowA > 0) {
				rowA--;
			}
			buffer = time;
		}
		
		mvaddch(lastrowA, lastcolA, ' ');
		mvaddch(rowA, colA, '*');
		lastrowA = rowA;
		lastcolA = colA;
		
	
	
	int listIndex = screenToIndex(rowA, colA);
	
	/* only operate every 150 ms */
	if (time - buttonBuffer > 150) {
		
		/*checks so that the operation is only done once per press. Rising edge detector */
		if (circle) {
			if (!circ) {
				circ = 1;
			}else {
				circ = 0;
			}
		}
		
		/* if triangle is pressed */
		if (triangle) {
			if (!tri) {
				tri = 1;
			} else {
				tri = 0;
			}
		}
		
		/* if square is pressed */
		if (square) {
			if (!s) {
				s = 1;
			}else {
				s = 0;
			}
		}
		
		/* undo function, making the boolean circ true for the shift of the sentence */
		if (x) {
			if (!cross) {
				cross = 1;
			}else {
				cross = 0;
			}
		}
		
		/* boolean for the clear function */
		if (rightDown) {
			if (!clear) {
				clear = 1;
			} else {
				clear = 0;
			}
		}
		
		/* will only enter if previous has not been pressed */
		if (tri) {
			/* passes in the selected character from the list, the sentence to add, and circ as 1, meaning shift */
			trianglePressed(selected[k], sentence, wordslist[listIndex], circ);
			selected[k] = wordslist[listIndex];
			tri = 0;
			k++;
			/* resets value back to 0 */
			if (circ) {
				circ = 0;
			}
		}
		if (s) {
			/* passes in the selected character from the list, the sentence to add, and circ as 0, meaning no shift */
			squarePressed(selected[k], sentence, wordslist[listIndex], circ);
			selected[k] = wordslist[listIndex];
			s = 0;
			k++;
			if (circ) {
				circ = 0;
			}
		}
		/* this is the functionality of the undo function */
		/* move the array to the previously stored state, and set the highest value to \0 */
		if (cross ) {
			k--;
			selected[k] = "\0";
			strcpy(sentence, "\0");
			
			for(int i=0; i<k; i++) {
				strcat(sentence, selected[i]);
			}
			mvprintw(20, 0, "%85s", "");
			refresh();
			cross = 0;
		}
		
		/* clears upon joystick press */
		if (clear) {
			strcpy(sentence, "");
			clear = 0;
			mvprintw(20, 0, "%85s", sentence);
		}
		
		/* reset the time buffer */
		buttonBuffer = time;
	}

	/* prints out the sentence to be printed and added to */
	fflush(stdout);
	mvprintw(20, 0, "%s", sentence);
	refresh();
	

	}while(1);

	
// most of your code for part 2 goes here. Don't forget to include the ncurses library 
	//endwin();
    return 0;
	}
	
// DO NOT MODIFY THIS FUNCTION!
void trimws(char* str) {
	int length = strlen(str);
	int x;
	if (length == 0) return;
	x = length - 1;
	while (isspace(str[x]) && (x >= 0)) {
		str[x] = '\0';
		x -= 1;
	}
}


// DO NOT MODIFY THIS FUNCTION!
int read_words(char* WL[MAXWORDS], char* file_name)
{
	int numread = 0;
	char line[WORDLENGTH];
	char *p;
	FILE* fp = fopen(file_name, "r");
	while (!feof(fp)) {
		p = fgets(line, WORDLENGTH, fp);
		if (p != NULL) 
		{
			trimws(line);
			WL[numread] = (char *)malloc(strlen(line) + 1);
			strcpy(WL[numread], line);
			numread++;
		}
	}
	fclose(fp);
	return numread;
}
	
	
	


/*-----------------------------------------------------------------------------
-					          SE 185 Lab 06
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name: Nate Tucker
- 	Section: B
-	NetID: njtucker
-	Date: 13 March 2019
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*-----------------------------------------------------------------------------
-	                             Defines
-----------------------------------------------------------------------------*/
#define TRUE 1
#define FALSE 0


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main()
{
	int t, b1, b2, b3, b4;
	int done = 0;
	int started = 0;
	int randButton;
	int failed = 0;
	int numRounds = 0;
	int localTime = 2500;
	int timeUp = 0;
	
	printf("Press the circle button to begin\n");
	while (started == 0){
		scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );
		if (b2 == 1){
			started = 1;
		}
	}
	
	while (done == 0) {
		srand(time(0)); 
		randButton =  rand() % 4;
		scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );
		
	if (b1 == 0 && b2 == 0 && b3 == 0  && b4 == 0 ){
		if (randButton == 0){
			int cont = 0;
			scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );
			int initialTime = t;
			printf("Press the triangle button\n");
			printf("You have %d milliseconds to respond!\n", localTime);
			while(cont == 0 || timeUp == 1){
				scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );
				if((t - initialTime) > localTime){
					timeUp = 1;
					done = 1;
					break;
				}
				if (b1 == 1){
					cont = 1;
					numRounds++;
					localTime -= 100;
					break;
				} else if (b2 == 1 || b3 == 1 || b4 == 1) {
					failed = 1;
					done = 1;
					break;
				}	
			}
		} else if (randButton == 1){
			int cont = 0;
			scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );
			int initialTime = t;
			printf("Press the circle button\n");
			printf("You have %d milliseconds to respond!\n", localTime);
			while(cont == 0){
				scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );
				if((t - initialTime) > localTime){
					timeUp = 1;
					done = 1;
					break;
				}
				if (b2 == 1){
					cont = 1;
					numRounds++;
					localTime -= 100;
					break;
				} else if (b1 == 1 || b3 == 1 || b4 == 1) {
					failed = 1;
					done = 1;
					break;
				}	
			}
		} else if (randButton == 2){
			int cont = 0;
			scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );
			int initialTime = t;
			printf("Press the x button\n");
			printf("You have %d milliseconds to respond!\n", localTime);
			while(cont == 0){
				scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );
				if((t - initialTime) > localTime){
					timeUp = 1;
					done = 1;
					break;
				}
				scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );
				if (b3 == 1){
					cont = 1;
					numRounds++;
					localTime -= 100;
					break;
				} else if (b2 == 1 || b1 == 1 || b4 == 1) {
					failed = 1;
					done = 1;
					break;
				}	
			}
		} else if (randButton == 3){
			int cont = 0;
			scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );
			int initialTime = t;
			printf("Press the square button\n");
			printf("You have %d milliseconds to respond!\n", localTime);
			while(cont == 0){
				scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );
				if((t - initialTime) > localTime){
					timeUp = 1;
					done = 1;
					break;
				}
				scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );
				if (b4 == 1){
					cont = 1;
					numRounds++;
					localTime -= 100;
					break;
				} else if (b2 == 1 || b3 == 1 || b1 == 1) {
					failed = 1;
					done = 1;
					break;
				}	
			}
		}
		


	}
	}

	
	if (failed == 1){
		printf("\nWrong Button\nYou lose!\nYou made it through %d rounds\n", numRounds);
	}
	
	if (timeUp == 1){
		printf("\nThanks for playing!\n You made it through %d rounds!\n", numRounds);
	}







}

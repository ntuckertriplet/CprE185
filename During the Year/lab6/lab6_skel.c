/*-----------------------------------------------------------------------------
-					          SE 185 Lab 06
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name: Nate Tucker
- Section: B
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
	int completed = 0;
	int random_button;
	int failed = 0;
	int rounds_lasted = 0;
	int time_left = 2500;
	int timeUp = 0;


	/* Prompt the user to begin */
	printf("Press the circle to begin\n");
	int started = 0;
	while (started == 0){
		scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );

		/* If they push the start, otherwise program hangs */
		if (b2 == 1){
			started = 1;
		}
	}

	while (completed == 0) {

		/* Seed random button, and give the options of 0, 1, 2, 3 */
		srand(time(0));
		random_button =  rand() % 4;
		scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );

		if (b1 == 0 && b2 == 0 && b3 == 0  && b4 == 0 ){

			/*Checks for b1 */
			if (random_button == 0){
				int continue = 0;

				/* Set value of starting time */
				int initialTime = t;
				printf("Press the triangle button\n");
				printf("You have %d milliseconds to respond!\n", time_left);
				while(continue == 0 || timeUp == 1){
					scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );

					/* If user time runs out. t grows indefinitely */
					if((t - initialTime) > time_left){
						timeUp = 1;
						completed = 1;
						break;
					}
					if (b1 == 1){

						/* Correct press, leave this loop and restart */
						continue = 1;
						rounds_lasted++;
						time_left -= 100;
						break;

					/* Wrong button press */
					} else if (b2 == 1 || b3 == 1 || b4 == 1) {
						failed = 1;
						completed = 1;
						break;
					}
				}

			/*Checks for b2 */
			} else if (random_button == 1){
				int initialTime = t;
				printf("Press the circle button\n");
				printf("You have %d milliseconds to respond!\n", time_left);
				while(continue == 0){
					scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );

					/* If user time runs out. t grows indefinitely */
					if((t - initialTime) > time_left){
						timeUp = 1;
						completed = 1;
						break;
					}
					if (b2 == 1){

						/* Correct press, leave this loop and restart */
						continue = 1;
						rounds_lasted++;
						time_left -= 100;
						break;

					/* Wrong button press */
					} else if (b1 == 1 || b3 == 1 || b4 == 1) {
						failed = 1;
						completed = 1;
						break;
					}
				}

			/*Checks for b3 */
			} else if (random_button == 2){
				int continue = 0;
				int initialTime = t;
				printf("Press the x button\n");
				printf("You have %d milliseconds to respond!\n", time_left);
				while(continue == 0){
					scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );

					/* If user time runs out. t grows indefinitely */
					if((t - initialTime) > time_left){
						timeUp = 1;
						completed = 1;
						break;
					}
					scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );
					if (b3 == 1){

						/* Correct press, leave this loop and restart */
						continue = 1;
						rounds_lasted++;
						time_left -= 100;
						break;

					/* Wrong button press */
					} else if (b2 == 1 || b1 == 1 || b4 == 1) {
						failed = 1;
						completed = 1;
						break;
					}
				}

			/*Checks for b4 */
			} else if (random_button == 3){
				int continue = 0;
				int initialTime = t;
				printf("Press the square button\n");
				printf("You have %d milliseconds to respond!\n", time_left);
				while(continue == 0){
					scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );

					/* If user time runs out. t grows indefinitely */
					if((t - initialTime) > time_left){
						timeUp = 1;
						completed = 1;
						break;
					}
					scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4 );
					if (b4 == 1){

						/* Correct press, leave this loop and restart */
						continue = 1;
						rounds_lasted++;
						time_left -= 100;
						break;

						/* Wrong button press */
					} else if (b2 == 1 || b3 == 1 || b1 == 1) {
						failed = 1;
						completed = 1;
						break;
					}
				}
			}
		}
	}

	/* If the user failed, i.e. pressed a wrong button */
	if (failed == 1){
		printf("\nYou pressed a wrong button\nYou made it through %d rounds\n", rounds_lasted);
	}

	/* If the user did not press the wrong button, but simply ran out of time */
	if (timeUp == 1){
		printf("\nYou ran out of time\n You made it through %d rounds\n", rounds_lasted);
	}







}

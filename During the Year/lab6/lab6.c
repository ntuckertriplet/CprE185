/*-----------------------------------------------------------------------------
-					          SE 185 Lab 04
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name:
- 	Section:
-	NetID:
-	Date:
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/
#define TRUE 1


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
//scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
int main(void) {
    int t, b1, b2, b3, b4;
	int started = 0;
	int win_game = 0;
	int num_rounds = 0;
	int win_time = 0;
	
	printf("Press triangle to begin:\n");
	scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
	while (b1 == 0) {
		scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
	}
	
	while(win_game == 0){
		srand(time(0));
		int random_button = rand() % 4;
		scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
			
		if(random_button == 0) {
			printf("Press the triangle! You have milliseconds!\n");
			scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
			while(b1 == 0) {
				scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
			}
		}
				
		else if(random_button == 1) {
			printf("Press the circle! You have milliseconds!\n");
			scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
			while(b2 == 0) {
				scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
			}
		}
				
		else if(random_button == 2) {
			printf("Press the x! You have milliseconds!\n");
			scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
			while(b3 == 0) {
				scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
			}
		}
				
		else if(random_button == 3) {
			printf("Press the square! You have milliseconds!\n");
			scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
			while(b4 == 0) {
				scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
			}
		}
	}
	
	printf("YUH");
	

    return 0;
}

/* Put your functions here */

	
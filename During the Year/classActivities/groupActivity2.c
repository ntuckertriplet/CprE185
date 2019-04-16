#include <stdlib.h>
#include <stdio.h>


//Nathan Tucker, Ian Hatlewick, Colton Urbaitis


//recursively find factorial f
int factorial(int f) {
	if (f == 1){
        	return 1;
	} else {
    		return(f * factorial(f - 1));
	}
}


int main() {

	int f;
	printf("Enter a number greater than 1: ");
	scanf("%d", &f);
	printf("%d factorial is: %d\n", f, factorial(f));
	return 0;
}

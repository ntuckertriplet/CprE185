#include <stdio.h>
#include <stdlib.h>

/*
David Luong
Jonathan Huser
Colton Urbaitis
Ian Haltewick
Nate Tucker
*/
int factorial(int f) {
	if (f == 0){
        	return 1;
	} else {
    		return(f * factorial(f - 1));
	}
}


int main(){

	FILE *fp = NULL;

	fp = fopen("read.txt", "r");

	if (fp == NULL){
		printf("sorry my dood");
		exit(0);
	}

	int arr[10];
	int i = 0;

	while(!feof(fp)){
		fscanf(fp, "%d", &arr[i]);
		i++;
	}


	int factor[10];
	for (i = 0; i < 10; i++){
		factor[i] = factorial(arr[i]);
	}

	fclose(fp);

	fp = fopen("read.txt", "w");
	if (fp == NULL){
		printf("sorry my dood, can't write");
		exit(-1);
	}

	for(int j = 0; j < 10; j++){
		fprintf(fp, "%d ", factor[j]);
	}


	return 0;
}

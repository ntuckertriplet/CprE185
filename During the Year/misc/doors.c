#include <stdio.h>

int main(){
	int num_doors;
	printf("pick an n: ");
	printf("\n");
	scanf("%d", &num_doors);
	int doors[num_doors];
	for (int i = 0; i < num_doors; i++){
		doors[i] = 0;
		printf("%d ", doors[i]);
	}
	printf("\n");
	for(int i = 0; i < num_doors; i++) {
		for(int j = i; j < num_doors; j++) {
			if (doors[i] == 1) {
				doors[i] = 0;
			} else if (doors[i] == 0) {
				doors[i] = 1;
			}	
		}
	}
	int open = 0;
	for(int i = 0; i < num_doors; i++){
		if(doors[i] == 1){
			open++;
		}
	}

	printf("Open doors: %d", open);
	printf("\n");
	return 0;
}

#include <stdio.h> 
/*
 * Nate Tucker
 * Colton Urbaitis
 * Ian Haltewick
 * Jonathan Huser
 * David Luong
 */
void swap(int *a, int *b) { 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 
 
void bubbleSort(int arr[], int n) { 
	for (int i = 0; i < n-1; i++){	  
		for (int j = 0; j < n-i-1; j++){ 
			if (arr[j] > arr[j+1]){ 
				swap(&arr[j], &arr[j+1]);
			}
		}	
	}
} 

int main() { 
	int arr[] = {13, 100, 6, 12, 4, 22, 7, 11};
	int size = sizeof(arr)/sizeof(arr[0]);
        printf("Given array: \n");
	for(int i = 0; i < size; i++){
                printf("%d ", arr[i]);
        }
	printf("\n\n");	
	bubbleSort(arr, size); 
	printf("Sorted array: \n"); 
	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");	
	return 0; 
}

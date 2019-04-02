#include <stdio.h>

void printNos(unsigned int n){
    if(n > 0){
        printNos(n - 1);
        printf("%d\n", n);
    }
    return;
}

// Driver code
int main(){
    printNos(1000);
    getchar();
    return 0;
}

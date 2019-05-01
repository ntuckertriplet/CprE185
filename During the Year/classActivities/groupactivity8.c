#include <stdio.h>

/*
Nate Tucker
Ian Haltewick
Colton Urbaitis
David Luong
Jonathan Huser
*/
int recursion(int n){
  if (n == 0 || n == 1){
      return n;
  } else {
      return (recursion(n-1) + recursion(n-2));
  }
}

int itterative(int n){
    int f[100];
    f[0] = 0; f[1] = 1;
    for(int i = 2; i <= n; i++){
      f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

int main(int argc, char* argv[]){
  int recurs = 0;
  int itter = 0;

  printf("Done with loops: \n");
  printf("Enter the number of terms: ");
  scanf("%d", &itter);
  printf("%d\n", itterative(itter));

  printf("Done with recursion: \n");
  printf("Enter the number of terms: ");
  scanf("%d", &recurs);
  printf("%d\n", recursion(recurs));
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float calcAvg(float student[]);

void letterGrade(float average);

int main() {

  float student1[] = {93.5, 78.9, 88.3, 0};
  float student2[] = {87.8, 92.9, 77.3, 0};

  student1[3] = calcAvg(student1);
  student2[3] = calcAvg(student2);

  printf("%f\n", student1[3]);
  printf("%f\n", student2[3]);

  letterGrade(student1[3]);
  letterGrade(student2[3]);

  return 0;
}


float calcAvg(float student[]) {
  float averge_score = 0;
  for (int i = 0; i < 3; i++) {
    averge_score += student[i];
  }


  return averge_score / 3;
}

void letterGrade(float grade) {
  (grade >= 90) ? printf("A\n") :
  (grade >= 80) ? printf("B\n") :
  (grade >= 70) ? printf("C\n") :
  (grade >= 60) ? printf("D\n") :
  printf("F\n");
}

/*
Jacob puetz
Taizhong Huang
Kordell Schrock
Colton Urbaitis
Ian haltewick
*/

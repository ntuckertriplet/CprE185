/*-----------------------------------------------------------------------------
-                             SE 185 Lab 05
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

//needed a prototype of the method
void print_face(int opt);

//needed the standard library for srand
#include <stdlib.h>

//needed stdio for printf
#include <stdio.h>

#include <time.h>

/* This is a simple program that takes a user inputs and prints out a message based on that input */

void hoo();

int main() {
    srand(time(NULL));
    int option = 0;

    printf("Enter 1 for happy, 2 for sad, 3 for neutral, any other integer for random: ");
    scanf("%d", &option);

    if (option < 1 || option > 3) {

       option = rand() % 4;
    }
    print_face(option);

    return 0;
}

void print_face(int opt) {
    if (opt == 1) {
        printf("Have a nice day! :) \n");
    }
    else if (opt == 2) {
        printf(":(\n");
    }
    else if (opt ==3) {
        printf("meh :\\ \n");
    }
    else {
        hoo();
    }
}

void hoo() {
    printf(" *___*\n {O,O}\n/)___)\n_\"__\"_\n");
}

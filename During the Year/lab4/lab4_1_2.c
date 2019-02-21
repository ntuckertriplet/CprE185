/*-----------------------------------------------------------------------------
-                             SE 185 Lab 05
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/
#include <stdio.h>
/* This program takes two inputs acceleration
    and mass, and ouputs the force = mass*acceleration */

void force(double m, double accel);

int main() {
    double mass;
    //accel never initialized
    int accel;

    printf("Enter an acceleration: ");
    scanf("%d", &accel);

    printf("Enter the mass of the object: ");
    //was originally scanning for an int, mass is declared as a double
    scanf("%lf", &mass);

    force(mass, accel);

    //accel is an int, print statement was looking for double
    printf("You entered %d m/s^2\n", accel);
    printf("You entered %lf kg\n", mass);

    return 0;
}

void force(double m, double accel) {
    
    //mass never initialized
    double mass;
    mass = m / 1000;

    printf("The force is %lf milliNewtons\n", mass * accel);

    accel = accel*1000;

    printf("The force is %lf Newtons\n\n", mass * accel);
}

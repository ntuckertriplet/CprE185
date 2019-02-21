/*-----------------------------------------------------------------------------
-                             SE 185 Lab 05
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/* This program calculates the energy of one photon of uder inputed wavelength
 * of light */

int main()
{
    //no ! in variable names
    double speed_light;
    
    //can't have - in variable name
    double waveLength;

    //no tilde in front of variable names
    double length_in_meters;

    //not allowed to have variable names that are two seperate words
    double planck_const;

    //not allowed to start variables with a number
    double energy;

    planck_const = (6.62606957)*(pow(10,-34)); //Planck's constant
    speed_light = (2.99792458)*(pow(10,8)); //Constant for the speed of light
    waveLength = 0;
    length_in_meters = 0;
    energy = 0;

    printf("Welcome! This program will give the energy, in Joules,\n");
    printf("of 1 photon with a certain wavelength.\n");
    printf("Please input a wavelength of light in nano-meters.\n");
    printf("Please do not enter a negative, or zero, wavelength.\n");

    scanf("%lf", &waveLength);

    if (waveLength > 0.0)
    {
        length_in_meters = waveLength / pow(10,9); //Converting nano-meters to meters
        energy = (planck_const*speed_light) / (length_in_meters); //Calculating the energy of 1 photon
        printf("A photon with a wavelength of %08.3lf nano-meters, carries\n%030.25lf joules of energy.", waveLength, energy);
    }
    else
    {
        printf("Sorry, you put in an invalid number.");
        printf("Please rerun the program and try again.");
    }

    return 0;

}

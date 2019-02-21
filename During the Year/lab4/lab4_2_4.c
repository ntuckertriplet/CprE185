/*-----------------------------------------------------------------------------
-                             SE 185 Lab 05
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/
#include <stdio.h>

/* This program calculates values of resistances, voltages, or current
 * using Ohm's Law */

double voltage(double resistance, double current);

double resistance(double voltage, double current);

double current(double voltage, double resistance);

int main()
{
    int select = 0;
    int v, i, r;

    printf("Select:\n1 for voltage\n2 for resistance\n3 for current\n");

    scanf("%d", &select);

    if(select > 3 || select < 1)
    {
        printf("Invalid number\n");
        return -1;
    }

    printf("Enter floating point numbers for input...\n");
    if(select == 1)
    {
        printf("Please enter a resistance value: ");

    	//was looking for a double when r was declared as int
        scanf("%d", &r);

        printf("Please enter a current value: ");

	//same as above
        scanf("%d", &i);

        printf("Your voltage is: %lf Volts\n", voltage(r, i));
    }
    else if(select == 2)
    {
        printf("Please enter a voltage value: ");

	//same as above, wrong type
        scanf("%d", &v);

        printf("Please enter a current value: ");

	//same as above
        scanf("%d", &i);

        printf("Your Resistance is: %lf Ohms\n", resistance(v, i));

    }
    else if(select == 3)
    {
        printf("Please enter a resistance value: ");

	//WOW ITS THE SAME
        scanf("%d", &r);

        printf("Please enter a voltage value: ");

	//YOU GUESSED IT
        scanf("%d", &v);

        printf("Your current is: %lf Amps\n", current(v, r));


    }

    return 0;

}





double voltage(double resistance, double current)
{
    return resistance * current;
}

double resistance(double voltage, double current)
{
    return voltage / current;
}

double current(double voltage, double resistance)
{
    return voltage / resistance;
}

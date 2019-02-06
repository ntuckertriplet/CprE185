#include <stdio.h>
#define M_PI 3.14159265358979323846
int main(){
	int a, b, c;
	double x, y, z;
	a = 6427;
	b = 1725;
	printf("%d + %d = %d/n", a, b, a + b);

	a = 6971;
	b = 3925;
	c = 95;
	printf("(%d * %d) - %d = %d/n", a, b, c, (a * b) – c);

	x = 79;
	y = 12;
	z = 5;
	printf("%lf + %lf / %lf = %lf/n", x, y, z, x + y / z);

	x = 3640.0;
	y = 107.9;
	printf("%lf /" %lf = %lf/n", x, y, x / y);

	a = 22;
	b = 3;
	printf("(%d /" %d) * %d = %d/n", x, y, y, (x / y) * y);

	printf("%d /" (%d * %d) = %d/n", x, y, y, x / (y * y));

	x = 22;
	y = 3;
	printf("%lf /" (%lf * %lf) = %lf/n", x, y, y, x / (y * y));

	printf("%lf /" %lf * %lf = %lf/n", x, y, y, x / y * y);

	x = 22.0;
	y = 3;
	z = 3.0;
	printf("(%lf /" %lf) * %lf/n", x, y, z, (x / y) * z);

	printf("%d/n", 22.0 / (3 * 3.0));
	printf("%lf/n", 22.0 / 3.0 * 3.0);


	/*
	The area of a circle is given by the formula A = π*r^2,
	where A is the area and r is the radius.
	The circumference of a circle is C = 2πr.
	If we "solve for r" in the second equation,
	we have r = C/(2π). Now we use this to
	replace r in the first equation: A = π[C/(2π)]2.
	When we simplify this, we get A = C^2/(4 π).
	*/
	double circumference = 23.567;
	printf("%lf",(circumference * circumference)/(4*M_PI));

	/*
	Feet to meters is 1 foot for every .3048 meters
	*/
	double givenFeet = 14;
	printf("%lf", givenFeet * .3048);

	/*
	Given Fahrenheit, convert to Celsius
	*/
	double givenF = 76;
	printf("%lf", (givenF - 32) / 1.8):
	return 0;
}

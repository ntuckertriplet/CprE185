#include <stdio.h>
#define M_PI 3.14159265358979323846
int main(){

	int a = 6427 + 1725;
	int b = (6971 * 3925) - 95;
	double c = 79 + 12 / 5;
	double d = 3640.0 / 107.9;
	int e = (22 / 3) * 3;
	int f = 22 / (3 * 3);
	double g = 22 / (3 * 3);
	double h = 22 /  3* 3;
	double i = (22.0 / 3) * 3.0;
	int j = 22.0 / (3 * 3.0);
	double k = 22.0 / 3.0 * 3.0;

	printf("a = %d\nb = %d\nc = %lf\nd = %lf\ne = %d\nf = %d\ng = %lf\nh = %lf\ni = %lf\nj = %d\nk = %lf\n", a, b, c, d, e, f, g, h, i, j, k);

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
	printf("Area of a circle with %lf circumference is %lf\n", circumference, (circumference * circumference)/(4*M_PI));

	/*
	Feet to meters is 1 foot for every .3048 meters
	*/
	double givenFeet = 14;
	printf("14 feet in meters is %lf\n", givenFeet * .3048);

	/*
	Given Fahrenheit, convert to Celsius
	*/
	double givenF = 76;
	printf("76 degrees in Fahrenheit is %lf in Celsius\n", (givenF - 32) / 1.8);
	return 0;
}

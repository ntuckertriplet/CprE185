#include <stdio.h>
int main(){
	printf("%d/n", 6427 + 1725);
	printf("%d/n", (6971 * 3925) – 95);
	printf("%lf/n", 79 + 12 / 5);
	printf("%lf/n", 3640.0 / 107.9);
	printf("%d/n", (22 / 3) * 3);
	printf("%d/n", 22 / (3 * 3));
	printf("%lf/n", 22 / (3 * 3));
	printf("%lf/n", 22 / 3* 3);
	printf("%lf/n", (22.0 / 3) * 3.0);
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
	return 0;
}

#include <stdio.h> //scanf(), printf()
#include <math.h> //cosf(), sinf(), M_PI
#include <string.h>
#include <ctype.h>

int main()
{

	//4 - table znach
	//5 - save in file and method bisection (бисекции)
	//the projectile falls need to find time and coords
	float x0, y0; //coords of weapon
	float v0; //start speed of projectile
	float a; //projectile departure angle

	printf("x0: ");
	//INPUT
	scanf("%f", &x0); //scanf x0
	printf("y0: ");
	scanf("%f", &y0); //scanf y0
	printf("v0: ");
	scanf("%f", &v0); //scanf start speed
	printf("a: ");
	scanf("%f", &a); //scanf angle

	//angle in radian
	float ra = a * (float) M_PI / 180.0f;

	//speed of projectile
	float v0x = cosf(ra) * v0;
	float v0y = sinf(ra) * v0;

	float g = 9.8f; //gravity (or something)
	//FORMULAS
	//float x = x0 + v0x * t;
	//float y = y0 + v0y * t - g * t * t / 2.0f;

	float d = v0y * v0y + 4 * g / 2.0f * y0; //discriminant
	printf("d = %f\n", d);

	float x1 = (-v0y - sqrt(d)) / (2.0f * (-g / 2.0f));
	float x2 = (-v0y + sqrt(d)) / (2.0f * (-g / 2.0f));
	printf("x1 = %f\tx2 = %f\n", x1, x2);

	float t = 0.0f;
	float eps = 0.01f;
	float x, y;
	printf("eps = %f\n", eps);

	//TABLE
	printf("|\tt\t|\tx\t|\ty\t|\n");
	while (1)
	{
		x = x0 + v0x * t;
		y = y0 + v0y * t - g * t * t / 2.0f;
		printf("|%f\t|%f\t|%f\t|\n", t, x, y);
		if (y <= 0.0f) break;
		t += eps;
	}




	return 0;
}

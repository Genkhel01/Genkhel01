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

	float t1 = (-v0y - sqrt(d)) / (2.0f * (-g / 2.0f));
	float t2 = (-v0y + sqrt(d)) / (2.0f * (-g / 2.0f));
	printf("t1 = %f\tt2 = %f\n", t1, t2);

	float eps = 0.01f;
	printf("eps = %f\n", eps);

	//TABLE
	float t = 0.0f;
	float ta, tb; //Borders
	float x; float y;
	FILE *f = freopen("exam03-c.txt", "w", stdout);
	printf("|\tt\t|\tx\t|\ty\t|\n");
	while (1)
	{
		//t - is not const
		x = x0 + v0x * t;
		y = y0 + v0y * t - g * t * t / 2.0f;
		tb = t;
		printf("|%f\t|%f\t|%f\t|\n", t, x, y);
		if (y <= 0.0f) break;
		ta = t;
		t += eps;
	}

	printf("|\tya\t|\tyc\t|\tyb\t|\n");
	float yb, ya, yc;
	float tc; //the time what we find
	while (1)
	{
		tc = 0.5f * (tb + ta);
		//calculate the height of the projectile in times: a,b,c
		ya = y0 + v0y * ta - g * ta * ta / 2.0f;
		yc = y0 + v0y * tc - g * tc * tc / 2.0f;
		yb = y0 + v0y * tb - g * tb * tb / 2.0f;
		printf("|%f\t|%f\t|%f\t|\n", ya, yc, yb);
		if (yc == 0.0f) break;
		if (yb * yc > 0.0f) tb = tc;
		else ta = tc;
	}
	float xc = x0 + v0x * tc;

	printf("\ntime = %f\n", tc);
	printf("y = %f\n", yc);
	printf("x = %f\n", xc);
	fclose(f);
	return 0;
}

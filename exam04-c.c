#include <stdio.h>
#include <math.h>

double f(double x)
{
  return -3.0f * cosf(x);
}

int main()
{

  // solving a nonlinear equation by the half division method
  // calculation as a function
  // 4 - display the steps of the execution element,
  // specify the number of steps, check
  // 5 - all intermediate and final calculations to a file

  double a, b;
  printf("a, b: ");
  scanf("%lf %lf", &a, &b);

  double eps; //epsilon
  printf("eps: ");
  scanf("%lf", &eps);

  FILE *theFile = freopen("exam04-c.txt", "w", stdout);
  int iteration = 1;
  while (1)
  {
    double c = 0.5*(a + b); //center
    double fa = f(a);
    double fc = f(c);
    double fb = f(b);
    printf("\t%d\n", iteration);
    printf("%lf %lf %lf %lf %lf %lf\n", a, b ,c ,fa, fc, fb);

    if (fabs(fc) <= eps)
    {
      printf("iteration: %d\n", iteration);
      printf("x: %lf\n", c);
      printf("y: %lf\n", fc);
      break;
    }

    if(fa*fc > 0.0f) a = c;
    else  b = c;

    iteration++;
  }

  fclose(theFile);
  return 0;
}

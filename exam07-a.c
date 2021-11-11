#include <stdio.h>
#include <stdlib.h>

#define n_max 100

int n;
int mmax, mmin;
int mark[n_max];
//int *mark; //na 5
char randMarks;
#define mmin 2
#define mmax 5
#define mpass 4.6f

int calculatingCertificate()
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  sum += mark[i];
  float avg = (float) sum / (float) n;
  printf("avg: %.1f\n", avg);
  if (avg >= mpass)
  printf("yes\n");
  else
  printf("no\n");
}

//проходной бал - 4.6
//4 - отдельные функции высичления атестата
//5 - для обработки использовать динамический одномерный массив

int main()
{
  printf("Кол-во оценок: ");
  scanf("%d", &n);

  //mark = (int *) malloc(n * sizeof(int)); //na 5

  printf("Задать оценки случайно?\nY/N: ");
  scanf("%s", &randMarks);
  if(randMarks == 'y' || randMarks == 'Y')
  {
    for(int i = 0; i < n; i++)
    {
      mark[i] = mmin + rand() % (mmax - mmin + 1);
      printf("%d ", mark[i]);
    }
    printf("\n");
  }
  else
  {
    printf("Введите оценки:");
    for(int i = 0; i < n; i++)
    {
      scanf("%d", &mark[i]);
      if(mark[i]<mmin)
      {
        printf("Error\n");
        return 0;
      }
      if(mark[i]>mmax)
      {
        printf("Error\n");
        return 0;
      }
    }
  }

  //calculatingCertificate(); //na 4

  int sum = 0;
  for (int i = 0; i < n; i++)
  sum += mark[i];
  float avg = (float) sum / (float) n;
  printf("avg: %.1f\n", avg);
  if (avg >= mpass)
  printf("yes\n");
  else
  printf("no\n");


  //free(mark); //na 5

  return 0;


}

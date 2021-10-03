#include <stdio.h>
#include <stdlib.h>

#define min 740
#define max 780
#define norm 760
#define days 31
int press[31];

int main()
{

  int daysBelow = 0;
  int daysAbove = 0;
  int daysExact = 0;

  //Fill days
  for (int i = 0; i < days; i++)
  {
    press[i] = min + rand() % (max - min + 1);
  }
  //Print days
      printf("NumDay\t|Pressure\t|NumDay\t\t|Pressure\t|\n");
  for (int i = 0; i < 15; i++)
      printf("%d\t|\t%d\t|\t%d\t|\t%d\t|\n", i + 1, press[i], i + 1 + 15, press[i + 15]);
  if (days > 30)
      printf(" \t|\t \t|\t%d\t|\t%d\t|\n", 30 + 1, press[30]);

  for (int i = 0; i < days; i++)
  {
    int v = press[i];
    if (v < norm)
      daysBelow++;
    else if (v > norm)
      daysAbove++;
    else
      daysExact++;
  }

  printf("below:\t%d\n", daysBelow);
  printf("above:\t%d\n", daysAbove);
  printf("exact:\t%d\n", daysExact);

  return 0;
}

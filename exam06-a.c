#include <stdio.h>
#include <stdlib.h>

#define min 740
#define max 760
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
      print("NumDay\t|\tPressure");
  for (int i = 0; i < days; i++)
    printf("%d\t|\t%d\n", i + 1, press[i]);

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

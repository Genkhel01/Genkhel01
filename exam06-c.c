#include <stdlib.h>
#include <stdio.h>
#include <linux/limits.h>

#define min 740
#define max 780
#define norm 760
#define days 31
int press[31];

int sortArray(int *num, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = size - 1; j > i; j--)
    {
      if (num[j - 1] > num[j])
        {
          int save = num[j-1];
          num[j-1] = num[j];
          num[j] = save;
        }
    }
  }
}

int main()
{

  int daysBelow = 0;
  int daysAbove = 0;
  int daysExact = 0;
  int dayDel;
  scanf("%d", &dayDel);
  dayDel--;

  struct day
  {
    int Number[days];
    int Press[days];
    int Del[days];
  };

  //Fill days
  for (int i = 0; i < days; i++)
  {
    day.Press[i] = min + rand() % (max - min + 1);
  }

  for (int i = 0; i < days; i++)
  //Delete the day
  if (i == dayDel)
    day.Press[i] = -1;

  //Sorting Array
  sortArray(day.Press, days);


  //Print days
      printf("NumDay\t|Pressure\t|NumDay\t|Pressure\t|\n");
  for (int i = 0; i < 15; i++)
  {
    if (i != dayDel)
      printf("%d\t|\t%d\t|", i + 1, day.Press[i]);
    else
      printf("%d\t|\tdel\t|", i + 1);
    if (i + 15 != dayDel)
      printf("%d\t|\t%d\t|\n", i + 1 + 15, day.Press[i + 15]);
    else
      printf("%d\t|\tdel\t|\n", i + 1 + 15);
  }
  if (days > 30)
    if (dayDel != 30)
      printf(" \t|\t \t|%d\t|\t%d\t|\n", 30 + 1, day.Press[30]);
    else
      printf(" \t|\t \t|%d\t|\tdel\t|\n", 30 + 1);

  //Comparison
  for (int i = 0; i < days; i++)
    if (i != dayDel)
  {
    int v = day.Press[i];
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

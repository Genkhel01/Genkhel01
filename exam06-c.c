#include <stdio.h>
#include <stdlib.h>

int daysSort(int *press, int *dayN, int length)
{
  for (int i = 0; i < length - 1; i++)
    for (int j = length - 1; j > i; j--)
      if (press[j - 1] > press[j])
      {
        int savePress = press[j-1];
        press[j-1] = press[j];
        press[j] = savePress;

        int saveDate = dayN[j-1];
        dayN[j-1] = dayN[j];
        dayN[j] = saveDate;
      }
}

int main()
{
  #define min 740
  #define max 780
  #define norm 760
  #define days 31
  int press[31];
  int dayNum[31];

  //Scan dayDel
    int dayDel;
    printf("Day Delete: ");
    scanf("%d", &dayDel);
    dayDel--;

  //Fill days
    for (int i = 0; i < days; i++)
    {
      press[i] = min + rand() % (max - min + 1);
      dayNum[i] = i + 1;
      //Delete the day
        if (i == dayDel)
          press[i] = -1;
    }

  //Sort day's pressure
    daysSort(press, dayNum, days);

  //Print days
    printf("|NumDay\t|Pressure\t|NumDay\t|Pressure\t|\n");
    for (int i = 0; i < 15; i++)
    {
      if (press[i] != -1)
          printf("|%d\t|\t%d\t|", dayNum[i], press[i]);
      else
          printf("|%d\t|\tdel\t|", dayNum[i]);
      if (press[i+15] != -1)
          printf("%d\t|\t%d\t|\n", dayNum[i+15], press[i+15]);
      else
          printf("%d\t|\tdel\t|\n", dayNum[i+15]);
    }
    if (days > 30)
      if (press[30] != -1)
        printf(" \t|\t \t|%d\t|\t%d\t|\n", dayNum[30], press[30]);
      else
        printf(" \t|\t \t|%d\t|\tdel\t|\n", dayNum[30]);

  //Comparison
    int daysBelow = 0;
    int daysAbove = 0;
    int daysExact = 0;
    for (int i = 0; i < days; i++)
      if (press[i] != -1)
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

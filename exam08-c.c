#include <stdio.h>
#include <stdlib.h>

int main()
{

	//общая  сумма ЗП за год
	//средняя ЗП за год
	//отчисления в пенс фонд - 2% от ежемес ЗП
	//отчисления в пенс фондд по месяцам
	//отчисления в пенс фондд за год
	//4 - отклонения ежемес ЗП от средней ЗП за год
	//5 - макс и мин ЗП с номерами месяцев
	
	int months = 12;
	int stonks[months];
	int stonks_low = 1000;
	int stonks_high = 5000;
	float tax[months];

	//charge stonks and taxs
	for(int i = 0; i < months; i++)
	{
		stonks[i] = stonks_low + rand() % (stonks_high - stonks_low + 1);
		tax[i] = (float)(stonks[i] * 0.02f);
	}

	//calculating the stonks year sum
	int stonksYear = 0;
	for(int i = 0; i < months; i++)
	stonksYear += stonks[i];

	//calculating average year stonks
	float stonksYearAverage = stonksYear / (float) months;

	//calculating deviation
	//float dev = (flaot)stonks / stonksYearAverage;

	//output stonks and taxs
	printf("|month\t|salary\t|deviation\t|tax\t|\n");
	for(int i = 0; i < months; i++)
	{
		printf("|%d\t|", (i+1));//month
		printf("%d\t|", stonks[i]);//stonks
		printf("\t%.1f%\t|", ((float)stonks[i] / stonksYearAverage)*100.0f);//deviation
		printf("%.1f\t|\n", tax[i]);//tax
	}

	//calculating the year taxs
	float taxYear = 0;
	for (int i = 0; i < months; i++)
	taxYear += tax[i];
	printf("Year tax = %.2f\n", taxYear);

	//output the stonks year sum
	printf("Year salary = %d\n", stonksYear);

	//output average year stonks
	printf("Average salary = %.2f\n", stonksYearAverage);

	int temp;
	int stonksMin = 0;
	int stonksMax = 0;
	for(int i = 0; i < months - 1; i++)
	for(int j = 0; j < months - i - 1; j++)
	{
		if(stonks[j] > stonks[j+1])
		{
			temp = stonks[j];
			stonks[j] = stonks[j+1];
			stonks[j+1] = temp;
		}
	}

	printf("Min = %d\n", stonks[0]);
	printf("Max = %d\n", stonks[months-1]);


	return 0;
}

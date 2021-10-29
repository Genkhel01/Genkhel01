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
	printf("|\tmonth\t|\tsalary\t|\ttax\t|\n");
	for(int i = 0; i < months; i++)
	{
		stonks[i] = stonks_low + rand() % (stonks_high - stonks_low + 1);
		tax[i] = (float)(stonks[i] * 0.02f);
		printf("|\t%d\t|", (i+1));//month
		printf("\t%d\t|", stonks[i]);//stonks
		printf("\t%.1f\t|\n", tax[i]);//tax
	}

	//calculating the year taxs
	float taxYear = 0;
	for (int i = 0; i < months; i++)
	taxYear += tax[i];
	printf("Year tax = %.2f\n", taxYear);

	//calculating the stonks year sum
	int stonksYear = 0;
	for(int i = 0; i < months; i++)
	stonksYear += stonks[i];
	printf("Year salary = %d\n", stonksYear);

	//calculating average year stonks
	float stonksYearAverage = stonksYear / (float) months;
	printf("Average salary = %.2f\n", stonksYearAverage);


	return 0;
}

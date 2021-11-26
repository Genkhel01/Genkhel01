#include <stdlib.h>
#include <stdio.h>

int numOfMarks = 10;
int mark0 = 1;
int mark1 = 10;

float centerMark()
{
	//printf("%d\t", );
	int theMark[numOfMarks];
	float cMark = 0;
	for(int i = 0; i < numOfMarks; i++)
	theMark[i] = mark0 + (rand() % (mark1 - mark0 + 1));

	for(int i = 0; i < numOfMarks; i++)
	{
		printf(" %d", theMark[i]);
		cMark += theMark[i];
	}

	printf(" %.2f", (float)cMark/(float)mark1);
	printf("\n");

	return (float)cMark/(float)mark1;
}

int main()
{

	//средняя оценка пяти спортсменов от 1-10
	//расчитать среднюю оценку каждого спортсмена
	//4 - спортсмен с максимальной средней оценкой
	//5 - использовать двойной массив

	int numOfSportsmans = 5;
	int sportsman[numOfSportsmans];
	float meanMarks[numOfSportsmans];
	float maxMarks = -1.0;
	
	printf("  ");
	for(int i = 0; i < numOfMarks; i++)
	printf("%d ", i+1);
	printf("\n");

	for(int i = 0; i < numOfSportsmans; i++)
	{
        printf("%d", i+1);
        meanMarks[i] = centerMark();
				if(meanMarks[i] >= maxMarks)
				maxMarks = meanMarks[i];
	}

	for(int i = 0; i < numOfSportsmans; i++)
		if(meanMarks[i] == maxMarks)
			printf("\n%d sportsman is the better\n", i+1);



	return 0;
}

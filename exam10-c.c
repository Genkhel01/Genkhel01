#include <stdlib.h>
#include <stdio.h>

int numOfMarks = 10;
int mark0 = 1;
int mark1 = 10;

/*float centerMark(int x)
{
int theMark[numOfMarks];
float cMark = 0;
for(int i = 0; i < numOfMarks; i++)
theMark[i] =;



printf(" %.2f", (float)cMark/(float)mark1);
printf("\n");

return (float)cMark/(float)mark1;
}*/

int main()
{

	//средняя оценка пяти спортсменов от 1-10
	//расчитать среднюю оценку каждого спортсмена
	//4 - спортсмен с максимальной средней оценкой
	//5 - использовать двойной массив

	int numOfSportsmans = 5;
	int sportsman[numOfSportsmans][numOfMarks+1];
	float meanMarks[numOfSportsmans];
	float maxMarks = -1.0;

	//printf("  ");
	for(int i = 0; i < numOfMarks; i++)
	{
		printf("\t%d", i+1);
	}
	printf("\n");

	for(int i = 0; i < numOfSportsmans; i++)
	{
		printf("%d", i+1);
		//int cMark = 0;
		sportsman[i][numOfMarks] = 0;
		for(int j = 0; j < numOfMarks; j++)
		{
			sportsman[i][j] =  mark0 + (rand() % (mark1 - mark0 + 1));
			printf("\t%d", sportsman[i][j]);
			sportsman[i][numOfMarks] += sportsman[i][j];
		}

		printf("\t%.2f", (float)sportsman[i][numOfMarks]/(float)mark1);
		printf("\n");

		//sportsman[i][numOfMarks] = sportsman;
		if(sportsman[i][numOfMarks] >= maxMarks)
		{
			maxMarks = sportsman[i][numOfMarks];
		}
	}

	for(int i = 0; i < numOfSportsmans; i++)
	if(sportsman[i][numOfMarks] >= maxMarks)
	printf("\nsportsman number %d is the better\n", i+1);



	return 0;
}

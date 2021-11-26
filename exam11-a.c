#include <stdlib.h>
#include <stdio.h>


/*float centerMark(int x)
{
int theMark[numOfSubject];
float cMark = 0;
for(int i = 0; i < numOfSubject; i++)
theMark[i] =;



printf(" %.2f", (float)cMark/(float)mark1);
printf("\n");

return (float)cMark/(float)mark1;
}*/

int main()
{

	//na 3 - "В группе 25 студентов информация о результатах
	//сессии представлена в виде таблицы в которой строки это оценки по
	// 5-ой системе, информация представлена массивом 25 на 5,
	//заполнить случайным образом, для каждого предмета рассчитать средний балл"
	//na 4 - "Дополнительно указать предмет который хуже всего был сдан по среднему баллу"
	//na 5 - "Для каждого предмета указать кол-во двоек, троек, четверок и пятерок"

	int numOfStudents = 25;
	int numOfSubject = 5;
	int mark0 = 2;
	int mark1 = 5;
	//int student[numOfStudents][numOfSubject+1];
	int student[numOfStudents][numOfSubject];
	float meanMarks[numOfSubject];

	//printf("  ");
	for(int i = 0; i < numOfSubject; i++)
	{
		printf("\t%d", i+1);
	}
	printf("\n");

	for(int i = 0; i < numOfStudents; i++)
	{
		printf("%d", i+1);
		//int cMark = 0;
		//student[i][numOfSubject] = 0;
		for(int j = 0; j < numOfSubject; j++)
		{
			student[i][j] =  mark0 + (rand() % (mark1 - mark0 + 1)); //mark for subject j
			printf("\t%d", student[i][j]);
			meanMarks[j] += student[i][j];
		}
		printf("\n");
	}

	float minMarks = -1.0;
	printf("avg:");
	for(int i = 0; i < numOfSubject; i++)
	{
		printf("\t%.2f", i, meanMarks[i]/(float)numOfStudents);

		if(meanMarks[i] <= minMarks)
		{
			minMarks = student[i][numOfSubject];
		}
	}

	//for(int i = 0; i < numOfSubject; i++)
	//if(meanMarks[i] <= minMarks)
	//printf("subject number %d is the worse\n", i+1);

	return 0;
}

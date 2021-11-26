#include <stdlib.h>
#include <stdio.h>

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
		meanMarks[i] = 0;
	}
	printf("\n");

	for(int i = 0; i < numOfStudents; i++)
	{
		printf("%d", i+1);
		//int cMark = 0;
		for(int j = 0; j < numOfSubject; j++)
		{
			student[i][j] =  mark0 + (rand() % (mark1 - mark0 + 1)); //mark for subject j
			printf("\t%d", student[i][j]);
			meanMarks[j] += student[i][j];
		}
		printf("\n");
	}

	int minMarks = (mark1+1)*numOfStudents;
	printf("avg:");
	for(int i = 0; i < numOfSubject; i++)
	{
		printf("\t%.2f", (float)meanMarks[i]/(float)numOfStudents);
		if(meanMarks[i] <= minMarks)
		{
			minMarks = meanMarks[i];
		}
	}
	printf("\n");

	for(int i = 0; i < numOfSubject; i++)
	if(meanMarks[i] <= minMarks)
	printf("subject number %d is the worse\n", i+1);

	//printf("AAAA");

	return 0;
}

#include <stdlib.h>
#include <stdio.h>

struct Subject
{
	int mark[4]; //2, 3, 4, 5
};

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
	struct Subject a[numOfSubject];

	//printf("  ");
	for(int i = 0; i < numOfSubject; i++)
	{
		printf("\t%d", i+1);
		meanMarks[i] = 0;
		a[i].mark[0] = 0;
		a[i].mark[1] = 0;
		a[i].mark[2] = 0;
		a[i].mark[3] = 0;
	}
	printf("\n");

	for(int i = 0; i < numOfStudents; i++)
	{
		printf("%d", i+1);
		//int cMark = 0;
		for(int j = 0; j < numOfSubject; j++)
		{
			student[i][j] =  mark0 + (rand() % (mark1 - mark0 + 1)); //mark for subject j
			if(student[i][j] == 2) a[j].mark[0]++;
			else if(student[i][j] == 3) a[j].mark[1]++;
			else if(student[i][j] == 4) a[j].mark[2]++;
			else if(student[i][j] == 5) a[j].mark[3]++;
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
	printf("\n\n");
	
	for(int i = 0; i < numOfSubject; i++)
	if(meanMarks[i] <= minMarks)
	printf("subject number %d is the worse\n", i+1);

	printf("\n\t2\t3\t4\t5");

	for(int i = 0; i < numOfSubject; i++)
	{
	    printf("\n%d", i+1);

	    for(int j = 0; j < 4; j++)
	    printf("\t%d", a[i].mark[j]);
	}

	return 0;
}

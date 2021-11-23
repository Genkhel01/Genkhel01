

#include <stdlib.h> // atoi(), atof()
#include <stdio.h>
#include <string.h> // strcmp(), strtok()

int main();

//#define rows 3
int rows = 3;
struct record
{
	int acc;
	char fio[32];
	float sum;
	int prc;
	float res;
};
struct record tab[3];

int findRowPrc(int thePrc)
{
	int rowsFinded = 0;
	for(int i = 0; i < rows; i++)
	if(thePrc == tab[i].prc)
	{
		printf("%d\t%s\t%.2f\t%d\t%.2f\n", tab[i].acc, tab[i].fio,
		tab[i].sum, tab[i].prc, tab[i].res);
		rowsFinded++;
	}
	if(rowsFinded < 1)
	printf("No find\n");
	return 0;
}

int findRowAcc(int theAcc)
{
	int rowsFinded = 0;
	for(int i = 0; i < rows; i++)
	if(theAcc == tab[i].acc)
	{
		printf("%d\t%s\t%.2f\t%d\t%.2f\n", tab[i].acc, tab[i].fio,
		tab[i].sum, tab[i].prc, tab[i].res);
		rowsFinded++;
	}
	if(rowsFinded < 1)
	printf("No find\n");
	return 0;
}

int findRowFio(char *theFio)
{
	int rowsFinded = 0;
	for(int i = 0; i < rows; i++)
	{
		char *lastNameFromFIO = strtok(tab[i].fio, " "); //read anytil " "
		if (strcmp(lastNameFromFIO, theFio) == 0) //FIO
		{
			printf("%d\t%s\t%.2f\t%d\t%.2f\n", tab[i].acc, tab[i].fio,
			tab[i].sum, tab[i].prc, tab[i].res);
			rowsFinded++;
		}
	}
	if(rowsFinded < 1)
	printf("No find\n");
	return 0;
}


int main()
{
	char tmp[32];
	for(int i = 0; i < rows; i++)
	{
		printf("[record %d]\n", i);

		printf("acc: ");
		gets(tmp);
		tab[i].acc = atoi(tmp);

		printf("fio: ");
		gets(tab[i].fio);

		printf("sum: ");
		gets(tmp);
		tab[i].sum = atof(tmp);

		printf("%%: ");
		gets(tmp);
		tab[i].prc = atoi(tmp);

		printf("\n");
	}

	for(int i = 0; i < rows; i++)
	tab[i].res = tab[i].sum + (tab[i].sum * tab[i].prc / 100.0f) / 12.0f;

	for(int i = 0; i < rows; i++)
	printf("%d\t%s\t%.2f\t%d\t%.2f\n", tab[i].acc, tab[i].fio, tab[i].sum, tab[i].prc, tab[i].res);
	//na 4
	int whatFind;
	printf("  1    2\n");
	printf("[ACC][FIO]\n");
	scanf("%d", &whatFind);
	if(whatFind == 1)
	{
		int findAcc;
		printf("Find acc: ");
		scanf("%d", &findAcc);
		//		gets(tmp);
		//		findAcc = atoi(tmp);
		findRowAcc(findAcc);
	}
	else if(whatFind == 2)
	{
		char findFio[32];
		printf("Find fio: ");
		scanf("%s", &findFio);
		//gets(findFio);
		findRowFio(findFio);
	}
	else
	printf("Not in menu\n");

	int findPrc;
	printf("Find prc: ");
	scanf("%d", &findPrc);
	findRowPrc(findPrc);

	return 0;

}

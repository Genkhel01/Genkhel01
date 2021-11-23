

#include <stdio.h>
#include <string.h> // strcmp(), strtok()

struct record
{
	char FIO[32];
	char category[48];
	char number[24];
	char info[64];
};

#define numOfRows 3
struct record tab[numOfRows];

int main()
{
	for (int i = 0; i < numOfRows; i++)
	{
		printf("[record %d]\n", i);

		printf("FIO: ");
		gets(tab[i].FIO);

		printf("category: ");
		gets(tab[i].category);

		printf("number: ");
		gets(tab[i].number);

		printf("info: ");
		gets(tab[i].info);

		printf("\n");
	}

	for (int i = 0; i < numOfRows; i++)
	printf("%s\t%s\t%s\t%s\n", tab[i].FIO, tab[i].category, tab[i].number, tab[i].info);

	printf("search LastName: ");
	char FIO[32];
	gets(FIO);
	printf("\n");

	int findedRows = 0;
	for (int i = 0; i < numOfRows; i++)
	{
		char *lastNameFromFIO = strtok(tab[i].FIO, " "); //read anytil " "
		if (strcmp(lastNameFromFIO, FIO) == 0)
		{
			printf("number: %s\n", tab[i].number);
			printf("info: %s\n", tab[i].info);
			findedRows++;
		}
	}
	if(findedRows < 1) printf("not fount laste name\n");

	return 0;

}

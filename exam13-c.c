

#include <stdio.h>
#include <string.h> // strcmp(), strtok()
#include <ctype.h>

struct record
{
	char FIO[32];
	char category[48];
	char number[24];
	char info[64];
};

#define numOfRows 3
struct record row[numOfRows];

int main()
{
	for (int i = 0; i < numOfRows; i++)
	{
		printf("[record %d]\n", i);

		printf("FIO: ");
		gets(row[i].FIO);

		printf("category: ");
		gets(row[i].category);

		printf("number: ");
		gets(row[i].number);

		printf("info: ");
		gets(row[i].info);

		printf("\n");
	}

	FILE *file1 = fopen("exam13-c.txt", "w");
	for (int i = 0; i < numOfRows; i++) //Output in file
	{
		fprintf(file1, "%s\t%s\t%s\t%s\n",
				row[i].FIO, row[i].category,
				row[i].number , row[i].info);
	}
	fclose(file1);

	for (int i = 0; i < numOfRows; i++)
	printf("%s\t%s\t%s\t%s\n", row[i].FIO, row[i].category, row[i].number, row[i].info);

	printf("search LastName: ");
	char FIO[32];
	gets(FIO);
	printf("\n");

	int findedRows = 0;
	for (int i = 0; i < numOfRows; i++)
	{
		char *lastNameFromFIO = strtok(row[i].FIO, " "); //read anytil " "
		if (strcmp(lastNameFromFIO, FIO) == 0)
		{
			printf("number: %s\n", row[i].number);
			printf("info: %s\n", row[i].info);
			findedRows++;
		}
	}
	if(findedRows < 1) printf("not fount laste name\n");

	////////////

	printf("search category: ");
	char category[48];
	gets(category);
	printf("\n");

	findedRows = 0;
	for (int i = 0; i < numOfRows; i++)
	{
		char *categoryFromTable = strtok(row[i].category, "\n"); //read anytil " "
		if (strcmp(categoryFromTable, category) == 0)
		{
			printf("number: %s\n", row[i].number);
			findedRows++;
		}
	}
	if(findedRows < 1) printf("not fount category\n");



	return 0;

}

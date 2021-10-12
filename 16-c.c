#include <stdio.h>

struct record
{
		char drugName[64]; //drug name
		char cntrIndications[64];	//contraindication
		int expYears;	//explotation years
		int manufYears; //date of manufacture
};

#define n 3
struct record row[n];

int main()
{
		//reading from keyboard
		for (int i = 0; i < n; i++)
		{
			scanf ("%s %s %d %d",
					row[i].drugName, row[i].cntrIndications,
					&row[i].expYears , &row[i].manufYears);
		}

		//Output
		printf ("name\tindics\texp\tyear\n");
		for (int i = 0; i < n; i++)
		{
			printf("%s\t%s\t%d\t%d\n",
					row[i].drugName, row[i].cntrIndications,
					row[i].expYears , row[i].manufYears);
		}

		FILE *file1 = fopen("Test.txt", "w+");
		for (int i = 0; i < n; i++) //Output in file
		{
			fprintf(file1, "%s\t%s\t%d\t%d\n",
					row[i].drugName, row[i].cntrIndications,
					row[i].expYears , row[i].manufYears);
		}
		fclose(file1);

		FILE *file2 = fopen("Test2.txt", "wb+");
		fwrite(row, sizeof(struct record), n, file2);
		fclose(file2);

		return 0;
}

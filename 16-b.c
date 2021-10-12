#include <stdio.h>

struct theRecord
{
		char drugName[64]; //drug name
		char cntrIndications[64];	//contraindication
		int expYears; //explotation years
		int manufYears; //date of manufacture
};

#define n 3
struct theRecord row[n];

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

		FILE *abc = fopen("Test", "w+");
		for (int i = 0; i < n; i++) //Output in file
		{
			fprintf(abc, "%s\t%s\t%d\t%d\n",
					row[i].drugName, row[i].cntrIndications,
					row[i].expYears , row[i].manufYears);
		}
		fclose(abc);



		return 0;
}

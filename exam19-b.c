#include <stdio.h> // FILE, fopen(), fscanf(), fclose()

#define max_ans 5
#define max_txt 100

struct quest
{
	int nans;
	int corr;
	char txt[max_txt];
	char ans[max_ans][max_txt];

};

#define max_quest 10
struct quest test[max_quest];

int main()
{
	char imia[16];
	char familia[16];
	char group[5];
	printf("Enter your familia ");
	scanf("%s", &familia);
	printf("Enter your imua ");
	scanf("%s", &imia);
	printf("Enter your group ");
	scanf("%s", &group);
	int c[max_quest];
	
	FILE *f = fopen("exam19.txt", "r");
	
	int nq;
	fscanf(f, "%d", &nq);
	
	for(int i = 0; i < nq; i++)
	{
		fscanf(f, "%d %d\n", &test[i].nans, &test[i].corr);
		fgets(test[i].txt, max_txt, f);
		for(int j = 0; j < test[i].nans; j++)
					fgets(test[i].ans[j], max_txt, f);
		
	}
	
	fclose(f);
	
	for(int i = 0; i < nq; i++)
	{
		printf(test[i].txt);
		for(int j = 0; j < test[i].nans; j++)
				printf(test[i].ans[j]);
		
		scanf("%d", &c[i]);
		
		if (c[i] == test[i].corr) puts("correct!");
		else puts("wrong!");
	}
	
	FILE *s = fopen("otvet.txt", "w");
	fprintf(s,"FIO = %s %s \ngroup = %s\n", familia, imia, group);
	for(int i = 0; i < nq; i++)
	{
		fprintf(f,"Vopros %d\n", i + 1);
		fprintf(f,test[i].txt);
		fprintf(f,"Selected otvet %d ", c[i]);
		if (c[i] == test[i].corr) fprintf(f,"correct!\n");
		else fprintf(f,"wrong!\n");
	}
	fclose(s);
	return 0;
	
}
#include <stdio.h> //FILE, fopen(), fclose(), fgets()
#include <string.h> // srlen(), strcpy(), strchr()

#define max_txt 256

int main()
{
	FILE *f = fopen("exam20.txt", "r");
	
	int m = 0;
	char p[max_txt];
	while(1)
	{
		
		
		char s[max_txt];
		if (fgets(s, max_txt, f) == NULL) break;
		
		char *c = strchr(s, '\n');
		if(c != NULL) *c = '\0';
	
		int l = strlen(s);
		printf("%s %d\n", s, l);
		if (l > m)
		{
			m = l;
			strcpy(p, s);	
	
		}
	}
	
	printf("str = %s\n", p);
	printf("len = %d\n", m);
	fclose(f);
	char spc[100];
		for (int i = 0; i < m; i++)
		{
			spc[i] = '*';
		}
			
	char change[max_txt];

	FILE *f1 = fopen("exam20.txt", "r");
	FILE *w = fopen("exam_out20.txt", "w");
	while(1)
	{

		char g[max_txt];
		if (fgets(g, max_txt, f1) == NULL) break;
		
		char *c = strchr(g, '\n');
		if(c != NULL) *c = '\0';
	
		int l = strlen(g);
		
		if (l < m)
		{
			strncat(g,spc,m-l);
			strcpy(change, g);	
			
		}
		else
			if(l == m)
				strcpy(change, g);
		
			
		fprintf(w,"%s\n",change);		
	}
	
	
	fclose(w);
	
	return 0;
	
	
}
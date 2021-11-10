#include <stdio.h>
#include <string.h> //strcpy()
#include <stdlib.h>

struct theRow
{
	char title[50];
	char mfg[100];
	short year;
	int price;
};

#define rowNum 3
struct theRow row[rowNum];

//na 5 |
//int main();
void theUpdateRow();

void writeInTxt()
{
    //WRITE TABLE IN TXT FILE
	FILE *theWriteFile = fopen("exam22.txt", "w+");
	//OUTPUT TABLE
	for(int i = 0; i < rowNum; i++)
	fprintf(theWriteFile, "%s\t%s\t%d\t%d\n", row[i].title, row[i].mfg, row[i].year, row[i].price);
	fclose(theWriteFile);
}

void outputTable()
{
	//OUTPUT TABLE
	for(int i = 0; i < rowNum; i++)
	printf("%s\t%s\t%d\t%d\n", row[i].title, row[i].mfg, row[i].year, row[i].price);
}


void menuCall()
{
	//MENU
	int theChooseOne = 0;
	printf(" [0]  	[1]\n");
	printf("[EXIT] [UPDATE]\n");
	printf("Choose(0/1): ");
	scanf("%d", &theChooseOne);
	if (theChooseOne == 0)
	exit(0);
	else if (theChooseOne == 1)
	theUpdateRow();
	else
	{
		printf("write 0 or 1\n");
		menuCall();
	}
}

void theUpdateRow()
{
    outputTable();
	int fondRowNum = 0;
	char xTitle[50];
	printf("Title: ");
	scanf("%s", xTitle);
	printf("Foundindg for %s\n", xTitle);
	//strcpy(xTitle, "Video Adapter");
	
	for(int i = 0; i < rowNum; i++)
	{
		if(strcmp(row[i].title, xTitle) == 0)
		{
			fondRowNum++;
			
			char newTitle[50];
			printf("New title: ");
			scanf("%s", newTitle);
			strcpy(row[i].title, newTitle);
			
			char newMfg[100];
			printf("New mfg: ");
			scanf("%s", newMfg);
			strcpy(row[i].mfg, newMfg);
			
			short newYear;
			printf("New year: ");
			scanf("%hd", &newYear);
			row[i].year = newYear;
			
			int newPrice;
			printf("New price: ");
			scanf("%d", &newPrice);
			row[i].price = newPrice;
			
			//WRITE TABLE IN BIN and TXT FILE
			FILE *theUpdateFile = fopen("exam22.bin", "wb+");
			fwrite(row, sizeof(struct theRow), 3, theUpdateFile);
			fclose(theUpdateFile);
			writeInTxt();
			
			outputTable();
		}
		else if(fondRowNum != 0)
		{
			printf("Number of founds rows: %d\n", fondRowNum);
			printf("End finding title %s\n", xTitle);
			menuCall();
		}   
	}
}
//na 5 |

int main()
{
	//создать двоичный файл - записи комплект пк
	//вывести информацию из базы данных на экран
	//выдать название фирм нужного комплектующего (вводится Пользоватлем)
	//сохранять и загружать файл
	/* 4 - из двоичного файла в текстовый, в котором
	каждая строчка - отдельная запись из таблицы БД*/
	// 5 - оформить взаимодействие с БД через пункты меню
	
	/*
	//WRITE TABLE
	strcpy(row[0].title, "VideoAdapter");
	strcpy(row[0].mfg, "Nvidia");
	row[0].year = 2020;
	row[0].price = 40000;
	strcpy(row[1].title, "HardDrive");
	strcpy(row[1].mfg, "WesternDigital");
	row[1].year = 2019;
	row[1].price = 5000;
	strcpy(row[2].title, "SoundCard");
	strcpy(row[2].mfg, "Realtek");
	row[2].year = 2015;
	row[2].price = 1000;
	//WRITE TABLE FROM BIN FILE
	FILE *theWriteBinFile = fopen("exam22.bin", "wb+");
	fwrite(row, sizeof(struct theRow), 3, theWriteBinFile);
	fclose(theWriteBinFile);
	*/
	
	//READ TABLE FROM BIN FILE
	FILE *theReadFile = fopen("exam22.bin", "rb+");
	fread(row, sizeof(struct theRow), 3, theReadFile);
	fclose(theReadFile);
	
	writeInTxt(); //na 4
	
	outputTable();
	
	//READ XTitle
	char xTitle[50];
	printf("find: ");
	fgets(xTitle, 50, stdin);
	//Enter in 0
	char *p = strchr(xTitle, '\n');
	if (p != NULL) *p = 0;
	p = strchr(xTitle, '\r');
	if (p != NULL) *p = 0;
	
	//FIND XTITLE
	int thereIsNoXTitle = 1;
	for(int i = 0; i < rowNum; i++)
	if (strcmp(row[i].title, xTitle) == 0)
	{
		puts(row[i].mfg);
		thereIsNoXTitle = 0;
	}
	if(thereIsNoXTitle == 1)
	printf("No title found\n");
	
	menuCall(); //na 5
	
	
	return 0;
}




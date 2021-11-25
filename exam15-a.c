//15
//na 3 - "Заполнить таблицу инфой и вывести на экран, выдать аппаратные требования для установленной на вашем ПК ОС, название ОС вводится пользователем"
//na 4 - "Дополнительно подобрать конфигурацию программных средств по минимальной цене"
//na 5 - "Дополнительно сохранить конфигурацию программных средств в текстовый файл"

#include <stdio.h>
#include <string.h>
#include <limits.h>

struct record
{
	char osNames[32];
	int virtualMemory; //virt memory
	int physicalMemory; //physical memory
	int price; //price
	float res; //resultat
};


#define numOfRows 3
struct record row[numOfRows];

int main()
{
	char tmp[32];
	for(int i = 0; i < numOfRows; i++)
	{
		printf("[record %d]\OS, virtual Memory, physical Memory, price: ", i);
		scanf("%s %d %d %d", row[i].osNames, &row[i].virtualMemory,
		&row[i].physicalMemory, &row[i].price);
		printf("\n");
	}

	printf("|\tOS\t|\tVirtM\t|\tPhysM\t|\tPrice\t|\n");
	for(int i = 0; i < numOfRows; i++)
	printf("|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\n", row[i].osNames, row[i].virtualMemory,
	row[i].physicalMemory, row[i].price);

	return 0;
}

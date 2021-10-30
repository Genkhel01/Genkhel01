#include <stdio.h>
#include <stdlib.h>

int writeFile(int days, float valueLow, float valueHight)
{
	//WRITE VALUE IN FILE
	FILE *theWriteFile = freopen("exam09-b.txt", "w", stdout);
	for(int i = 0; i < days; i++)
	printf("%f\n", (valueLow + ((valueHight - valueLow) * rand() / RAND_MAX)));
	fclose(theWriteFile);
	return 0;
}

int main()
{

	//стоимость доллора по курсу
	//по дням (31) массив заполн случ данными от 10 до 50
	//указать сам выскоий и низкий курс долл
	//4 - чтение исходных данных из тхт файла в массив
	//5 - поиск нужного курса + указать дату курса

	int days =  31;
	float valueLow =  10.0f;
	float valueHight = 50.0f;
	float value[days];
	float scanSymbol;

	//READ VALUE FROM FILE
	FILE *theReadFile = fopen("exam09-b.txt", "r");
	//if not exist write file
	if(theReadFile == NULL) writeFile(days, valueLow, valueHight);
	int j = 0;
	while (j < days)
	{
		fscanf(theReadFile, "%f", &value[j]);
		//printf("%.2f\n", value[j]);
		j++;
	}
	fclose(theReadFile);

	//OUTPUT VALUE $ FOR EVERY DAY
	printf("|\tday\t|\t$\t|\n");
	for(int i = 0; i < days; i++)
	{
		printf("|\t%d\t|\t%.2f\t|\n", i+1, value[i]);
	}

	//CALCULATING MIN AND MAX VALUE
	float valueMin = valueHight;
	float valueMax = valueLow;
	for(int i = 0; i < days; i++)
	{
		if(value[i] < valueMin) valueMin = value[i];
		if(value[i] > valueMax) valueMax = value[i];
	}

	//OUTPUT MIN AND MAX VALUE
	printf("min = %.2f\n", valueMin);
	printf("max = %.2f\n", valueMax);

	return 0;
}

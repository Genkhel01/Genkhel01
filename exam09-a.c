#include <stdio.h>
#include <stdlib.h>

int main()
{

	//стоимость доллора по курсу
	//по дням (31) массив заполн случ данными от 10 до 50
	//указать сам выскоий и низкий курс долл
	//4 - чтение исходных данных из тхт файла в массив
	//5 - поиск нужного курса + указать дату курса

	int days =  31;
	float value[days];
	float valueLow =  10.0f;
	float valueHight = 50.0f;

	//charge value $ for every day
	for(int i = 0; i < days; i++)
	value[i] = valueLow + ((valueHight - valueLow) * rand() / RAND_MAX);

	//output value $ for every day
	printf("|\tday\t|\t$\t|\n");
	for(int i = 0; i < days; i++)
	{
		printf("|\t%d\t|\t%.2f\t|\n", i, value[i]);
	}

	//calculating min and max value
	float valueMin = valueHight;
	float valueMax = valueLow;
	for(int i = 0; i < days; i++)
	{
		if(value[i] < valueMin) valueMin = value[i];
		if(value[i] > valueMax) valueMax = value[i];
	}

	//output min and max value
	printf("min = %.2f\n", valueMin);
	printf("max = %.2f\n", valueMax);

	return 0;
}

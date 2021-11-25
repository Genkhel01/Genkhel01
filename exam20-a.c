#include <stdio.h> //fgets(), sprintf(), puts()
#include <string.h> //strchr(), strlen()

int main()
{
	//тчитать текст файл
	//вывести самую длинную строку в этом фале и её длинну
	//4 - дописать длинну для каждой строки (в файле)
	//5 - выровнить исходные сртроки файла, по самой длинной строке текста
	//недостающие символы - в конце, в виде кол-ва звёздочек

	int maxRowsNum = 256;

	FILE *theReadFile = fopen("exam20Input.txt", "r");
	while(1)
	{
		char textOfFile[maxRowsNum]
	}
	fclose(textOfFile);

	return 0;
}

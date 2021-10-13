#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
		char theString[256]; //create char array
													//stdin - file systeam
		fgets(theString, 256, stdin);  //read char from stream and store them into the array

		//???
		char *p = strchr(theString, '\n');
			if (p != NULL) p[0] = '\0';

		//the lenght of array in n
		size_t lenghtOfTheStrig = strlen(theString);
		//print the lenghtOfTheStrig
		printf("lenght: %ld\n", lenghtOfTheStrig);

		//counting the words
		int numOfWords = 0;
			for (int i = 0; i < lenghtOfTheStrig-1; i++)
			{      //if the probel
				 if (theString[i] == ' ' && theString[i+1] != ' ')
				 {
					 	numOfWords++;
						//to uppercase (if not possible, it returns NULL)
						theString[i+1] = toupper(theString[i+1]);
				 }
			}

		//if there any symbol
		    if(theString[0] == ' ') numOfWords--;
			if(lenghtOfTheStrig > 0) numOfWords++;
		printf("num words: %d\n", numOfWords);


		return 0;
}

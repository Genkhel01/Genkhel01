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

            //!!!lenght of every Word
            int numOfSumbols[lenghtOfTheStrig];
            int theAlternativeNumOfWords = 0;
                for (int i = 0; i < lenghtOfTheStrig; i++)
                {
                    theAlternativeNumOfWords++;
                    //if it's not probel
                    if (theString[i] != ' ')
                    {
                        int numSymbl = 0; //number of symbol
                            int startOfWord = i;
                                   //if it's not probel
                            for (; theString[i] != ' '; i++)
                            {       //if in string
                                if (i < lenghtOfTheStrig)
                                    numSymbl++;
                            }
                        char theWord[numSymbl];
                            for (int x = 0; x < numSymbl; x++)
                            {
                                theWord[x] = theString[startOfWord+x];
                                printf("%c", theString[startOfWord+x]);
                            }

                        numOfSumbols[theAlternativeNumOfWords] = numSymbl;
                        printf(" %d\n", numOfSumbols[theAlternativeNumOfWords]);
                        //???
	                    //char *h = strchr(theWord, '\n');
                    	//	if (h != NULL) h[0] = '\0';
                        //printf("%c", theWord);
                    }
                }



    		//!!!counting the words
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

		//print the lenghtOfTheStrig
    	printf("string lenght: %ld\n", lenghtOfTheStrig);
	    //if there any symbol
	    if(theString[0] == ' ') numOfWords--;
		if(lenghtOfTheStrig > 0) numOfWords++;
            printf("num words: %d\n", numOfWords);

		theString[0] = toupper(theString[0]);
		printf("%s \n", theString);

		return 0;
}

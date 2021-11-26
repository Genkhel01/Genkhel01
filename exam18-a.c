#include <stdio.h> //fgets(), sprintf(), puts()
#include <string.h> //strchr(), strlen()

//4 - восстановление сжатой строки
//5 - частота встречаемости в строке для каж символа

int main()
{
  char theInputString[30];
  fgets(theInputString, 30, stdin);

  char *stringForRemoveNew = strchr(theInputString, '\n');
  if(stringForRemoveNew != NULL)
    *stringForRemoveNew = '\0';

  char theOutputString[100];
  int indexOfOutputString = 0;

  char oldSynbol = theInputString[0];
  int numOfRepeat = 0;

  int lenghtOfSting = strlen(theInputString);
  for(int i = 1; i <= lenghtOfSting; i++) //for every symbol in string
  {
    char symbol = theInputString[i];
    if(oldSynbol == symbol) //if symbol repeat
      numOfRepeat++;
    else //if symbol not to repeat
    {
      theOutputString[indexOfOutputString] = oldSynbol;
      indexOfOutputString++; //to next symbol
      if(numOfRepeat > 0); //if symbol was in string more than 0
      {
        //write
        int writeIt = sprintf(theOutputString + indexOfOutputString, "%d", numOfRepeat + 1);
        indexOfOutputString += writeIt;
      }
      numOfRepeat = 0;
    }
    oldSynbol = symbol; //now symbol is next
  }

  //OUTPUT THEOUTPUTSTRING
  theOutputString[indexOfOutputString] = '\0'; //remove \n
  puts(theOutputString);

  return(0);
}

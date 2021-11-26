#include <stdio.h> //fgets(), sprintf(), puts()
#include <stdlib.h> //malloc()
#include <string.h> //strchr(), strlen()

//4 - восстановление сжатой строки
//5 - частота встречаемости в строке для каж символа

struct theBukva
{
  int indexOfBukva;
  int num;
};
struct theBukva *arrayOfBukva;

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

  int lenghtOfInputString = strlen(theInputString);
  arrayOfBukva = (theBukva *) malloc(lenghtOfInputString * sizeof(theBukva)); //na 4
  for(int i = 1; i <= lenghtOfInputString; i++) //for every symbol in string
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
        arrayOfBukva[i-1].indexOfBukva = i-1; //na 4
        arrayOfBukva[i-1].num = numOfRepeat + 1; //na 4
        //printf("%d\t%d\n", arrayOfBukva[i-1].indexOfBukva, arrayOfBukva[i-1].num);
        //write
        int writeIt = sprintf(theOutputString + indexOfOutputString, "%d", numOfRepeat + 1);
        indexOfOutputString += writeIt;
      }
      numOfRepeat = 0;
    }
    oldSynbol = symbol; //now symbol is next
  }

  //OUTPUT THEOUTPUTSTRING
  //theOutputString[indexOfOutputString] = '\0'; //remove \n
  int lenghtOfOutpyString = strlen(theOutputString);
  puts(theOutputString);



  for(int i = 0; i < lenghtOfOutpyString; i+2)
  {
    char brah[1];
    brah[0] = theOutputString[arrayOfBukva[i].indexOfBukva];
    //brah[1] = '\0';
    //int writeIt = sprintf(brah, "%d");
    //printf("%s\n", symbol); //думает, что переменная чар это инт, почему?
    puts(brah);
  }

  return(0);
}

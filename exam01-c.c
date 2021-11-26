#include <stdlib.h> //EXIT_SUCCESS, NULL, malloc(), free()
#include <stdio.h> // FILE, fopen(), fscanf()
#include <string.h> // strcpy(), strcmp()

#define max_word 64

struct element
{
  char word[max_word];
  int count;
  struct element *next;
};

struct element *first = NULL;

struct element *find(char word[max_word])
{
  struct element *current = first;
  while(current != NULL)
  {
    if (strcmp(current->word, word) == 0) return current;
    current = current->next;
  }
  return NULL;
}

struct element *add()
{
  struct element *mem =
  (struct element *) malloc(sizeof(struct element));
  mem->next = first;
  first = mem;
  return mem;
}

int main()
{
//na 3 - "Имеется тектовый файл, в нем слова отделены пробелами
//все слава даны в одну строчку постороить односвязный список таким
//образом чтобы слова не повторялись,..
//.. и для каждого слова указать сколько оно раз повторяется и вывести список на экран"
//na 4 - "Найти минимальное и максимальное значение повторяющихся слов и вывести"
//na 5 - "Список выведеный на экран сохранить в файл"
  FILE *f = fopen("exam1.txt", "r");
  while(1)
  {
    char temp[max_word];
    int n = fscanf(f, "%s", temp);
    if (n != 1) break;

    struct element *found = find(temp);
    if(found != NULL) found->count++;
    else
    {
      struct element *added = add();
      strcpy(added->word, temp);
      added->count = 1;
    }
  }
  fclose(f);

  FILE *fw = fopen("exam1List.txt", "w");

  int minWord = 65;
  int maxWord = -1;
  struct element *current = first;
  while (current != NULL)
  {
    fprintf(fw ,"%s %d\n", current->word, current->count);
    printf("%s %d\n", current->word, current->count);
    if(current->count <= minWord) minWord = current->count;
    if(current->count >= maxWord) maxWord = current->count;
    struct element *next = current->next;
    free(current);
    current = next;
  }
  printf("min: %d\n", minWord);
  printf("min: %d\n", maxWord);
  fprintf(fw ,"min: %d\n", minWord);
  fprintf(fw ,"min: %d\n", maxWord);



  fclose(fw);

  return EXIT_SUCCESS;

}

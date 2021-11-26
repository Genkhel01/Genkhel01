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

struct element *current = first;
while (current != NULL)
{
printf("%s %d\n", current->word, current->count);
struct element *next = current->next;
free(current);
current = next;
}

return EXIT_SUCCESS;

}

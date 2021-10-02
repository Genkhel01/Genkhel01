#include <stdlib.h>
#include <stdio.h>

#define days 30
#define min 740
#define max 780
#define norm 760
int pressha[days]

int main()
{

    for(int i = 0; i < days; i++)
        pressha[i] = min + rand() % (max - min + 1)
    for(int i = 0; i < days; i++)
        printf("%d\t%d", i+1, pressha[i]);

}
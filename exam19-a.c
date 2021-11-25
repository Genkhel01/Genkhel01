#include <stdio.h> //FILE, fopen(), fscanf(), fclose()

#define max_ans 5
#define max_txt 100

struct quest
{
    int nans;
    int corr;
    char text[max_txt];
    char ans[max_ans][max_txt];
};

#define max_quest 10
struct quest test[max_quest];

int main()
{
    FILE *f = fopen("ezam_bilet19.txt", "r");

    int nq;
    fscanf (f, "%d", &nq);

    for(int i = 0; i < nq; i++)
    {
        fscanf(f, "%d %d\n", &test[i].nans, &test[i].corr);
        fgets(test[i].text, max_txt, f);
        for(int j = 0; j < test[i].nans; j++)
            fgets(test[i].ans[j], max_txt, f);
    }

    fclose(f);

    for(int i = 0; i < nq; i++)
    {
        printf(test[i].text);
        for(int j = 0; j < test[i].nans; j++)
            printf(test[i].ans[j]);

        int c;
        scanf("%d", &c);

        if (c == test[i].corr) puts("correct!");
        else puts("wrong!");
    }

    return 0;
}

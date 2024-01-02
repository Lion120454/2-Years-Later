#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdio.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    FILE *fr,*fw;
    int p,n;
    fr = fopen("IN13.txt", "r");
    fw = fopen("OUT13.txt", "w");
    if ((fr = fopen("IN13.txt", "r")) == NULL)
    {
        printf("Не удалось открыть файл IN13");
        getchar();
        return 0;
    }
    if ((fw = fopen("OUT13.txt", "w")) == NULL)
    {
        printf("Не удалось открыть файл OUT13");
        getchar();
        return 0;
    }
    fscanf(fr, "%d%", &p);
    for(int i=0;i<15;i++)
    {
        fscanf(fr, "%d%", &n);
        n=n*p;
        fprintf(fw,"%d ",n);
    }
    fclose(fr);
    fclose(fw);
    getchar();
    return 0;
}

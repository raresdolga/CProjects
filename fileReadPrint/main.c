#include <stdio.h>
#include <stdlib.h>
char *x,er;
int i=1;
int main()
{
FILE *f=fopen("input.in","r");
FILE *g=fopen("output.txt","w");
x=(char*)malloc(101*sizeof(char));
if(!f)
{
    printf("could not be opened\n");
    return 3;
}
er=fscanf(f,"%s",x);//fara spatii, citeste doar pana la primul spatiu
fgets(x,101,f);//cu spatii
if(!er) return 4;
        fprintf(g,"%s\n",x);
        fclose(g);

    return 0;
}

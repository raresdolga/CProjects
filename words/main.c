#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{int  nrw=0,ok=1,c;
double i;
    for(i=0;(c=getchar())!=EOF;i++)
    {
        if(strchr(" \n\t",c)!=NULL)ok=1;
        else
            if(ok==1){nrw++;ok=0;}
    }
    printf("%i\n",nrw);
    printf("%.0f\n",i);
    return 0;
}

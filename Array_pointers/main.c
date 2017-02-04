#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{char s[51]="ljnnbmnb";
int i=0;
    while(i<10)
    {
        printf("%s",s);
        puts("\n");
strcpy(s,s+i+1);
i+=1;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int getline(char s[],int lim);
int main()
{int len,max=0;
char line[100];
char longest[1000];
len=getline(line,100);
strcpy(longest,"");
while(len>0)
{if(len>8)
strcat(line,"\n");
strcat(longest,line);
    len=getline(line,100);
}
printf("%s\n",longest);
    return 0;
}
int getline( char s[], int lim )
{int i=0,c;
    for(i=0;i<lim&&(c=getchar())!=EOF&&c!='\n';i++)
        s[i]=c;
        if(c=='\n')
        {s[i]=c;
        i++;}
        s[i]=NULL;
        return i;
}

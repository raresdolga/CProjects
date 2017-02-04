#include <stdio.h>
#include <stdlib.h>
#include<string.h>
 int  getline(char s[])
{
    int i=0,c;
    while((c=getchar())!=EOF && c!='\n')
    {
        if((strchr(" /t",c)==0))s[i]=c;
    i++;
    }
    if(c=='\n'){s[i]=c;
    i++;}
    s[i]='0';
    return i;
}
int main()
{char line[1000];
int len;
len =getline(line);
while(len>0)
{
        printf("%s\n",line);
        len=getline(line);
}


    return 0;
}

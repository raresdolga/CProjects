#include <stdio.h>
#include <stdlib.h>
/*char * stringCopy(char *s, char *p)
{
    //char *p=(char*)malloc(strlen(s)*sizeof(char));
    while(*s)
    {
        *p++=*s++;


    }
    *p='\0';
    return p;
}*/
void strcpy1(char *s, char *t)
	{
		while(*t != '\0')
			*s++ = *t++;
		*s = '\0';
	}
int main()
{char s[101];
char *p,*c;
int i;
    scanf("%s",s);
    c=s;
  strcpy1(p,c);
    printf("%s\n",p);
    return 0;
}

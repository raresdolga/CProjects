#include <stdio.h>
#include <stdlib.h>

int main()
{ int c;
double nc=0;
while((c=getchar())!=EOF)
{ ++nc;
 putchar(c);
}
 printf("%.0f\n",nc);
printf("%d\n",c);
    return 0;
}

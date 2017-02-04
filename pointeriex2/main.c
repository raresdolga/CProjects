#include <stdio.h>
#include <stdlib.h>
int i=10;
int main()
{int *p=&i;
int *a;
a=&i;
int *b;
b=&i;
    printf("%i\n%i\n%i\n",p,a,*b);
    return 0;
}

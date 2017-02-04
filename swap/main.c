#include <stdio.h>
#include <stdlib.h>
int a,b;
void swap (int *x ,int *y)
{
    int aux;
    aux=*x;
    *x=*y;
    *y=aux;
}
int main()
{scanf("%d %d",&a,&b);
swap(&a,&b);
    printf("%d %d\n",a,b);
    return 0;
}

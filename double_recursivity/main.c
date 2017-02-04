#include <stdio.h>
#include <stdlib.h>
int n;
char a[20];
void G(int i)
{
    if(i==n)printf("%s\n",a);
    else
        {
            a[i]='.'; G(i+1);
            a[i]='-';G(i+1);
        }
}

int main()
{scanf("%d",&n);
G(0);

    return 0;
}

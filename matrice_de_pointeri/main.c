#include <stdio.h>
#include <stdlib.h>

int main()
{int *array[5]={
{2,4,5,6},
{3,6,7,4},
{4,8,9,1}
};
int i,j;
int *p;
for(i=0;i<=2;i++)
    {p=*(array+i);
        for(j=0;j<=3;j++)
            {printf("%d ",p);
            p++;
            }
    printf("\n");
    }
    printf("Hello world!\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int array[]={10,20,45,78};
int main()
{int *p;
char *string="hdjkadca";
int i;
p=array;
for(i=0;i<=3;i++)
printf("%d\n",*(array+i));//{ sau printf("%d"\n",*array)
                          //array++;}
printf("%d",p);
    return 0;
}

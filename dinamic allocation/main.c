#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}
int pivot(int *A,int i,int j)
{
    int k;
    int p=i;
    for(k=i;k<j;k++)
        if(*(A+k)<*(A+j))
        {
            swap((A+p),(A+k));
        p++;
        }
        swap((A+p),(A+j));
        return p;
}
void Quick(int *A,int i, int j)
{
    if(i<j)
        {
        int p=pivot(A,i,j);
        Quick(A,i,p-1);
        Quick(A,p+1,j);
        }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int *ptr=(int*)malloc(n*sizeof(int*));

    for(i=0;i<n;i++)
    scanf("%d",(ptr+i));

   /* for(i=0;i<n;i++)
    printf("%d\n",*(ptr+i));
*/
    Quick(ptr,0,n-1);

    for(i=0;i<n;i++)
    printf("%d\n",*(ptr+i));

    return 0;
}

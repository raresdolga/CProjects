#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "heap.h"
int right[101],left[101];
int prQueuMin(int Q[])
{
   return delete_heap(Q);
}
int prQueuAdd(int Q[],int key)
{
    insert_heap(key,Q);
}

int insertAllInQueu(char input[],int frq[],int Q[])
{
    int i,nr=0;
    for(i='A';i<'Z';i++)
        frq[i]=0;
    for(i=0;i<strlen(input);i++)
       {
           frq[*(input+i)]+=1;

       }
       for(i='A';i<'Z';i++)
           if(frq[i]>0)
        {
        nr++;
        prQueuAdd(Q,frq[i]);
        }
        return nr;

}

int huFfman(char *input,int *frq,int Q[],int n)
{
    int nrChar=n;

    int i;
    int x,y,z;
    for(i=1;i<nrChar;i++)
    {
        z=0;
        x=prQueuMin(Q);
        y=prQueuMin(Q);
        z=x+y;
        prQueuAdd(Q,z);
    }
    return prQueuMin(Q);

}
int main()
{
    int *heap_array=(int *)malloc(101*sizeof(int));
    int *frq=(int*)malloc(sizeof(int)*101);
    char *input=(char*)malloc(sizeof(char)*101);
    int prQue[101];
    int i;
        scanf("%s",input);
         n=insertAllInQueu(input,frq,prQue);
        printf("\n%d",huFfman(input,frq,prQue,n));

    return 0;
}

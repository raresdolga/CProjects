#include <stdio.h>
#include <stdlib.h>
void Merge(int L[101], int R[101],int A[101],int sizeL, int sizeR)
{int i=0, j=0,k=0;
    while(i<sizeL&& j<sizeR)
        if(L[i]<R[j])A[k++]=L[i++];
    else
    A[k++]=R[j++];
    while(j<sizeR)A[k++]=R[j++];
    while(i<sizeL)A[k++]=L[i++];

}
void mergesort(int A[],int m)
{int mij=0; int i;
int L[101];int R[101];
    if(m<2) return ;
    mij=m/2;
    for(i=0;i<mij;i++)L[i]=A[i];
    for(i=mij;i<m;i++)R[i-mij]=A[i];
    mergesort(L,mij);
    mergesort(R,m-mij);
    Merge(L,R,A,mij,m-mij);
}
int main()
{int i,n;
int A[101];
scanf("%i",&n);
for(i=0;i<n;i++)
    scanf("%i",&A[i]);
mergesort(A,n);
for(i=0;i<n;i++)
    printf("%i\n",A[i]);
    return 0;
}

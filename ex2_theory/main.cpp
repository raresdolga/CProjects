#include <iostream>
#include<math.h>
#include <stdlib.h>
using namespace std;
void citire (int n, int x[])
{
    for(int i=1;i<=n;i++)
        cin>>x[i];
}
void construction_graph(int p[], int a[51][51] , int n)
{int i,j;
    for(i=1;i<=n/2;i++)
    for(j=1;j<=n/2;j++)
        a[i][j]=9999999;
    for(i=1;i<=n-2;i=i+2)
        for(j=i+2;j<=n;j=j+2)
   {

    a[i/2+1][j/2+1]=abs(p[i]-p[j])+abs(p[i+1]-p[j+1]);
    a[j/2+1][i/2+1]=abs(p[i]-p[j])+abs(p[i+1]-p[j+1]);
    }
    }
    void prim(int a[51][51], int n, int y,int v[])
    {
        int mini,c; int nearest[51],cost=0;
        int k=1,i;
   for( i=1;i<=n/2;i++)
    {
        nearest[i]=y;
        v[i]=0;}
        v[1]=1;
    while(k<(n/2))
    { mini=99999999;
        for(i=1;i<=n/2;i++)
            if(v[i]==0)
                if(a[i][nearest[i]]<=mini)
                    {
                        mini=a[i][nearest[i]];
                       c=i;
                    }
                    k++;

                          cost+=mini;
                          v[c]=1;
                          for(i=0;i<=n/2;i++)
                            if(v[i]==0)
                          if(a[i][c]<a[i][nearest[i]])
                            nearest[i]=c;

    }
    cout<<cost<<" ";
}


int main()
{int n,p[51],a[51][51];
cin>>n;
citire(n,p);
construction_graph(p,a,n);
prim(a,n,1,p);

    return 0;
}

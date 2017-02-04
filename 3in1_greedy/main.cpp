#include <iostream>
using namespace std;
int a[101][101],dist[101],v[101],y,nearest[101];
    int k,n,i,j;
void citire(int n, int a[101][101])
{for(int i=1;i<n;i++)
    for(int j=0;j<n;j++)
    {
        cin>>a[i][j];
        if(a[i][j]==0)a[i][j]=99999;
        for(i=0;i<n;i++)
    {v[i]=0;
    nearest[i]=y;
    }
    }
}
int mini1( int dist[101])
{int mini=0;int l;
    for(int i=0;i<n;i++)
    if(v[i]==0)
    {if(dist[i]<mini)
    mini=dist[i];
    l=i;
    }
return l;
}
int verif(int v[101])
{
    for(int i=0;i<n;i++)
        if(v[i]==0)return 0;
    return 1;
}
void dijadkra(int n, int a[101][101],int dist[101], int p)
{k=0;
int c;
for(i=0;i<n;i++)
    {dist[i]=a[p][i];
        v[i]=0;}
    v[p]=1;
while(verif==0)
{
    for(int i=0;i<n;i++)
        c=mini1(dist);
    v[c]=0;
    for(int i=0;i<n;i++)
        if(v[i]==0)
        dist[i]=min(dist[i], dist[c]+a[c][i]);
}
}
int main()
{int c;
    cin>>n>>y;
    citire(n,a);
    int mini;
    k=0;
    v[y]=1;
    while(k<n)
    {
        mini=99999;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
        if(a[i][nearest[i]]<mini)
        {
            mini=a[i][nearest[i]];
            c=i;
        }
        k++;
    }
    cout << "Hello world!" << endl;
    return 0;
}

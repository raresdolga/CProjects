#include <iostream>

using namespace std;
int n, v[101],l=1;
struct nod
{
    int a[4][4];
}c[282];
void citire()
{cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        for(int j=1;j<=282;j++)
            if(v[i]%4==0)c[l].a[v[i]/4][4]=0;
        else
            c[l].a[v[i]/4+1][v[i]%4]=0;
    }
}
int vecini(int i, int j, int l)
{
    int k=0;
    if(c[l].a[i-1][j]==1)
        k++;
        if(c[l].a[i+1][j]==1)
            k++;
        if(c[l].a[i][j-1]==1)
            k++;
        if(c[l].a[i][j+1]==1)
            k++;
            if(c[l].a[i][j]==1)
                k++;
        return k;
}
void matrice(int l)
{
    for(int i=1;i<=16;i++)
        for(int j=1;j<=16;j++)
        c[l].a[i][j]=vecini(i,j,l);
}
void maxim(int &p, int &t, int l)
{int maxi=0;
    for(int i=1;i<=16;i++)
        for(int j=1;j<=16;j++)
            if(c[l].a[i][j]>maxi)
        {
            maxi=c[l].a[i][j];
            p=i;
            t=j;
        }
}
void vecini_comuni(int i, int j, int e, int d, int &z , int &x, int l)
{ x=0;
  z=0;
    if(c[l+1].a[i-1][j]==0&&(e-1==i-1)&&(j==d)&& c[l+1].a[e-1][j]==0)
     {
         z=i-1;
            x=j;
            return ;
     }
       if(c[l+1].a[i+1][j]==0&&(e+1==i+1)&&(j==d) && c[l+1].a[e+1][j]==0)
     {
         z=i+1;
            x=j;
            return ;
     }
     if(c[l+1].a[i][j-1]==0&&(e==i)&&(j-1==d-1)&& c[l+1].a[e][j-1]==0)
     {
         z=i;
        x=j-1;
        return ;
     }
      if(c[l+1].a[i][j+1]==0 &&c[l+1].a[e][j+1]==0&&(e==i)&&(j+1==d+1))
     {
         z=i;
        x=j+1;
        return ;
     }
}
void parcurgere_matrix(int &l)
{
    int t,p,e,d,z,x;
    maxim(p,t,l);
    matrice(l);
    if(c[l].a[1][1]!=0)
    {cout<<c[l].a[1][1]<<" ";
        c[l+1].a[1][1]=0;
    }
    else
        if(c[l].a[1][16]!=0)
        {cout<<c[l].a[1][16]<<" ";
            c[l+1].a[1][16]=0;
        }
    else
        if(c[l].a[16][1]!=0)
        {cout<<c[l].a[16][1]<<" ";
            c[l+1].a[16][1]=0;
        }
    else
        if(c[l].a[16][16]!=0)
        {

        cout<<c[l].a[16][16]<<" ";
            c[l+1].a[16][16]=0;
        }
    else
    {cout<<c[l].a[p][t]<<" ";
          c[l+1].a[p][t]=0;

     if(c[l+1].a[p-1][t]!=0)
       c[l+1].a[p-1][t]=0;

        if(c[l+1].a[p+1][t]!=0)
        c[l+1].a[p+1][t]=0;

        if(c[l+1].a[p][t-1]!=0)
          c[l+1].a[p][t-1]=0;

        if(c[l+1].a[p][t+1]!=0)
            c[l+1].a[p][t+1]=0;
matrice(l+1);
    maxim(e,d,l+1);
    vecini_comuni(t,p,e,d,z,x,l+1);
    c[l+1].a[z][x]=1;
    }
    l++;
}
int main()
{
    citire();
    while(l<=n)
    parcurgere_matrix(l);

    return 0;
}

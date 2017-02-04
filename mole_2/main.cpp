#include <iostream>

using namespace std;
int i,n,a[8][8],j,v[17],c[6][6];
struct nod
{
    int a[4][4];
}c[282];

void citire()
{cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
            if(v[i]%4==0)a[v[i]/4][4]=-2;
        else
            a[v[i]/4+1][v[i]%4]=-2;
    }
}
    void bordare()
{
    int i;
    for(i=1;i<=4;i++)
        {
            a[i][0]=-1;
            a[i][5]=-1;
        }
         for(i=2;i<4;i++)
         {
             a[0][i]=-1;
            a[5][i]=-1;
         }
}
int vecini(int i, int j)
{
    int k=0;
    if(a[i-1][j]==-2)
        k++;
        if(a[i+1][j]==-2)
            k++;
        if(a[i][j-1]==-2)
            k++;
        if(a[i][j+1]==-2)
            k++;
        return k;
}
int check_in(int i, int j)
{
    if(i>=1&&j>=1&&i<=4&&j<=4)
        return 1;
    return 0;
}
void vecini_comuni(int i, int j, int e, int d, int &z , int &x)
{ x=0;
z=0;
    if(a[i-1][j]==0&&(e-1==i-1)&&(j==d)&& a[e-1][j]==0)
     {
         z=i-1;
            x=j;
            return ;
     }
       if(a[i+1][j]==0&&(e+1==i+1)&&(j==d) && a[e+1][j]==0)
     {
         z=i+1;
            x=j;
            return ;
     }
     if(a[i][j-1]==0&&(e==i)&&(j-1==d-1)&& a[e][j-1]==0)
     {
         z=i;
        x=j-1;
        return ;
     }
      if(a[i][j+1]==0 &&a[e][j+1]==0&&(e==i)&&(j+1==d+1))
     {
         z=i;
        x=j+1;
        return ;
     }
}
void go(int i, int j, int a[8][8])
{
    int p=0;
    a[i][j]=0;
     if(a[i-1][j]==-2)
        a[i-1][j]=0;
        /*else
            if(check_in(i-1,j)&&p==0)
            {
            a[i-1][j]=-2;
           p=1;
            }*/
        if(a[i+1][j]==-2)
        a[i+1][j]=0;
     /*  else
        if(check_in(i+1,j)&&p==0)
       {a[i+1][j]=-2;
        p=1;}*/

        if(a[i][j-1]==-2)
          a[i][j-1]=0;
      /* else
       if(check_in(i,j-1)&&p==0)
           {a[i][j-1]=-2;
    p=1;}*/
        if(a[i][j+1]==-2)
            a[i][j+1]=0;
      /* else
        if(check_in(i,j+1)&&p==0)
            {a[i][j+1]=-2;
            p=1;}*/

}
void verific(int &e, int &d )
{
    int i,j,maxi=0;
    for(i=1;i<=4;i++)
    for(j=1;j<=4;j++)
    if(c[i][j]>maxi)
    {
        maxi=c[i][j];
        e=i;
        d=j;
    }

}
int caut(int a[8][8])
{
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            if(a[i][j]!=0)
            return 1;

            return 0;
}
void construct()
{
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        c[i][j]=vecini(i,j);
}
int main()
{int d,e;
    citire();
    bordare();
    int k=caut(a);
    while(k==1)
   {
       construct();
        verific(e,d);
        go(e,d,a);
        k=caut(a);
   }

    return 0;
}

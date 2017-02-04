#include <iostream>
using namespace std;
int a[5][5],n,v[17];

void citire()
{cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        if(v[i]%4==0&&v[i]/4==0)a[4][4]=1;
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
        else
            if(v[i]%4==0)a[v[i]/4+1][4]=1;
        else
            a[v[i]/4+1][v[i]%4]=1;
    }

}
int vecini(int i, int j)
{int k=0;
    if(a[i-1][j]==1)
        k++;
        if(a[i+1][j]==1)
            k++;
        if(a[i][j-1]==1)
            k++;
        if(a[i][j+1]==1)
            k++;
        return k;
}
 void parcurgere(int &c, int &d)
{
    int i,j,maxi=0,k;
    for(i=1;i<=4;i++)
    for(j=1;j<=4;j++)
       {
       k= vecini(i,j);
        if(k>maxi)
        {
            maxi=k;
            c=i;
            d=j;
        }
        }
}
void mole()
{int c,d;
    parcurgere(c,d);
    cout<<a[c][d]<<" ";
    if(a[c-1][d]==1)a[c-1][d]=0;
   // else
       // if(a[c-1][d]==0)a[c+1][d]=1;

    if(a[c+1][d]==1)a[c+1][d]=0;
  //  else
     //   if(a[c+1][d]==0)a[c+1][d]=1;

        if(a[c][d-1]==1)a[c][d-1]=0;
   // else
       // if(a[c][d-1]==0)a[c][d-1]=1;

        if(a[c][d+1]==1)a[c][d+1]=0;
    //else
  //      if(a[c][d+1]==0)a[c][d+1]=1;
  parcurgere(c,d);

}
int caut()
{int i,j,ok=0;
    for(i=1;i<=4&&ok==0;i++)
        for(j=1;j<=4&&ok==0;j++)
        if(a[i][j]==1)ok=1;
    return ok;
}
int main()
{
    citire();
    while(caut()==1)
        mole();


    return 0;
}

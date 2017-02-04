#include <iostream>
//#include <fstream>
using namespace std;
//ifstream f("date.in");
int n,i,k=1;
int v[101],a[101][101],cost=0;
void prime(int y)
{int mini,c;
v[1]=1;
//weight[y]=0;
int nearest[51];
int i;
   for( i=1;i<=n;i++)
     nearest[i]=y;
    while(k<n)
    {
        mini=9999;
        for(i=1;i<=n;i++)
            if(v[i]==0)
                if(a[i][nearest[i]]<=mini)
                    {
                        mini=a[i][nearest[i]];
                       c=i;

                    }
                    k++;
                           cout<<c<<" "<<y<<"\n";
                          cost+=mini;
                          v[c]=1;
                          for(i=1;i<=n;i++)
                            if(v[i]==0)
                          if(a[i][c]<a[i][nearest[i]])
                          nearest[i]=c;



    }
}
int main()
{
cin>>n;

for(i=1;i<=n;i++)
   {
       v[i]=0;
    for(int j=1;j<=n;j++)
    cin>>a[i][j];}

prime(1);
//for(i=1;i<=n;i++)
    cout << cost<< endl;
    return 0;
}

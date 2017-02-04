#include <iostream>
using namespace std;
int a[101][101],i,j,n;
void in(int v)
{int j=1;
    if(j<4)
    for(int i=v;i<=n;i++)
    {if(a[v][i]==1)
cout<<i<<" ";
       j++; in(i);
       break ;}
       return;
}

int main()
{cin>>n;
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)cin>>a[i][j];
    cout<<1<<" ";
    in(1);

    return 0;
}

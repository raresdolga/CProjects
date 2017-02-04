#include <iostream>

using namespace std;

int main()
{int n,s,a[101][101];
cin>>n>>s;
int i,j;
    for(j=1;j<=9;j++)
        a[1][j]=1;
    for(i=1;i<=n;i++)
    a[i][1]=i;
    for(i=2;i<=n;i++)
        for(j=2;j<=9;j++)
            a[i][j]=a[i-1][j]+a[i][j-1];
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=9;j++)
                cout<<a[i][j]<<" ";
                cout<<"\n";
            }

    return 0;
}

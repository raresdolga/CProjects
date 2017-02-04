#include <iostream>
#include <stdlib.h>
int n,i,m,a[501],c,s,k,b,s2;
using namespace std;

int main()
{cin>>n;
    for(i=1;i<=n;i++)
    {cin>>c;
    s=0; k=0; s2=0;
    for(int j=1;j<=c;j++)
    {cin>>b;
    s=s+b;
    a[k++]=b;
    }
     s=s/c;
     for(k=0;k<c;k++)
        s2=s2+abs(a[k]-s);
        cout<< s2 << "\n";
    }

    return 0;
}

#include <iostream>

using namespace std;
int a[101],ok, i,n;
int main()
{cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
do
{ok=1;
    for(i=1;i<n;i++)
if(a[i]>a[i+1])
    {a[0]=a[i];
    a[i]=a[i+1];
    a[i+1]=a[0];
        ok=0;
    }
}while(ok==0);
for(i=1;i<=n;i++)
    cout <<a[i] << endl;
    return 0;
}

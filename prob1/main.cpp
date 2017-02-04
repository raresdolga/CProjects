#include <iostream>
#include<fstream>
using namespace std;

int gcd(int a,int b)
{
    while(a!=b)
        if(a>b)a=a-b;
    else
        b=b-a;
    return a;
}
int main()
{int a,c,b,x[101],s=0,n;
cin>>n;
    x[1]=a;
    int i=1;
    for(i=1;i<=n;i++)
    cin>>x[i];
    a=x[1];
    for(i=2;i<=n;i++)
    {c=gcd(a,x[i]);

        a=c;

    }

    cout << c<<" ";
    for(int j=1;j<=n;j++)
        s=s+x[j]/c;
    cout<<s;
    return 0;
}

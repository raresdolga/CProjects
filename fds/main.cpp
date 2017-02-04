#include <iostream>

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
{int v[101],b,i,n,c;
cin>>n>>b;
for(i=1;i<=n;i++)
{cin>>v[i];
c=gcd(b,v[i]);
b=c;
}

     cout << c << endl;
    return 0;
}

#include <iostream>
using namespace std;
int prime(int a)
{
    int d;
    for(d=2;d<=a/2;d++)
        if(a%d==0)return 0;
    return 1;
}
int main()
{
    int a,n,b,i=1;
    cin>>a>>n;
    while(i<=n)
   {

   if(prime(a)==1)
    {
        b=a+1;
        while(prime(b)==0)
            b++;
            cout<<a<<" "<<b<<"\n";
            i++;
            a=b;
    }
    else
        a++;
   }

    return 0;
}

#include <iostream>
using namespace std;
int long v[31338];
int a;
void read_construct(int &a,int long &n, int long v[])
{int i;
    cin>>a>>n;
    v[a]++;
    for(i=1;i<n;i++)
    {
     a*=31334;
     a%=31337;

     v[a]++;

    }

}
int main()
{
    int long n=0;
    int long i=0;
    int long k=0;
read_construct(a,n,v);
    while(i<=a)
       {
           if(v[i]!=0)
            k=k+v[i];
            i++;
       }
    cout<<k;
    return 0;
}

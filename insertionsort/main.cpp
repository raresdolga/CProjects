#include <iostream>

using namespace std;
int i,n,j,aux,v[101],ok;

int main()
{cin>>n;
for(i=1;i<=n;i++)
    cin>>v[i];
        for(i=2;i<=n;i++)
        {
            aux=v[i];
            j=i-1;
            while(j>0&&v[j]>aux)
{
    v[j+1]=v[j];
    j--;

v[j+1]=aux;}
        }
        for(i=1;i<=n;i++)
    cout <<v[i]<<" ";
    return 0;
}

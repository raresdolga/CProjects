#include <iostream>
using namespace std;
void read_construct(int &a,int long &n, int long v[])
{int i;
    cin>>a>>n;
    v[0]=a;
    for(i=1;i<n;i++)
    v[i]=(v[i-1]*31334)%31337;
    a=v[n-1];
}
int pivot(int long v[],int long i, int long j)
{int long  p;
    int long k;
    p=i;
    for(k=i;k<j;k++)

        if(v[k]<v[j])
        {
            swap(v[p],v[k]);
            p++;
        }
        swap(v[p],v[j]);
        return p;

}
void quick(int long v[],int long  i,int long j)
{int p;
if(i<j)
   {
    p=pivot(v,i,j);
    quick(v,i,p-1);
    quick(v,p+1,j);
   }
   else
    return ;
}
int main()
{
    int long n=0;
    int a;
    int long v[1793233];
    read_construct(a,n,v);
    quick(v,0,n-1);
    int long i=n-1;

    while(i>0&&v[i]!=a)
        i--;
    cout<<i;
    return 0;
}

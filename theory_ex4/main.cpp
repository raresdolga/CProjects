#include <iostream>
using namespace std;
int a[101][101];
int sum( int i,int j)//sum for the numbers with i-1 digits 10 in 3 digits 1(in 2 digits)+9 or 2(in 2 digits)+8...
{
    int s=0;
    for(int k=j;k>=j-9;k--)//11(din 3 cifre)= 11(din 2 cifre)+0; 11(3 cifre)=10(2 cifre)+1 ;...11(3 cifre)=1(din 2 cifre) +10;
  {
    s=s+a[i][k];
  }
return s;
}

int main()
{
int n,s,k;
cin>>n>>s;
int i,j,p;
    for(i=1;i<=9;i++)
    a[1][i]=1;

    for(i=1;i<=n;i++)
{
    a[i][1]=i;
    a[i][0]=1;
}
    for(i=2;i<=n;i++)
        for(j=2;j<=9;j++)
           {
            a[i][j]=a[i-1][j]+a[i][j-1];
           }
        for(i=2;i<=n;i++)
            for(j=10;j<=s;j++)
                a[i][j]=sum(i-1,j);//dinamicaly construct the cases
    cout << a[n][s]<< endl;
    return 0;
}

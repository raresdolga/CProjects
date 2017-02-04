#include <iostream>
#include<string.h>
using namespace std;
int T,v[11];
char a[11][100001];
 int delet(char b[])
 {
     int k=0;
     int i=0;
     while(i<strlen(b)-1)
     {
         if(b[i]==b[i+1])
            k++;
            i++;
     }
     return k;
 }
int main()
{cin>>T;
for(int i=1;i<=T;i++)
{
    cin>>a[i];
    v[i]=delet(a[i]);
}
for(int j=1;j<=T;j++)
cout<<v[j]<<"\n";
    return 0;
}
int n=seatPrices_rows;
    int m=seatPrices_cols;
    int mini=99999;
    int k=0,ok=0,i,j=1,s;
     for( i=1;i<=n;i++)
        while(j<=m&&(j+requiredSeats<=m))
        {ok=0; s=0;k=0;
        while(k<=requiredSeats&&ok==0)
            {
            if(seatPrices[i][j]!=-1)
            {
                s=s+seatPrices[i][j];
                j++;
                k++;
            }
             else
             ok=1;
            }
         if(ok==0)
         {
             if(mini<s)mini=s;
             j=j-requiredSeats-1;
         }

    }
return mini;

}

    int m=seatPrices_size_rows;
    int n=seatPrices_size_cols;
    int *a= (int *)malloc(m*n*sizeof(int));
    int mini=9999;
    int i,j;

    for( i=1;i<=m;i++)
         for(j=1;j<=n;j++)
     {
         if(seatPrices[i][j]==-1)seatPrices[i][j]=99999;

     }
     for( i=1;i<=m;++i)
         for(j=1;j<=n;++j)
     a[i][j]=a[i][j-1]+seatPrices[i][j];

    for( i=1;i<=m;++i)
         for(j=requiredSeats;j<=n;++j)
    if(a[i][j]-a[i][j-requiredSeats]<mini)mini=a[i][j]-a[i][j-requiredSeats];
    return mini;

}

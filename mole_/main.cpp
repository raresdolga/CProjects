#include <iostream>
#include<vector>
using namespace std;
int <vector>v[1<<16],a[1<<16],b[1<<16];
void total_vecini()
{
    for (i=1;i<1<<16;i++)
    {
        l=0;
        for (j=0;j<16;j++)
            if (i & (1<<j))
             a[j]=1;
          else
            a[j]=0;
        for (j=0;j<16;j++)
        if (a[j]==1)
        {
            nr=0;
            for (z=0;z<16;z++)
            b[z]=a[z];
            b[j]=1-a[j];
            if (j+4<=15)
                b[j+4]=1-a[j+4];
            if (j-4>=0)
                b[j-4]=1-a[j-4];
            if (j%4==1 || j%4==2){
                b[j+1]=1-a[j+1];
                b[j-1]=1-a[j-1];
            }
            if (j%4==0)
                 b[j+1]=1-a[j+1];
            if (j%4==3)
                b[j-1]=1-a[j-1];
            for (z=0;z<16;z++)
                if (b[z]==1)
                 nr=nr+(1<<z);
            v[i].push_back(make_pair(nr,j));
        }
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

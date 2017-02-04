#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream f("test.in");
ofstream g("test.out");
int l,i,j,MAX,a[20],d[1<<16],u[1<<16],nr,z,r,last[1<<16],b[20],x,t,dl[]={0,-1,1,0,0},dc[]={0,0,0,-1,1},sol[116161];
vector <pair <int,int > > v[1<<16];
queue <int> Q;
int main()
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
                if (b[z])
                 nr=nr+(1<<z);
            v[i].push_back(make_pair(nr,j));
        }
    }
    while (f>>i)
        t+=(1<<(i-1));
    for (i=0;i<(1<<16);i++)
        d[i]=200000000;
    d[t]=0;
    Q.push(t);
    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();
        for (j=0;j<v[x].size();j++)
            if (d[v[x][j].first]>d[x]+1)
              d[v[x][j].first]=d[x]+1,last[v[x][j].first]=x,u[v[x][j].first]=v[x][j].second,Q.push(v[x][j].first);
    }
    x=0;
     while(x!=t)
     {
         sol[++r]=u[x]+1;
         x=last[x];
     }
     for (i=1;i<=r;i++)
        g<<sol[i]<<' ';
    return 0;
}

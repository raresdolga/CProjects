#include <iostream>
#include<queue>
using namespace std;
queue <int> q;
int n, a[101][101],visited[101];
void construct(int v[101])
{
    cin>>n;
    for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=n;j++)
        cin>>a[i][j];
    v[i]=0;
       }
}
void breadth(int x)
{
    construct(visited);
    q.push(x);
    visited[x]=1;
    while(q.empty()==0)
    { x=q.front();
        cout<<x<<" ";

     q.pop();
     for(int i=1;i<=n;i++)
        if(a[x][i]==1&&visited[i]==0)
     {
         q.push(i);
         visited[i]=1;
     }
    }

}
int main()
{int x;
cin>>x;
breadth(x);

    return 0;
}

#include <iostream>
#include<stack>
std::stack<int> s;
using namespace std;
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
void depthfirst(int x, int visited[101])
{s.push(-1);
    construct(visited);
    s.push(x);
    while(s.top()!=-1)
    { cout<<s.top()<<" ";
        s.pop();
              visited[x]=1;
        for(int i=n;i>=1;i--)
            if(a[x][i]==1&&visited[i]==0)
        {
            s.push(i);
            x=i; // move to the next element
        }
   }

}
int main()
{int x;
cin>>x;
    depthfirst(x, visited);
    return 0;
}

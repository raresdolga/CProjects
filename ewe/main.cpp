#include <iostream>
#include<stack>
using namespace std;
int grid[101][101],i,j,k,visited[101][101];
stack<int> st;
int maximum=0;
int dx[]={-1,0,1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
int m,n;
void neighbour(int grid[101][101], int a, int b)
    {
    int k=0;
    int number=0,j;

    //v[k].e=b;

    k=a*10+b;
    st.push(k);

    while(st.empty()==0)
   {   number ++;

   k=st.top();
visited[k/10][k%10]=1;
   cout<<k/10<<" "<<k%10<<"\n";
    st.pop();
    for( j=1;j<=8;j++)
    if((a+dx[j])<=n&&((b+dy[j])<=m)&&(a+dx[j])>=1&&(b+dx[j])>=1)
    {

     k=(a+dx[j])*10+(b+dy[j]);
    if(grid[a+dx[j]][b+dy[j]]==1&&visited[k/10][k%10]==0)
    {

     //v[k].c=(a+dx[j]);
     //v[k].e=(b+dy[j]);
    st.push(k);


    }
   }
    if(number>maximum)maximum=number;
}
}


int main()
{

    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        cin>>grid[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(grid[i][j]==1)
        neighbour(grid,i,j);
        cout<<maximum;
    return 0;
}

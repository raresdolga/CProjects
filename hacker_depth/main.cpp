
#include <stack>
#include <string>
#include <vector>

#include <cstring>
#include <cstdlib>
#include <fstream>

#include <iostream>

using namespace std;
stack<int> st;

/*struct go
    {
    int c;
    int e;

}v[101];*/
int maximum=0;
int dx[]={-1,0,1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};

void neighbour(vector< vector<int> > grid, int a, int b)
    {
    int k=0;
    int number=0,j;
    int l=grid[1].size();
    int m=grid.size();
    //v[k].c=a;
    //v[k].e=b;
    k++;
    st.push(k);
    while(st.empty()==0&&k<=4)
   {   number ++;
    st.pop();
    for( j=1;j<=8;j++)
    if((a+dx[j])<=l&&((b+dy[j])<=m)&&(a+dx[j])>=1&&(b+dx[j])>=1)
    if(grid[a+dx[j]][b+dy[j]]==1)
    {
     //v[k].c=(a+dx[j]);
     //v[k].e=(b+dy[j]);
    st.push(k);
        k++;
    }
   }
    if(number>maximum)maximum=number;
}

int get_biggest_region(vector< vector<int> > grid)
{
    int l=grid[1].size();
    int m=grid.size();
    for(int i=1;i<=l;i++)
        for(int j=1;j<=m;j++)
        if(grid[i][j]==1)
        neighbour(grid,i,j);
        return maximum;

}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}

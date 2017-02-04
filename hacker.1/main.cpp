#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
stack<int> st;
int k=0;
struct go{
    int c;
    int b;
}b[101];
int dx[]={-1,0,1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
void neighbour(vector< vector<int> > grid, int a,int b)
    {
    int l=grid[1].size();
    int m=grid.size();
    for(int i=1;i<=8;i++)
    for(int j=1;j<=8;j++)
    if((a+dx[i])<=l&&((b+dy[j])<=m))
    if(grid[a+dx[i]][b+dy[j]]==1)
{
        b[k].c=(a+dx[i])*10+(b+dy[j]);
    st.push(b[k].c);
        k++;
}

}
int get_biggest_region(vector< vector<int> > grid) {


int l=grid[1].size();
int m=grid.size();
return 0;

}

int main(){
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

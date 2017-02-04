#include <iostream>
using namespace std;
struct var{
char shape;
int r,c;}v[4];
void draw(char c,int m,int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {for(j=1;j<=m;j++)
        cout<<c;
        cout<<"\n";
    }
}


int main()
{int n;
    cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>v[i].shape>>v[i].r>>v[i].c;
}
   for(int i=1;i<=n;i++)
    draw(v[i].shape,v[i].r,v[i].c);
    return 0;
}

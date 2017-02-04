#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int l=2,n,p=1; vector < pair< int, int> >v[30];
queue <int > Q;
struct nod
{
int d[30];
int f[25];
}b[16];

void citire()
{
    int a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
            b[l-1].f[a+4]=1;//primele 4 si ultimele 4 de bordare
    }
    Q.push(l-1);
}
 void copy1(int l)
 {
     for(int i=1;i<=24;i++)
        b[l].f[i]=b[l-1].f[i];
 }
    void neighbours(int i,int l)
    {

            b[l].f[i]=1-b[l].f[i];
            b[l].f[i-1]=1-b[l].f[i-1];
            b[l].f[i+1]=1-b[l].f[i+1];
            b[l].f[i-4]=1-b[l].f[i-4];
            b[l].f[i+4]=1-b[l].f[i+4];

    }

    void link(int f[25])
    {
         int i,nr,p=2;
        for(i=1;i<=24;i++)
             b[l-1].d[i]=0;
        while(Q.empty()==0)
         {
            nr=0;
         for(i=5;i<=20;i++)
            if(b[l-1].f[i]==1)
            {
                copy1( l);
                neighbours(i,l);
                p=i*10+(l-1);
                Q.push(p);
                b[l].d[i]=
        nr=0;
            }
            Q.pop();
        l=p;
         }
    }
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

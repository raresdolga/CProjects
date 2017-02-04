#include <iostream>
#include<queue>
using namespace std;
    queue<int> q;
int l=2,n;
struct nod
{
    int c[6][6];
    int branch, column,line;
}b[1<<16];
void bordare(int l)
{
    int i;
    for(i=0;i<=5;i++)
        {
            b[l].c[i][0]=-1;
            b[l].c[i][5]=-1;
        }
         for(i=1;i<=4;i++)
         {
             b[l].c[0][i]=-1;
            b[l].c[5][i]=-1;
         }

}
void citire()
{int a,p,i,j;
    cin>>n;
    for( i=1;i<=n;i++)
    {
        cin>>a;
            if(a%4==0)b[1].c[a/4][4]=1;
        else
            b[1].c[a/4+1][a%4]=1;
    }

    bordare(1);
    for( i=1;i<=4;i++)
        for( j=1;j<=4;j++)
        if(b[1].c[i][j]==1)
        {
        p=(10+i)*10+j;
        q.push(p);
        }
        b[l].branch=1;
        b[l].column=1;
        b[l].line=1;


}
void equa(int l, int p)//b[l]=b[p];
{
    for(int i=0;i<=5;i++)
        for(int j=0;j<=5;j++)
        b[l].c[i][j]=b[p].c[i][j];
}

    void neighbours(int i, int j, int l)
    {
        b[l].c[i][j]=0;
        if(b[l].c[i-1][j]==1)
     b[l].c[i-1][j]=0;
     else
      b[l].c[i-1][j]=1;
     if(b[l].c[i+1][j]==1)
        b[l].c[i+1][j]=0;
        else
            b[l].c[i+1][j]=1;
            if(b[l].c[i][j-1]==1)
            b[l].c[i][j-1]=0;
        else
            b[l].c[i][j-1]=1;
            if(b[l].c[i][j+1]==1)
            b[l].c[i][j+1]=0;
        else
          b[l].c[i][j+1]=1;
           }

    void link()
    {
        int t;
        int i,ok=0,k,x,o=1,p,m,j;
        while(ok==0)
        {
            o=1;
            x=q.front();
            cout<<x<<" ";
            equa(l,x/100);//nivelul pt b[l]
             k=x%10;
             p=(x/10)%10;
             neighbours(p,k,l);
             for(i=1;i<=4;i++)
                for(j=1;j<=4;j++)
                    if(b[l].c[i][j]==1)
                    {
                        t=(l*10+i)*10+j;//pun in coada trei elemente sub forma unuia : tatal de nivel si coordonatele nodului
                        q.push(t);
                        o=0;

                    }
                   b[l].branch=x/100;
                        b[l].column=x%10;
                        b[l].line=(x/10)%10;
                    if(o==1) ok=1;
                    l++;
                        q.pop();

     }
    m=x/100;
     while(m>0)
     {
         cout<<b[m].line<<" "<<b[m].column<<" ";
         m=b[m].branch;
     }

    }
int main()
{   citire();
link();

    return 0;
}

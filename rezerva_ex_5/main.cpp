#include <iostream>

using namespace std;

    void link()
    {
        int t=1;
        int i,ok=0,k=1,x,o;
        while(ok==0)
        {
            t=1;
                  while(t<=b[l-1].o)
            {   x=q.front();
                equa(l,t);
                neighbours(i,j,l);
                t++;
                 for(i=1;i<=4;i++)
                for(int j=1;j<=4;j++)
                    if(b[l].c[i][j]==1)
                    {
                        q.push(b[l].c[i][j]);
                        b[l].p++;
                    }
                b[l].d[p]=x;
                l++;

        }
    t=t-
        }
     }

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

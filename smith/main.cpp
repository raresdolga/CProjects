#include <iostream>
using namespace std;
 int i,n,a,b,s,ok;
    int suma(int m)
    {int s=0;
        while(m!=0)
        {
            s+=m%10;
            m=m/10;
        }
        return s;
    }
  int smith( int c)
  {int d=2,s1=0;
      while(c>1)
      if(c%d==0)
             while(c%d==0) {c=c/d; s1=s1+suma(d);}
      d++;

                return s1;}
int main()
{cin>>n;

for(int i=1;i<=n;i++)
   {

    cin>>a;
    do{s=0;    b=a;


    if(smith(a)==suma(b))ok=1;
    else a++;}
    while(ok==0);
    cout <<a<<"\n";
    }

return 0;
}

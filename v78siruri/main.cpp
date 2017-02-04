#include <iostream>
#include<cstring>
using namespace std;
char s[101],c[101],x[101],a[101],*p;
int main()
{cin.get(c,101);
    cin.get();
    cin.get(s,101);
    strcpy(x,c);
    strcat(x,"?");
    p=strstr(s,c);
    while(p!=0)
    {strcpy(a,s+p+strlen(c));
    strcpy(s+p,x);
    strcat(s+p,a);
p=strstr(a,c);
    }
    cout << s << endl;
    return 0;
}

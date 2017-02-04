#include <iostream>
#include <cstring>
using namespace std;
 int n;
 char s1[20]="absolvent",s2[21]="absolvent";
int main()
{cin>>n;
    for(int i=0;i<strlen(s1);i++)
       if(strcmp(s2,s1+i)<0)
       strcpy(s2,s1+i);
    cout << s2 << endl;
    cout<<n;
    return 0;
}

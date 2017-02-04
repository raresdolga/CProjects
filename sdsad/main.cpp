#include <iostream>
#include<string.h>
using namespace std;

char a[10],c[10];
int main()
{
cin.get(a,11);
strncpy(c,a,3);
    cout << c<< endl;
    return 0;
}

#include <iostream>
using namespace std;
float b[101];
int iterations=n
int main()
{
    double * x = new double [rows];
double sum = 0;

for (int l = 0; l < rows; l++)
x[l] = 0;

while(iterations--)
{
for(int i = 1; i <= rows; i++)
{
sum = b[i-1];
for(int j = 1; j <= rows; j++)
{
if( i != j )
{
sum = sum - (el[i][j] * x[j-1]);
}
}
x[i-1] = sum/el[i][i];
}
}

    cout << "Hello world!" << endl;
    return 0;
}

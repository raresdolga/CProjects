#include <stdio.h>
#include <stdlib.h>

int main()
{int i,v[101],n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
    for(i=1;i<=n;i++)
    printf("%d\n",v[i]);
    return 0;
}

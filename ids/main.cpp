#include <iostream>
using namespace std;
int parent[101], key[101],left1[101],right1[101];
int root =1;
void insert1(int z)
{
    int y;
    int x=root;
    while(x!=0)
    {
        y=x;
        if(key[z]<key[x])
            {
                x=left1[x];
            }
        else
           {

            x=right1[x];
           }
    }
    parent[z]=y;
    if(key[y]>key[z])
        left1[y]=z;
    else
        right1[y]=z;

}
int  minim(int x)
{
    if(left1[x]!=0)
        return minim(left1[x]);
        else
        return x;
}
int succesor(int x)
{

    if(right1[x]!=0)
        return minim(right1[x]);

        int y=parent[x];

        while(y!=0&&right1[y]==x)
        {
            x=y;
            y=parent[y];
        }
        return y;

}
void deletetion(int x)
{
    int z=0,y=0;
    if(right1[x]==0||left1[x]==0)
        y=x;
    else
        y =succesor(x);
    if(left1[y]!=0)
        z=left1[y];
    else
        z=right1[y];
    if(z!=0)
    parent[z]=parent[y];
    if(parent[y]==0) cout<<" now z is the root of the tree";

    if(left1[parent[y]]==y)
        left1[parent[y]]=z;
    else
        right1[parent[y]]=z;

    if(y!=x) key[x]=key[y];
}
void treeInOrder(int x)
{
    if(x!=0)
        {
        treeInOrder(left1[x]);
        cout<<key[x]<<" ";
        treeInOrder(right1[x]);
        }

}

int main()
{
    int i=2,n,a,b;// trebe initialiat cu 0 vectorii;
    cin>>n;
    cin>>b;
    key[root]=b;
    parent[root]=0;
    left1[root]=0;
    right1[root]=0;
    //deja initializate global cu 0;
    while(i<=n)
    {
        cin>>a;
        left1[i]=0;
        right1[i]=0;
        key[i]=a;
        insert1(i);
        i++;
    }

   deletetion(3);
   treeInOrder(root);
   cout<<"\n";
   for(int j=1;j<i;j++)
    cout<<key[parent[j]]<<" ";
    cout<<"\n";
    treeInOrder(root);
    return 0;
}


int n;

 void swapEl(int *a, int *b)
{
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;

}

void insert_heap(int key,int* heap_array)
{

   // heap_array= realloc(heap_array,(n+1)*sizeof(int)); // add a new space in memory
    *(heap_array+(n))=key;

    int i=n;
    int p=0;

    while(i>0)
    {
        //start from index 0 do child1=2i+1; child2=2i;
        p=(i-1)/2;//solve equation find the parent
        if(*(heap_array+p)<*(heap_array+i))//parent smaller then children
            break;
        swapEl(heap_array+p,heap_array+i);
        i=p;
    }
    n+=1;
}

int delete_heap(int *heap_array)
{

    swapEl(heap_array+n-1,heap_array);
   //realloc(heap_array,(n-1)*sizeof(int));// delete last element

    int p=0;//parent
    int i=0;//child
    n-=1;
    while(p<n)
    {

        i=2*p+1;
        if(i>=n)
            break;
        if(i+1<n)
        if(*(heap_array+i)>*(heap_array+i+1))//take the smallest of the children
        i+=1;

        if(*(heap_array+i)>*(heap_array+p)) // property ok =>finish
            break;

        swapEl(heap_array+i,heap_array+p);
        p=i;
    }
    return *(heap_array+n);
}

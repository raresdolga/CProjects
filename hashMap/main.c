#include <stdio.h>
#include <stdlib.h>
typedef struct link{
  char *string;
  struct  link *next1;
}chainelement;

 typedef struct listTable{
 int size;
 chainelement *p;
 }table_;

 void construct(int size)
 {
    table_ *newTable=(table_*)malloc(sizeof(table_));

 }
int main()
{
    printf("Hello world!\n");
    return 0;
}

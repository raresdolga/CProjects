#include <stdio.h>
#include <stdlib.h>
struct name
{int marks;
char subject[30];
};
int main()
{struct name *ptr;
int i, numberOfRecords;
printf("Enter number of records: ");
scanf("%d",&numberOfRecords);
ptr=(struct name*)malloc(numberOfRecords*sizeof(struct name));
for(i=0;i<numberOfRecords;i++)
{
    printf("enter name of the subject and marks:\n");
    scanf("%s %d",&(*(ptr+i)).subject,&(*(ptr+i)).marks);
}
printf("\n");
    for(i=0;i<numberOfRecords;i++)
printf("%s\t%d\n",(ptr+i)->subject,(ptr+i)->marks);
    return 0;
}

#include <stdio.h>
#include <string.h>   /* for all the new-fangled string functions */
#include <stdlib.h>     /* malloc, free, rand */


const int Fsize=50;
int no_edges;
int no_nodes;
int i;
const int cases=10;
int filter1(char *g)
{
    int i,nr=0,x=0;
    for(i=0;i<strlen(g);i++)
        if(*(g+i)=='(')nr++;
    else
        if(strchr(">v^",*(g+i))!=0)x++;
    if(nr!=x)return 0;
    return 1;
}
int filter2(char *g)
{
    int i,nr=0;
 for(i=0;i<strlen(g);i++)
        if(*(g+i)=='(')nr++;
    else
        if(*(g+i)==')')nr--;
    if(nr!=0)return 0;
}
void coppy(int i, char *nm, char k[101], char p[101]) //copy q in k and w in p from the formula (q bin_connective p)
{               int j=0;
                while(j<=i-2) // string until bin_connective
                {
                    *(k+j)=*(nm+1+j);
                    j+=1;
                }

                *(k+j)=NULL;
                 j=0;
                while(*(nm+i+2+j)!=NULL) // last bracket in the initial string must not be copied in p
                {*(p+j)=*(nm+i+1+j); j++;}
                *(p+j)=NULL; // put the terminator for the string
}
int parse(char *g)
{/* return 1 if atomic, 2 if  neg, 3 if binary, 4 if exists, 5 if for all, ow 0*/
    int nr=0,i=0,x=0,ok=0;
    int bin =0,c;
    if(filter1(g)==0)return 0;
    if(filter2(g)==0)return 0;
    nr=1;
    x=0;
    char d,k[101],p[101];//left and right substrings for binary connnective case
          if(*g=='(')
        {
            i=1;x=0;nr=0;
            while(*(g+i)!=NULL&&ok==0)
            {
            if(*(g+i)=='(')nr++;
            else
                if(*(g+i)==')')x++;
                i++;
               if(nr==x){
                    if(strchr("v^>",*(g+i))!=0) {c=i; d=*(g+i);ok=1;}
            }
        }
        if(d!=NULL)
        {
            coppy(i,g,k,p);
            if(parse(k)!=0&&parse(p)!=0)return 3;
        }
        }

       else
            if(*g=='A'&&parse(g+2)!=0)
        {
            if(strchr("xyz",*(g+1))!=0)
               {
                return 5;

               }
        }
            else
            if(*g=='E'&&parse(g+2)!=0)
        {
            if(strchr("xyz",*(g+1))!=0)
                {
                return 4;
                }
                else
              if(parse(g+2)==0)  return 0;
        }
        else
            if(*g=='-'&&parse(g+1)!=0)
                {
                    return 2;
                }
       else
           // if(strchr(">v^",*(g+5))!=0)

           if(*g=='X')
                {
                    if(!((*(g+1))=='['&&(strchr("xyz",(*(g+2)))!=0&&(strchr("xyz",(*(g+3))))!=0&&(*(g+4))==']')))
                    return 0;
                    else
                    {if(*(g+5)!=NULL)
                       {    if(*(g+5)=='-') return 0;

                       }
                       else
                        return 1;
                    }

                       }
                       else return 0;

}

void construct(int a[3][3],int edges[no_edges][2]) // make a matrix of adjacency for the graph using the adjacency list
{
    int i,j;
 for(i=0;i<=2;i++)
        for(j=0;j<=2;j++)
        a[i][j]=0;
 for(i=0;i<no_edges;i++)
    a[(edges[i][0])][(edges[i][1])]=1;
}

int binary1(int i, char *nm, int edges[no_edges][2], int size, int V[3])
{char k[101],p[101];
    int fml=0;
coppy(i,nm,k,p);

                    if(*(nm+i)=='^')fml=(eval(k,edges,size,V)&&eval(p,edges,size,V));
                    else
                    if(*(nm+i)=='v'){fml=(eval(k,edges,size,V)||eval(p,edges,size,V));  }
                    else
                    if(*(nm+i)=='>')
                    {
                        if(eval(k,edges,size,V)==1)
                            {if(eval(p,edges,size,V)==0) fml=0;
                        else
                                                         fml=1;
                            }
                            else fml=1;
                    }
                    return fml;
}

int eval(char *nm, int edges[no_edges][2], int size, int V[3])
{/* returns 1 if formla nm evaluates to true in graph with 'size' nodes, no_edges edges, edges stored in 'edges', variable assignment V.  Otherwise returns 0.*/

int a[3][3],i,j,c;
char d;
int nr, x;
int ok=0;

        construct(a,edges);

    if(*nm=='X')
    {
        i=*(nm+2)-'0'-72;
        j=*(nm+3)-'0'-72;
        if(a[V[i]][V[j]]==1)return 1;
        else
            return 0;
    }
    else
        if(*nm=='-')return (1-eval(nm+1,edges,size,V));
    else
        if(*nm=='(')
        {
            i=1;x=0;nr=0;
            while(*(nm+i)!=NULL&&ok==0)
            {
            if(*(nm+i)=='(')nr++;
            else
                if(*(nm+i)==')')x++;
                i++;
               if(nr==x){
                    if(strchr("v^>",*(nm+i))!=0) {c=i; d=*(nm+i);ok=1;}
            }
        }
 return binary1(c,nm,edges,size,V);
        }
    else
        if(*nm=='A')
        {
            ok=1;
            for(i=0;i<size;i++)
               {
                V[*(nm+1)-'0'-72]=i;
            if(eval(nm+2,edges,size,V)==0) ok=0;
               }
               if(ok==1)return 1;
               else return 0;
        }
    else
         if(*nm=='E')
        {
            ok=1;
            for(i=0;i<size;i++)
               {
                V[*(nm+1)-'0'-72]=i; // make from the characters x,y,z indices
            if(eval(nm+2,edges,size,V)==1) ok=0;
               }
               if(ok==0)return 1;
               else
                return 0;        }

}

int main()
{
  char *name=malloc(Fsize); /*create space for the formula*/
  FILE *fp, *fpout;

  /* reads from input.txt, writes to output.txt*/
 if ((  fp=fopen("input.txt","r"))==NULL){printf("Error opening file");exit(1);}
  if ((  fpout=fopen("output.txt","w"))==NULL){printf("Error opening file");exit(1);}

  int j;
  for(j=0;j<cases;j++)
    {
      fscanf(fp, "%s %d %d",name,&no_nodes,&no_edges);/*read number of nodes, number of edges*/
      int edges[no_edges][2];  /*Store edges in 2D array*/
      for(i=0;i<no_edges;i++)	 fscanf(fp, "%d%d", &edges[i][0], &edges[i][1]);/*read all the edges*/

      /*Assign variables x, y, z to nodes */
      int W[3];
      /*Store variable values in array
	value of x in V[0]
	value of y in V[1]
	value of z in V[2] */
      for(i=0;i<3;i++)  fscanf(fp, "%d", &W[i]);
      int p=parse(name);
      switch(p)
	{case 0:fprintf(fpout,"%s is not a formula.  ", name);break;
	case 1: fprintf(fpout,"%s is an atomic formula.  ",name);break;
	case 2: fprintf(fpout,"%s is a negated formula.  ",name);break;
	case 3: fprintf(fpout,"%s is a binary connective formula.  ", name);break;
	case 4: fprintf(fpout,"%s is an existential formula.  ",name);break;
	case 5: fprintf(fpout,"%s is a universal formula.  ",name);break;
	default: fprintf(fpout,"%s is not a formula.  ",name);break;
	}

      /*Now check if formula is true in the graph with given variable assignment. */
      if (parse(name)!=0){
	if (eval(name, edges, no_nodes,  W)==1)	fprintf(fpout,"The formula %s is true in G under W\n", name);
	else fprintf(fpout,"The formula %s is false in G under W\n", name);
      }
    }



  fclose(fp);
  fclose(fpout);
  free(name);
  return(0);
}



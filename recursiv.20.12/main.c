#include <stdio.h>
#include <string.h>   /* for all the new-fangled string functions */
#include <stdlib.h>     /* malloc, free, rand */


const int Fsize=50;
int no_edges;
int no_nodes;
int i;
const int cases=10;

int parse(char *g)
{/* return 1 if atomic, 2 if  neg, 3 if binary, 4 if exists, 5 if for all, ow 0*/
    int nr=0,i=0,x=0;
    int bin =0;
    int ok=0;
    char *k,*p;
    for(i=0;i<strlen(g);i++)
        if(*(g+i)=='(')nr++;
    else
        if(*(g+i)==')')nr--;
    if(nr!=0)return 0;
    nr=1;
    x=0;
        if(*g=='(')
        {
            i=1;
            while(*(g+i)!=NULL)
                {
                    if(*(g+i)==')')
                        {
                            x++;
                            ok=1;
                        }
                    else
                    if(*(g+i)=='(')nr++;
                    i++;
            if(nr==x+1&&ok==1)
               {
                if(strchr(">^v",*(g+i))!=0)
               {

                strncpy(p,g+1,i-2);
                strcpy(k,g+i+1);
                strncpy(k,k,strlen(k)-1);
                if(parse(k)!=0&&parse(p)!=0)return 3;
               }
               else
                return 0;
               }
               else
               if(x==1)
                {
                    if(strchr((g+i),'>')!=0||strchr((g+i),'v')!=0||strchr((g+i),'^')!=0)
                    if(parse(strncpy(p,g,i-1))&&parse(strncpy(p,g+i+1,5))) return 3;

                }
                }
        }
       else
            if(*g=='A'&&parse(g+2)!=0)
        {
            if(strchr("xyz",*(g+1))!=0)
               {
                if(bin==0)
                return 5;


               }
               // else
              // if(parse(g+2)==0) return 0;
        }
        else
            if(*g=='E'&&parse(g+2)!=0)
        {
            if(strchr("xyz",*(g+1))!=0)
                {
                if(bin==0)
                return 4;
                }
                else
              if(parse(g+2)==0)  return 0;
        }
        else
            if(*g=='-'&&parse(g+1)!=0)
                {
                    if(bin==0)return 2;
                    else
                    if(parse(g+2)==0) return 0;

                }
       else
           // if(strchr(">v^",*(g+5))!=0)

           if(*g=='X')
                {
                    if(!((*(g+1))=='['&&(strchr("xyz",(*(g+2)))!=0&&(strchr("xyz",(*(g+3))))!=0&&(*(g+4))==']')))
                    return 0;
                    else
                    {if(*(g+5)!=NULL)
                       {

                        if(strchr(">v^",*(g+5))!=0) bin=3;
                       }
                       else
                        if(bin==0) return 1;
                    }

                       }

return 0;
}



int eval(char *nm, int edges[no_edges][2], int size, int V[3])
{/* returns 1 if formla nm evaluates to true in graph with 'size' nodes, no_edges edges, edges stored in 'edges', variable assignment V.  Otherwise returns 0.*/


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



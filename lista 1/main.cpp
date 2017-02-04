#include <iostream>
using namespace std;
struct Nod
      {int info;
       Nod *next;
       };

Nod *prim, *ultim;
/*************************************************************************
 functiile de creare si adaugare se pot comprima intr-o singura functie
 care poate testa daca exista un prim nod si in functie de rezultatul testului
 va realiza alocarea primului nod sau se va adauga un nou nod la sfarsit
 *************************************************************************/
void creare_adaugare()
    {if(prim==NULL)
      {prim=new Nod;
       cout<<"introduceti valoarea retinuta in primul nod:";
       cin>>prim->info;
 prim->next=0; //la crearea listei va  exista un singur nod, primul      //                 si prin urmare adresa urmatoare lui este 0
ultim=prim; //evident, avand un singur element acesta va fi si primul                                                                                                                                                                 //            si ultimul
       }
     else
       {Nod *c;
      c=new Nod;
      cout<<"valoarea de adaugat in lista ";
      cin>>c->info;
      ultim->next=c; //se "agata" noul nod c, dupa ultimul din lista
      ultim=c; //evident noul nod e ultimul...
      ultim->next=0;//...si dupa ultimul nu e nimic, deci nici o adresa
      }
    }
    void listare()
   {Nod *c;
    c=prim;
    while(c!=0)//cat timp mai sunt in lista
      {cout<<c->info<<"  ";
       c=c->next;//avansez in lista trecand la urmatoarea adresa
       }
    cout<<endl;
       }

int main()
{
    creare_adaugare();
    listare();
    return 0;
}

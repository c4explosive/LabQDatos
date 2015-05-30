//Comentario
#include <stdio.h>
#include <stdlib.h>
typedef struct col 
{
    int *cola;
    int capacity;
    int tam;
    int* frente;
    int* final;
    int nfr,nfi;
}cl;

//Create
cl * create(int maxE)
{
   cl *Q=malloc(sizeof(cl)); //Poner MaxE*sizeof... por si acaso
   Q->cola=malloc(maxE*sizeof(int));
   Q->tam=0;
   Q->capacity=maxE;
   Q->frente=&(Q->cola[0]);
   Q->final=&(Q->cola[0]);
   Q->nfr=1;
   Q->nfi=1;
   return Q;
}

int elim(cl * Q, int elem)
{
    int s,pl=0;
    int * pt;
    if  (Q->tam==0)
	printf("La cola está vacía\n");
    else
    {
	pt=Q->frente;
    	while ( pt != Q->final)
    	{
	    if (*pt == elem)
	    {
		pl=1;
		break;
	    }
	    else
		pl=0;
   	    pt++;
    	}
	if (pl)
	{
	    do
	    {
    	    	s=*Q->frente;
    	    	Q->frente++;
		Q->nfr++;
	    	Q->tam--;
	    } while ( s != elem);
	}
	else
	    printf("No existe el elemento.\n");
    }
    return s;
}

void ins(cl * Q, int elem)
{
    if ( Q->tam >= Q->capacity)
	printf("Cola llena, no se puede ingresar mas elementos\n");
    else
    {
    	*Q->final=elem;
    	Q->final++;
	Q->nfi++;
    	Q->tam++;
    }
}

//Display elements of queue
void display(cl *qu)
{
    int * pt;
    if (qu->tam != 0)
    {
    	pt=qu->frente;
    	while ( pt != qu->final)
    	{
	    printf("%d, ",*pt);
   	    pt++;
    	}
    	printf("\b\b \n");
    }
    else
	printf("La cola está vacía.\n");
}

void frfi(cl * Q)
{
    printf("El frente es: %d y el final: %d\n",Q->nfr,Q->nfi);
}
void main()
{
    cl * cl1 = create(5);
    ins(cl1,7);
    ins(cl1,9);
    /*ins(cl1,3);
    ins(cl1,5);
    ins(cl1,8);
    elim(cl1,9);*/
    display(cl1);
    frfi(cl1);
}

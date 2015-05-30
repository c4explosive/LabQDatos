//Comentario
#include <stdio.h>
#include <stdlib.h>
typedef struct col 
{
    int *cola; //Array donde se insertan los elementos
    int capacity; //Capacidad de la cola
    int tam; // tamaño actual de la cola
    int* frente; //Puntero o dirección de memoria del frente
    int* final; // Puntero o dirección de memoria del final
    int nfr,nfi; //Enteros que almacenan el índice de posoción final e inicial.
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

//delete elements

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

//Insert elements
void ins(cl * Q, int elem)
{
    if (lle(Q))
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
    if (!vac(qu))
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
    if (lle(qu))
	printf("La cola está llena.\n");
}

//Vacía
int vac(cl * Q)
{
    if (Q->tam != 0)
	return 0;
    else
	return 1;
}

//Llena

int lle(cl * Q)
{
    if (Q->tam >= Q->capacity)
	return 1;
    else
	return 0;
}
void frfi(cl * Q)
{
    printf("El frente es: %d y el final: %d\n",Q->nfr,Q->nfi);
}
void main()
{
    cl * cl1 = create(5);
    cl * cl2 = create(5);
    ins(cl1,7);
    ins(cl1,8);
    ins(cl1,9);
    ins(cl1,3);
    ins(cl1,5);
    ins(cl2,8);
    //elim(cl1,9);
    display(cl1);
    display(cl2);
    //frfi(cl1);
}

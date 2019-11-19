#include <stdio.h>
#include <stdlib.h>
#define max 5

struct Cola
{
	int datos;
	struct Cola *siguiente;
	struct Cola *frente;
	struct Cola *atras;
};

struct ColaPrd
{
	struct Cola *colaprd[max];
};

int agregar(struct ColaPrd **cola, int valor, int prioridad);
int eliminar(struct ColaPrd **cola);
void iniciarCola(struct ColaPrd **colaprd);

int main()
{
	struct ColaPrd *colaprd=NULL;
	colaprd=(struct ColaPrd*)malloc(sizeof(struct ColaPrd));

	iniciarCola(&colaprd);

	agregar(&colaprd, 1, 0);
	agregar(&colaprd, 2, 0);
	agregar(&colaprd, 3, 1);
	agregar(&colaprd, 4, 2);
	agregar(&colaprd, 5, 2);
	agregar(&colaprd, 6, 2);
	agregar(&colaprd, 7, 3);
	agregar(&colaprd, 8, 4);
	agregar(&colaprd, 9, 4);

	eliminar(&colaprd);
	eliminar(&colaprd);
	eliminar(&colaprd);
	eliminar(&colaprd);

	return 0;
}


void iniciarCola(struct ColaPrd **colaprd)
{
	for(int i=0; i<max; i++)
	{
		struct Cola *cola=NULL;
		cola=(struct Cola*)malloc(sizeof(struct Cola));
		cola->frente=NULL;
		cola->atras=NULL;

		(*colaprd)->colaprd[i]=cola;
	}
}

int agregar(struct ColaPrd **cola, int valor, int prioridad)
{
	struct Cola *nuevo=NULL;

	nuevo=(struct Cola*)malloc(sizeof(struct Cola));
	
	nuevo->datos=valor;
	nuevo->siguiente=NULL;

	if(((*cola)->colaprd[prioridad])->frente==NULL && ((*cola)->colaprd[prioridad])->atras==NULL)
	{
		((*cola)->colaprd[prioridad])->frente=nuevo;
	}
	else
	{
		(((*cola)->colaprd[prioridad])->atras)->siguiente=nuevo;
	}

	((*cola)->colaprd[prioridad])->atras=nuevo;
	printf("Agregado en %d: %d \n", prioridad, (((*cola)->colaprd[prioridad])->atras)->datos);
	
	return 0;
}

int eliminar(struct ColaPrd **cola)
{
	int aux=0;

	while(((*cola)->colaprd[aux])->frente==NULL && ((*cola)->colaprd[aux])->atras==NULL)
	{
		aux++;
	}

	printf("Eliminar de %d: %d \n", aux, (((*cola)->colaprd[aux])->frente)->datos);
	
	if(((*cola)->colaprd[aux])->frente==NULL && ((*cola)->colaprd[aux])->atras==NULL)
	{
		(*cola)->colaprd[aux]=NULL;
	}
	else
	{
		if(((*cola)->colaprd[aux])->frente==((*cola)->colaprd[aux])->atras)
		{
			((*cola)->colaprd[aux])->frente=NULL;
			((*cola)->colaprd[aux])->atras=NULL;
		}
		else
		{
			((*cola)->colaprd[aux])->frente=(((*cola)->colaprd[aux])->frente)->siguiente;
		}
	}	

	return 0;
}
			
					





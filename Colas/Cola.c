#include <stdio.h>
#include <stdlib.h>

struct Cola
{
	int datos;
	struct Cola *siguiente;
	struct Cola *frente;
	struct Cola *atras;
};

int agregar(struct Cola **cola, int valor);
int eliminar(struct Cola **cola);

int main()
{
	struct Cola *cola=NULL;

	cola=(struct Cola*)malloc(sizeof(struct Cola));
	cola->frente=NULL;
	cola->atras=NULL;

	agregar(&cola, 1);
	agregar(&cola, 2);
	agregar(&cola, 3);
	agregar(&cola, 4);
	agregar(&cola, 5);
	agregar(&cola, 6);
	agregar(&cola, 7);
	agregar(&cola, 8);
	agregar(&cola, 9);
	agregar(&cola, 10);

	eliminar(&cola);
	eliminar(&cola);
	eliminar(&cola);
	eliminar(&cola);

	return 0;
}

int agregar(struct Cola **cola, int valor)
{
	struct Cola *nuevo=NULL;

	nuevo=(struct Cola*)malloc(sizeof(struct Cola));

	nuevo->datos=valor;
	nuevo->siguiente=NULL;

	if((*cola)->frente==NULL && (*cola)->atras==NULL)
	{
		(*cola)->frente=nuevo;
	}
	else
	{
		((*cola)->atras)->siguiente=nuevo;
	}

	(*cola)->atras=nuevo;
	printf("Agregado: %d \n", ((*cola)->atras)->datos);
	
	return 0;
}

int eliminar(struct Cola **cola)
{
	printf("Atender: %d", ((*cola)->frente)->datos);

	if((*cola)->frente==NULL && (*cola)->atras==NULL)
	{
		return -1;
	}
	else
	{
		if((*cola)->frente==(*cola)->atras)
		{
			(*cola)->frente=NULL;
			(*cola)->atras=NULL;
		}
		else
		{
			(*cola)->frente=((*cola)->frente)->siguiente;
		}

	}
	printf("\n");

	return 0;
}	

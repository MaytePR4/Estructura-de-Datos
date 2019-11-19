#include <stdio.h>
#include <stdlib.h>

struct Lista
{
	int datos;
	struct Lista *siguiente;
};


struct HashAbierto
{
	struct Lista* abierto[10];	
};

int agregar(struct HashAbierto **lista, int dato);
int eliminar(struct HashAbierto **lista, int posicion);
int hash(int dato);
void mostrar(struct HashAbierto *lista);
void iniciarLista(struct HashAbierto **thash);

int main()
{
	struct HashAbierto *thash=NULL;
	thash=(struct HashAbierto*)malloc(sizeof(struct HashAbierto));
	
	agregar(&thash, 34);
	agregar(&thash, 73);
	agregar(&thash, 83);
	agregar(&thash, 21);
	agregar(&thash, 53);
	agregar(&thash, 80);
	agregar(&thash, 67);
	agregar(&thash, 101);
	agregar(&thash, 64);
	agregar(&thash, 11);
	agregar(&thash, 67);
	mostrar(thash);

	eliminar(&thash, 9);
	eliminar(&thash, 3);
	eliminar(&thash, 9);
	eliminar(&thash, 0);

	return 0;
}

void iniciarLista(struct HashAbierto **thash)
{
	for(int i=0; i<10; i++)
	{
		struct Lista *lista=NULL;
		lista=(struct Lista*)malloc(sizeof(struct Lista));

		(*thash)->abierto[i]=lista;
		lista->siguiente=NULL;
	}
}

int agregar(struct HashAbierto **lista, int dato)
{
	struct Lista *nuevo=NULL;
	struct Lista *aux=NULL;

	nuevo=(struct Lista*)malloc(sizeof(struct Lista));
	
	if(nuevo==NULL)
	{
		return -1;
	}

	nuevo->datos=dato;
	nuevo->siguiente=NULL;	
	
	if((*lista)->abierto[hash(dato)]==NULL)
	{
		(*lista)->abierto[hash(dato)]=nuevo;
	}
	else
	{
		aux=(*lista)->abierto[hash(dato)];
		
		while(aux->siguiente!=NULL)
		{
			aux=aux->siguiente;
		}
		
		aux->siguiente=nuevo;
	}

	while(aux->siguiente!=NULL)
	{
		printf("Agregado en %d: %d", hash(dato), aux->siguiente->datos);
		aux=aux->siguiente;
	}
	printf("\n");

	return 0;
}



int eliminar(struct HashAbierto **lista, int posicion)
{
	printf("Eliminar de %d: %d", posicion, (((*lista)->abierto[posicion])->siguiente)->datos);
	
	if((*lista)->abierto[posicion]==NULL)
	{
		return -1;
	}
	else
	{
		(*lista)->abierto[posicion]=((*lista)->abierto[posicion])->siguiente;
	}
	printf("\n");	
	
	return 0;
}


int hash(int dato)
{
	int k=0;
	k=((dato*10)^dato)%10;
	return k;
}

void mostrar(struct HashAbierto *lista)
{
	struct Lista *aux=NULL;	

	for(int i=0; i<=100; i++)
	{
		aux=lista->abierto[i];
		printf("%d ", i);
		printf("\n");	
		while(aux->siguiente!=NULL)
		{
			printf("%d ", aux->siguiente->datos);
			aux=aux->siguiente;
		}
		printf("\n");
	}
	printf("\n");
}

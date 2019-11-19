#include <stdio.h>
#include <stdlib.h>

struct Pila
{
	int dato;
	struct Pila *tope;
};

int push(struct Pila **pila, int valor);
int pop(struct Pila **pila);
void mostrar(struct Pila *pila);

int main()
{
	struct Pila *pila=NULL;

	pila=(struct Pila*)malloc(sizeof(struct Pila));

	pila->tope=0;

	push(&pila, 12);
	push(&pila, 23);
	push(&pila, 31);
	push(&pila, 46);
	push(&pila, 54);
	push(&pila, 68);
	push(&pila, 76);
	push(&pila, 89);
	push(&pila, 92);
	push(&pila, 15);
	push(&pila, 27);
	mostrar(pila);

	pop(&pila);
	pop(&pila);
	pop(&pila);
	pop(&pila);
	pop(&pila);
	pop(&pila);
	mostrar(pila);

	return 0;
}

int push(struct Pila **pila, int valor)
{
	struct Pila *nuevo=NULL;

	nuevo=(struct Pila*)malloc(sizeof(struct Pila));
	
	if(nuevo==NULL)
	{
		return -1;
	}

	nuevo->dato=valor;
	nuevo->tope=*pila;
	*pila=nuevo;

	return 0;
}

int pop(struct Pila **pila)
{
	struct Pila *aux=NULL;
	aux=*pila;

	if(*pila==NULL)
	{
		return -1;
	}
	else
	{
		*pila=aux->tope;
		free(aux);
	}
	
	return 0;
}

void mostrar(struct Pila *pila)
{
	while(pila->tope!=NULL)
	{
		printf("%d \n", pila->dato);
		pila=pila->tope;
	}
	printf("\n");
}	 

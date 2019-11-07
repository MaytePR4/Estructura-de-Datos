#include <stdio.h>
#include <stdlib.h>
#define max 10

struct Pila
{
	int tope;
	int vector[max];
};

int push(struct Pila *pila, int valor);
int pop(struct Pila *pila);
int estaLlena(struct Pila *pila);
int estaVacia(struct Pila *pila);
void mostrar(struct Pila *pila);

int main()
{
	struct Pila *pila=NULL;

	pila=(struct Pila*)malloc(sizeof(struct Pila));

	pila->tope=0;

	push(pila, 12);
	push(pila, 23);
	push(pila, 31);
	push(pila, 46);
	push(pila, 54);
	push(pila, 68);
	push(pila, 76);
	push(pila, 89);
	push(pila, 92);
	push(pila, 15);
	push(pila, 27);
	mostrar(pila);

	pop(pila);
	pop(pila);
	pop(pila);
	pop(pila);
	pop(pila);
	pop(pila);
	mostrar(pila);

	return 0;
}

int push(struct Pila *pila, int valor)
{
	if(estaLlena(pila))
	{
		return -1;
	}
	else
	{
		pila->vector[pila->tope]=valor;
		pila->tope++;
	}

	return 0;
}

int pop(struct Pila *pila)
{
	if(estaVacia(pila))
	{
		return -1;
	}
	else
	{
		pila->tope--;
	}
	
	return 0;
}

int estaLlena(struct Pila *pila)
{
	return pila->tope==max;
}

int estaVacia(struct Pila *pila)
{
	return pila->tope==0;
}

void mostrar(struct Pila *pila)
{
	for(int i=pila->tope-1;i>=0;i--)
	{
		printf("%d ", pila->vector[i]);
		printf("\n");
	}
	printf("\n");
	printf("\n");
}	 

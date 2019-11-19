#include <stdio.h>
#include <stdlib.h>

struct Pila
{
	char simbolo;
	struct Pila *tope;
};

char push(struct Pila **pila, char car);
char pop(struct Pila **pila);
void balanceo(struct Pila **pila, char cadena[]);

int main()
{
	struct Pila *pila=NULL;
	char cadena[7]="[(){}]";
	balanceo(&pila, cadena); 

	char cadena2[10]="([{}{}(])";
	balanceo(&pila, cadena2);

	return 0; 
}

char push(struct Pila **pila, char car)
{
	struct Pila *nuevo=NULL;

	nuevo=(struct Pila*)malloc(sizeof(struct Pila));

	if(nuevo==NULL)
	{
		return -1;
	}

	nuevo->simbolo=car;
	nuevo->tope=*pila;
	*pila=nuevo;

	return 0;
}

char pop(struct Pila **pila)
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
	}

	return 0;
}

void balanceo(struct Pila **pila, char cadena[])
{
	int i=0;

	while(cadena[i]!='\0')
	{
		if(cadena[i]=='(' || cadena[i]=='[' || cadena[i]=='{')
		{
			push (pila, cadena[i]);
		}
		else if(cadena[i]==')' || cadena[i]==']' || cadena[i]=='}')
		{
			pop(pila);
		}

		i++;
	}

	if(*pila==NULL)
	{
		printf("La cadena esta balanceada \n");		
	}
	else
	{
		printf("La cadena no esta balanceada \n");		
	} 
}

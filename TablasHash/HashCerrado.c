#include <stdio.h>
#include <stdlib.h>

struct HashCerrado
{
	int datos[100];
};

int agregar(struct HashCerrado **thash, int dato);
int eliminar(struct HashCerrado **thash, int valor);
int hash(int dato);
int rehash(int dato);
void mostrar(struct HashCerrado *thash);
void buscar(struct HashCerrado *thash, int valor);

int main()
{
	struct HashCerrado *thash=NULL;
	thash=(struct HashCerrado*)malloc(sizeof(struct HashCerrado));
	
	agregar(&thash, 34);
	agregar(&thash, 83);
	agregar(&thash, 4);
	agregar(&thash, 9);
	agregar(&thash, 97);
	agregar(&thash, 21);
	mostrar(thash);
	buscar(thash, 83);

	eliminar(&thash, 4);
	eliminar(&thash, 34);
	mostrar(thash);
	buscar(thash, 36);

	return 0;
}

int agregar(struct HashCerrado **thash, int dato)
{
	if((*thash)->datos[hash(dato)]!=0)
	{
		(*thash)->datos[rehash(dato)]=dato;
	}
	else
	{
		(*thash)->datos[hash(dato)]=dato;
	}

	return 0;
}



int eliminar(struct HashCerrado **thash, int valor)
{
	for(int i=0; i<=100; i++)
	{
		if((*thash)->datos[i]==valor)
		{
			(*thash)->datos[i]=0;
		}
	}
	
	return 0;
}


int hash(int dato)
{
	int k=0;
	k=(dato*(dato^5))%100;
	return k;
}

int rehash(int dato)
{
	int k=0;
	k=hash(dato)+1;
	return k;
}

void mostrar(struct HashCerrado *thash)
{
	for(int i=0; i<=100; i++)
	{	
		if(thash->datos[i]!=0)
		{
			printf("%d: %d", i, thash->datos[i]);
			printf("\n");
		}
	}
	printf("\n");
}


void buscar(struct HashCerrado *thash, int valor)
{
	int aux=0;

	for(int i=0; i<=100; i++)
	{
		if(thash->datos[i]==valor)
		{
			printf("%d esta en la posicion %d", valor, i);
			printf("\n");
			aux=1;
		}
	}

	if(aux==0)
	{
		printf("%d no se encuentra entre los datos de la tabla", valor);
	}

	printf("\n");
}

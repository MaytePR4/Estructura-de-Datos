#include "Pila.h"

int
push (struct Pila **pila, int valor)
{
  struct Pila *nuevo = NULL;

  nuevo = (struct Pila *) malloc (sizeof (struct Pila));

  if (nuevo == NULL)
    {
      return -1;
    }

  nuevo->dato = valor;
  nuevo->tope = *pila;
  *pila = nuevo;

	printf ("Agregado: %d \n", (*pila)->dato);
  return 0;
}

int
pop (struct Pila **pila)
{
	printf ("Eliminar: %d \n", (*pila)->dato);
  struct Pila *aux = NULL;
  aux = *pila;

  if (*pila == NULL)
    {
      return -1;
    }
  else
    {
      *pila = aux->tope;
      free (aux);
    }

  return 0;
}


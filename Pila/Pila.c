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

  return 0;
}

int
pop (struct Pila **pila)
{
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

void
mostrar (struct Pila *pila)
{
  while (pila->tope != NULL)
    {
      printf ("%d \n", pila->dato);
      pila = pila->tope;
    }
  printf ("\n");
}

#include "DobleCirc.h"

int
agregar (struct DobleCirc **lista, int valor)
{
  struct DobleCirc *nuevo = NULL;
  struct DobleCirc *ultimo;

  nuevo = (struct DobleCirc *) malloc (sizeof (struct DobleCirc));

  if (nuevo == NULL)
    {
      return 0;
    }

  nuevo->dato = valor;

  if (*lista == NULL)
    {
      ultimo = NULL;
      *lista = nuevo;
      (*lista)->siguiente = *lista;
      ultimo = *lista;
      (*lista)->anterior = ultimo;
    }
  else
    {
      ultimo->siguiente = nuevo;
      nuevo->siguiente = *lista;
      nuevo->anterior = ultimo;
      ultimo = nuevo;
      (*lista)->anterior = ultimo;
    }

  return 0;
}

int
eliminar (struct DobleCirc **lista, int valor)
{
  struct DobleCirc *actual;
  struct DobleCirc *auxant = NULL;
  struct DobleCirc *auxsig = NULL;
  actual = *lista;
  auxant = *lista;
  auxsig = *lista;

  while (actual->dato != valor)
    {
      actual = actual->siguiente;
    }

  while (auxant->siguiente != actual)
    {
      auxant = auxant->siguiente;
    }

  if (*lista != NULL)
    {
      if (actual == *lista)
	{
	  *lista = (*lista)->siguiente;
	  auxant->siguiente = *lista;
	  (*lista)->anterior = auxant;
	  free (actual);
	}
      else
	{
	  while (auxsig->anterior != actual)
	    {
	      auxsig = auxsig->anterior;
	    }

	  if (actual == auxant && actual == auxsig)
	    {
	      *lista = NULL;
	      (*lista)->siguiente = NULL;
	      (*lista)->anterior = NULL;
	    }
	  else
	    {
	      auxant->siguiente = auxsig;
	      auxsig->anterior = auxant;
	      free (actual);
	    }
	}
    }

  return 0;
}

void
mostrar (struct DobleCirc *lista)
{
  struct DobleCirc *aux = NULL;
  aux = lista;

  while (aux->siguiente != lista)
    {
      printf ("%d ", aux->dato);
      aux = aux->siguiente;
    }

  printf ("%d ", aux->dato);
  printf ("\n");
}

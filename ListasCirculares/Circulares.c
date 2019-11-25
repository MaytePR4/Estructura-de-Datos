#include "Circulares.h"

int
agregar (struct Circular **lista, int valor)
{
  struct Circular *nuevo = NULL;

  nuevo = (struct Circular *) malloc (sizeof (struct Circular));

  if (nuevo == NULL)
    {
      return 0;
    }

  nuevo->dato = valor;

  if (*lista == NULL)
    {
      *lista = nuevo;
    }
  else
    {
      nuevo->siguiente = (*lista)->siguiente;
    }

  (*lista)->siguiente = nuevo;
  *lista = nuevo;

  return 0;
}

int
eliminar (struct Circular **lista, int valor)
{
  struct Circular *actual = NULL;
  struct Circular *aux = NULL;
  struct Circular *primero = NULL;
  actual = *lista;
  aux = *lista;
  primero = (*lista)->siguiente;

  if ((*lista)->dato == valor)
    {
      while (aux->siguiente != *lista)
	{
	  aux = aux->siguiente;
	}

      aux->siguiente = (*lista)->siguiente;
      free (*lista);
      *lista = aux;
    }
  else
    {
      while (primero != *lista)
	{
	  if (actual->dato != valor)
	    {
	      actual = actual->siguiente;
	    }

	  if (aux->siguiente != actual)
	    {
	      aux = aux->siguiente;
	    }

	  primero = primero->siguiente;
	}

      aux->siguiente = actual->siguiente;
      free (actual);
      actual = *lista;
      aux = *lista;
    }

  return 0;
}

void
mostrar (struct Circular *lista)
{
  struct Circular *aux = NULL;
  aux = lista->siguiente;

  while (aux != lista)
    {
      printf ("%d ", aux->dato);
      aux = aux->siguiente;
    }
  printf ("%d ", aux->dato);
  printf ("\n");
}

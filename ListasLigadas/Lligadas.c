#include "Lligadas.h"

int
eliminar (struct Lista **lista, int valor)
{
  struct Lista *anterior = NULL;
  struct Lista *actual = *lista;

  while (actual != NULL)
    {
      if (actual->dato == valor)
	{
	  if (actual == *lista)
	    {
	      *lista = (*lista)->siguiente;
	      free (actual);
	      actual = *lista;
	    }
	  else
	    {
	      anterior->siguiente = actual->siguiente;
	      free (actual);
	      actual = anterior->siguiente;
	    }
	}
      else
	{
	  if (anterior == NULL)
	    {
	      anterior = *lista;
	    }
	  else
	    {
	      anterior = anterior->siguiente;
	    }

	  actual = actual->siguiente;
	}
    }
  return 0;
}

int
agregar (struct Lista **lista, int valor)
{
  struct Lista *nuevo = NULL;

  nuevo = (struct Lista *) malloc (sizeof (struct Lista));

  if (nuevo == NULL)
    {
      return 0;
    }

  if (*lista == NULL)
    {
      *lista = nuevo;
      (*lista)->dato = valor;
      (*lista)->siguiente = NULL;
    }
  else
    {
      nuevo->dato = valor;
      nuevo->siguiente = *lista;
      *lista = nuevo;
    }

  return 0;
}

void
mostrar (struct Lista *lista)
{
  while (lista != NULL)
    {
      printf ("%d ", lista->dato);
      lista = lista->siguiente;
    }
  printf ("\n");
}

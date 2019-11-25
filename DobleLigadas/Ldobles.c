#include "Ldobles.h"

int
agregar (struct Doble **lista, int valor)
{
  struct Doble *nuevo = NULL;

  nuevo = (struct Doble *) malloc (sizeof (struct Doble));

  if (nuevo == NULL)
    {
      return 0;
    }

  if (*lista == NULL)
    {
      *lista = nuevo;
      (*lista)->dato = valor;
      (*lista)->siguiente = NULL;
      (*lista)->anterior = NULL;
    }
  else
    {
      if (*lista != NULL)
	{
	  (*lista)->anterior = nuevo;
	  nuevo->anterior = NULL;
	  nuevo->siguiente = *lista;
	  nuevo->dato = valor;
	  *lista = nuevo;
	}
    }

  return 0;
}

int
eliminar (struct Doble **lista, int valor)
{
  struct Doble *actual = NULL;
  struct Doble *anterior = NULL;
  actual = *lista;

  while (actual != NULL)
    {
      if (actual->dato == valor)
	{
	  if (actual == *lista)
	    {
	      *lista = (*lista)->siguiente;
	      actual->siguiente = NULL;
	      (*lista)->anterior = NULL;
	      free (actual);
	      actual = *lista;
	    }
	  else
	    {
	      if (actual->siguiente == NULL)
		{
		  anterior->siguiente = NULL;
		  actual->anterior = NULL;
		  free (actual);
		  actual = *lista;
		  anterior = NULL;
		}
	      else
		{
		  actual->siguiente->anterior = actual->anterior;
		  actual->anterior->siguiente = actual->siguiente;
		  free (actual);
		  actual = *lista;
		}
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

void
mostrar (struct Doble *lista)
{
  while (lista != NULL)
    {
      printf ("%d ", lista->dato);
      lista = lista->siguiente;
    }
  printf ("\n");
}

void
mostrarInverso (struct Doble *lista)
{
  struct Doble *ultimo = NULL;
  ultimo = lista;

  while (ultimo->siguiente != NULL)
    {
      ultimo = ultimo->siguiente;
    }

  while (ultimo != NULL)
    {
      printf ("%d ", ultimo->dato);
      ultimo = ultimo->anterior;
    }
  printf ("\n");
}

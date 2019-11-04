#include <stdio.h>
#include <stdlib.h>

struct Lista
{
  int dato;
  struct Lista *siguiente;
};

int agregar (struct Lista **lista, int valor);
int eliminar (struct Lista **lista, int valor);
void mostrar (struct Lista *lista);

int main ()
{
  struct Lista *lista = NULL;

  agregar (&lista, 1);
  agregar (&lista, 2);
  agregar (&lista, 3);
  agregar (&lista, 4);
  agregar (&lista, 5);
  mostrar (lista);

  eliminar (&lista, 3);
  mostrar (lista);

  return 0;
}

int eliminar (struct Lista **lista, int valor)
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

int agregar (struct Lista **lista, int valor)
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

void mostrar (struct Lista *lista)
{
  while (lista != NULL)
    {
      printf ("%d ", lista->dato);
      lista = lista->siguiente;
    }
  printf ("\n");
}

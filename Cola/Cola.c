#include "Cola.h"

int
agregar (struct Cola **cola, int valor)
{
  struct Cola *nuevo = NULL;

  nuevo = (struct Cola *) malloc (sizeof (struct Cola));

  nuevo->datos = valor;
  nuevo->siguiente = NULL;

  if ((*cola)->frente == NULL && (*cola)->atras == NULL)
    {
      (*cola)->frente = nuevo;
    }
  else
    {
      ((*cola)->atras)->siguiente = nuevo;
    }

  (*cola)->atras = nuevo;
  printf ("Agregado: %d \n", ((*cola)->atras)->datos);

  return 0;
}

int
eliminar (struct Cola **cola)
{
  printf ("Atender: %d", ((*cola)->frente)->datos);

  if ((*cola)->frente == NULL && (*cola)->atras == NULL)
    {
      return -1;
    }
  else
    {
      if ((*cola)->frente == (*cola)->atras)
	{
	  (*cola)->frente = NULL;
	  (*cola)->atras = NULL;
	}
      else
	{
	  (*cola)->frente = ((*cola)->frente)->siguiente;
	}

    }
  printf ("\n");

  return 0;
}

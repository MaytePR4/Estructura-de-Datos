#include "ColaPrd.h"

void
iniciarCola (struct ColaPrd **colaprd)
{
  for (int i = 0; i < max; i++)
    {
      struct Cola *cola = NULL;
      cola = (struct Cola *) malloc (sizeof (struct Cola));
      cola->frente = NULL;
      cola->atras = NULL;

      (*colaprd)->colaprd[i] = cola;
    }
}

int
agregar (struct ColaPrd **cola, int valor, int prioridad)
{
  struct Cola *nuevo = NULL;

  nuevo = (struct Cola *) malloc (sizeof (struct Cola));

  nuevo->datos = valor;
  nuevo->siguiente = NULL;

  if (((*cola)->colaprd[prioridad])->frente == NULL
      && ((*cola)->colaprd[prioridad])->atras == NULL)
    {
      ((*cola)->colaprd[prioridad])->frente = nuevo;
    }
  else
    {
      (((*cola)->colaprd[prioridad])->atras)->siguiente = nuevo;
    }

  ((*cola)->colaprd[prioridad])->atras = nuevo;
  printf ("Agregado en %d: %d \n", prioridad,
	  (((*cola)->colaprd[prioridad])->atras)->datos);

  return 0;
}

int
eliminar (struct ColaPrd **cola)
{
  int aux = 0;

  while (((*cola)->colaprd[aux])->frente == NULL
	 && ((*cola)->colaprd[aux])->atras == NULL)
    {
      aux++;
    }

  printf ("Eliminar de %d: %d \n", aux,
	  (((*cola)->colaprd[aux])->frente)->datos);

  if (((*cola)->colaprd[aux])->frente == NULL
      && ((*cola)->colaprd[aux])->atras == NULL)
    {
      (*cola)->colaprd[aux] = NULL;
    }
  else
    {
      if (((*cola)->colaprd[aux])->frente == ((*cola)->colaprd[aux])->atras)
	{
	  ((*cola)->colaprd[aux])->frente = NULL;
	  ((*cola)->colaprd[aux])->atras = NULL;
	}
      else
	{
	  ((*cola)->colaprd[aux])->frente =
	    (((*cola)->colaprd[aux])->frente)->siguiente;
	}
    }

  return 0;
}

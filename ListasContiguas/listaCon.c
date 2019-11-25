#include "listaCon.h"


int
agregar (struct Lista *lista, int dato)
{
  int *tmp;

  if (lista == NULL)
    {
      return -1;
    }

  tmp = (int *) malloc ((lista->fin * 2) * sizeof (int));

  *(tmp + (lista->fin)) = dato;

  if (tmp == NULL)
    {
      return 0;
    }

  for (int i = 0; i < lista->fin; i++)
    {
      *(tmp + i) = *(lista->datos + i);
    }

  free (lista->datos);
  lista->datos = tmp;
  lista->fin++;

  return 0;
}

int
eliminar (struct Lista *lista, int datos)
{
  int *tmp, pos = 0, j = 0;

  if (lista == NULL)
    {
      return -1;
    }

  for (int i = 0; i < lista->fin; i++)
    {
      if (datos == *(lista->datos + i))
	{
	  pos = i;
	}
    }

  tmp = (int *) malloc ((lista->fin / 2) * sizeof (int));

  for (int i = 0; i < lista->fin; i++)
    {
      if (i != pos)
	{
	  *(tmp + j) = *(lista->datos + i);
	  j++;
	}
    }

  free (lista->datos);
  lista->datos = tmp;
  lista->fin--;

  return 0;
}

void
mostrar (struct Lista *lista)
{
  for (int i = 0; i < lista->fin; i++)
    {
      printf ("%d ", *(lista->datos + i));
    }
  printf ("\n");
}

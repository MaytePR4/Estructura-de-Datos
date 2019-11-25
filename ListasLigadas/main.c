#include "Lligadas.h"

int
main ()
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


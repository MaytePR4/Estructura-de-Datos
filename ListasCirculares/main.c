#include "Circulares.h"

int
main ()
{
  struct Circular *lista = NULL;

  agregar (&lista, 1);
  agregar (&lista, 2);
  agregar (&lista, 3);
  agregar (&lista, 4);
  agregar (&lista, 5);
  mostrar (lista);

  eliminar (&lista, 5);
  mostrar (lista);

  return 0;
}


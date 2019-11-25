#include "Ldobles.h"

int
main ()
{
  struct Doble *lista = NULL;

  agregar (&lista, 1);
  agregar (&lista, 2);
  agregar (&lista, 3);
  agregar (&lista, 4);
  agregar (&lista, 5);
  mostrar (lista);
  mostrarInverso (lista);

  eliminar (&lista, 5);
  mostrar (lista);
  mostrarInverso (lista);

  return 0;
}


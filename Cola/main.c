#include "Cola.h"

int
main ()
{
  struct Cola *cola = NULL;

  cola = (struct Cola *) malloc (sizeof (struct Cola));
  cola->frente = NULL;
  cola->atras = NULL;

  agregar (&cola, 1);
  agregar (&cola, 2);
  agregar (&cola, 3);
  agregar (&cola, 4);
  agregar (&cola, 5);
  agregar (&cola, 6);
  agregar (&cola, 7);
  agregar (&cola, 8);
  agregar (&cola, 9);
  agregar (&cola, 10);

  eliminar (&cola);
  eliminar (&cola);
  eliminar (&cola);
  eliminar (&cola);

  return 0;
}

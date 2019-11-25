#include "ColaPrd.h"

int
main ()
{
  struct ColaPrd *colaprd = NULL;
  colaprd = (struct ColaPrd *) malloc (sizeof (struct ColaPrd));

  iniciarCola (&colaprd);

  agregar (&colaprd, 1, 0);
  agregar (&colaprd, 2, 0);
  agregar (&colaprd, 3, 1);
  agregar (&colaprd, 4, 2);
  agregar (&colaprd, 5, 2);
  agregar (&colaprd, 6, 2);
  agregar (&colaprd, 7, 3);
  agregar (&colaprd, 8, 4);
  agregar (&colaprd, 9, 4);

  eliminar (&colaprd);
  eliminar (&colaprd);
  eliminar (&colaprd);
  eliminar (&colaprd);

  return 0;
}


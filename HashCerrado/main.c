#include "HashCerrado.h"

int
main ()
{
  struct HashCerrado *thash = NULL;
  thash = (struct HashCerrado *) malloc (sizeof (struct HashCerrado));

  agregar (&thash, 34);
  agregar (&thash, 83);
  agregar (&thash, 4);
  agregar (&thash, 9);
  agregar (&thash, 97);
  agregar (&thash, 21);
  buscar (thash, 83);

  eliminar (&thash, 4);
  eliminar (&thash, 34);
  buscar (thash, 36);

  return 0;
}



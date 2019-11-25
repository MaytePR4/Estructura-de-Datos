#include "Pila.h"

int
main ()
{
  struct Pila *pila = NULL;

  pila = (struct Pila *) malloc (sizeof (struct Pila));

  pila->tope = 0;

  push (&pila, 12);
  push (&pila, 23);
  push (&pila, 31);
  push (&pila, 46);
  push (&pila, 54);
  push (&pila, 68);
  push (&pila, 76);
  push (&pila, 89);
  push (&pila, 92);
  push (&pila, 15);
  push (&pila, 27);
  mostrar (pila);

  pop (&pila);
  pop (&pila);
  pop (&pila);
  pop (&pila);
  pop (&pila);
  pop (&pila);
  mostrar (pila);

  return 0;
}


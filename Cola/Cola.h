#ifndef Cola_H
#define Cola_H

#include <stdio.h>
#include <stdlib.h>

struct Cola
{
  int datos;
  struct Cola *siguiente;
  struct Cola *frente;
  struct Cola *atras;
};

int agregar (struct Cola **, int);
int eliminar (struct Cola **);

#endif

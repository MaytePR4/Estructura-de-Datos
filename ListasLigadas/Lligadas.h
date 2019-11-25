#ifndef Ligada_H
#define Ligada_H

#include <stdio.h>
#include <stdlib.h>

struct Lista
{
  int dato;
  struct Lista *siguiente;
};

int agregar (struct Lista **, int);
int eliminar (struct Lista **, int);
void mostrar (struct Lista *);

#endif

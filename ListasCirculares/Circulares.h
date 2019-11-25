#ifndef Circular_H
#define Circular_H

#include <stdio.h>
#include <stdlib.h>

struct Circular
{
  int dato;
  struct Circular *siguiente;
};

int agregar (struct Circular **, int);
int eliminar (struct Circular **, int);
void mostrar (struct Circular *);

#endif

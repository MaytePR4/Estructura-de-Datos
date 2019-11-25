#ifndef ColaPrioridad_H
#define ColaPrioridad_H

#include <stdio.h>
#include <stdlib.h>
#define max 5

struct Cola
{
  int datos;
  struct Cola *siguiente;
  struct Cola *frente;
  struct Cola *atras;
};

struct ColaPrd
{
  struct Cola *colaprd[max];
};

int agregar (struct ColaPrd **, int, int);
int eliminar (struct ColaPrd **);
void iniciarCola (struct ColaPrd **);

#endif

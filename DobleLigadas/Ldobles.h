#ifndef DobleLigadas_H
#define DobleLigadas_H

#include <stdio.h>
#include <stdlib.h>

struct Doble
{
  int dato;
  struct Doble *siguiente;
  struct Doble *anterior;
};

int agregar (struct Doble **, int);
int eliminar (struct Doble **, int);
void mostrar (struct Doble *);
void mostrarInverso (struct Doble *);

#endif

#ifndef DobleCirc_H
#define DobleCirc_H

#include <stdio.h>
#include <stdlib.h>

struct DobleCirc
{
  int dato;
  struct DobleCirc *siguiente;
  struct DobleCirc *anterior;
};

int agregar (struct DobleCirc **, int);
int eliminar (struct DobleCirc **, int);
void mostrar (struct DobleCirc *);

#endif

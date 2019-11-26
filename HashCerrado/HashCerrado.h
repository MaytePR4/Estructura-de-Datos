#ifndef Cerrado_H
#define Cerrado_H

#include <stdio.h>
#include <stdlib.h>

struct HashCerrado
{
  int datos[100];
};

int agregar (struct HashCerrado **, int);
int eliminar (struct HashCerrado **, int);
int hash (int);
int rehash (int);
void buscar (struct HashCerrado *, int);

#endif

#ifndef Pila_H
#define Pila_H

#include <stdio.h>
#include <stdlib.h>

struct Pila
{
  int dato;
  struct Pila *tope;
};

int push (struct Pila **, int);
int pop (struct Pila **);
void mostrar (struct Pila *);

#endif

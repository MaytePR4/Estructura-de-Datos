#include "listaCon.h"

int
main ()
{
  struct Lista *lista=NULL;
	
  lista = (struct Lista*)malloc(sizeof(struct Lista));
	lista->fin = 0;
  

  agregar(lista, 1);
  agregar(lista, 2);
  agregar(lista, 3);
  agregar(lista, 4);
  agregar(lista, 5);
  mostrar(lista);

  eliminar(lista, 5);
  mostrar(lista);

  return 0;
}

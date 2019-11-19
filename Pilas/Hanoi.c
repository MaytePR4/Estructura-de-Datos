#include <stdio.h>

void hanoi(int n, char origen, char temporal, char destino);

int main()
{
	char origen='A', temporal='B', destino='C';
	int n=0;

	n=1;
	hanoi(n, origen, temporal, destino);
	printf("\n\n\n"); 

	n=2;
	hanoi(n, origen, temporal, destino);
	printf("\n\n\n"); 

	n=3;
	hanoi(n, origen, temporal, destino);
	printf("\n\n\n"); 

	return 0;
}

void hanoi(int n, char origen, char temporal, char destino)
{
	if(n==1)
	{
		printf("%c->%c", origen, destino);
		printf("\n");
	}
	else
	{
		hanoi(n-1, origen, destino, temporal);
		printf("%c->%c", origen, destino);
		printf("\n");
		hanoi(n-1, temporal, origen, destino);
	}
}




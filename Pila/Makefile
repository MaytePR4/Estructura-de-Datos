Pila.o: Pila.c
	gcc Pila.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o Pila.o
	gcc main.o Pila.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o Pila.o

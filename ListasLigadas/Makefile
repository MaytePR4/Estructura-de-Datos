Lligadas.o: Lligadas.c
	gcc Lligadas.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o Lligadas.o
	gcc main.o Lligadas.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o Lligadas.o

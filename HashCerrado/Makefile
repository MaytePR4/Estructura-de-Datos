HashCerrado.o: HashCerrado.c
	gcc HashCerrado.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o HashCerrado.o
	gcc main.o HashCerrado.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o HashCerrado.o

Circulares.o: Circulares.c
	gcc Circulares.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o Circulares.o
	gcc main.o Circulares.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o Circulares.o

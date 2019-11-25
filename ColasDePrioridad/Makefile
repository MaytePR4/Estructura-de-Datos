ColaPrd.o: ColaPrd.c
	gcc ColaPrd.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o ColaPrd.o
	gcc main.o ColaPrd.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o ColaPrd.o

listaCon.o: listaCon.c
	gcc listaCon.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o listaCon.o
	gcc main.o listaCon.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o listaCon.o

Cola.o: Cola.c
	gcc Cola.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o Cola.o
	gcc main.o Cola.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o Cola.o

DobleCirc.o: DobleCirc.c
	gcc DobleCirc.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o DobleCirc.o
	gcc main.o DobleCirc.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o DobleCirc.o

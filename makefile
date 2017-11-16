all: forkin.o
	gcc -o forkin forkin.o

forkin.o: forkin.c
	gcc -c forkin.c

run: all
	./forkin

clean:
	rm -rf *.o *~ runo

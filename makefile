all: forkin.c
	gcc -o forkin forkin.c
run: all
	./forkin
clean:
	rm *~	

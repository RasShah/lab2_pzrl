.PHONY: all clean run

all: launch

launch: main.o calculations.o bin.o oct.o hex.o
	gcc main.o calculations.o bin.o oct.o hex.o -o launch -lm
main.o: main.c 
	gcc -c main.c
calculations.o: calculations.c
	gcc -c calculations.c
bin.o: bin.c
	gcc -c bin.c 
oct.o: oct.c
	gcc -c oct.c
hex.o: hex.c
	gcc -c hex.c
run: launch
	./launch
clean:
	rm -rf *.o launch

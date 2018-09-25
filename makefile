build: dwarfland

dwarfland: tema1.o
	gcc -Wall tema1.o -o dwarfland -lm

tema1.o: tema1.c
	gcc -c tema1.c -o tema1.o 

run: dwarfland
	./dwarfland

clean:
	rm -f dwarfland tema1.o

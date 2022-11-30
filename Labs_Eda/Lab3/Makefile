programa: main.o Pila.o Error.o
	g++ -o programa main.o Pila.o Error.o -Wall
	
main.o: main.cpp Pila.h Error.h
	g++ -c main.cpp -Wall

Pila.o: Pila.h Pila.cpp
	g++ -c Pila.cpp -Wall

Error.o: Error.h Error.cpp
	g++ -c Error.cpp -Wall
	
clean:
	rm -f programa *.o

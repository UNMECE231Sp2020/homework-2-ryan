all: main.o Complex.o
	g++ main.o Complex.o -o Test
main.o: main.cpp Complex.h
	g++ -c main.cpp
Complex.o: Complex.cpp Complex.h	
	g++ -c Complex.cpp -o Complex.o
clean:
	rm*.o
	rm Test

all: main.o Complex.o
	g++ main.o Complex.o -o Test_now
main.o: main.cpp declarations.h
	g++ -c main.cpp
Complex.o: functions.cpp declarations.h	
	g++ -c functions.cpp -o Complex.o
clean:
	rm*.o
	rm Test_now

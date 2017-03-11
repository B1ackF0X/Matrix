all: Matrix

Matrix: main.o Matrix.o
		g++ main.o Matrix.o -o main

main.o: main.cpp
		g++ -c main.cpp

Matrix.o: Matrix.cpp
		g++ -c Matrix.cpp

clean:
		rm -rf *.o main

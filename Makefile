CC = g++ -Wall -std=c++11
CFLAG = -c

all: main.o bspline.o
	$(CC) main.o bspline.o -o tpModelisation

main.o: main.cpp bspline.hpp
	$(CC) $(CFLAG) main.cpp -o main.o

bspline.o: bspline.cpp bspline.hpp
	$(CC) $(CFLAG) bspline.cpp -o bspline.o

clean:
	rm *.o
	rm tpModelisation

all: Q1 Q2

Q1: Q1.o
	g++ -o Q1 Q1.o

Q1.o: Q1.cpp
	g++ -c Q1.cpp

Q2: Q2.o
	g++ -o Q2 Q2.o

Q2.o: Q2.cpp
	g++ -c Q2.cpp

clean:
	rm -rf *.o Q1 Q2
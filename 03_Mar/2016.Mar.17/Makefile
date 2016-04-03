all: main secondMain

main: main.o
	g++ -o main main.o

main.o: main.cpp
	g++ -c main.cpp

secondMain: secondMain.o
	g++ -o secondMain secondMain.o

secondMain.o:secondMain.cpp
	g++ -c secondMain.cpp

clean:
	rm -rf *.o main secondMain
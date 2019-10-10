project1: fraction.o point.o main.o
		g++ -o project1 fraction.o point.o main.o

fraction.o: fraction.cc fraction.h
		g++ -c fraction.cc

point.o: point.cc point.h fraction.h
		g++ -c point.cc 

main.o: main.cc fraction.h point.h
		g++ -c main.cc 
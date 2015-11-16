main:main.cpp poly.o
	g++ main.cpp -o main  poly.o
poly.o: poly.cpp
	g++ -c poly.cpp -o poly.o

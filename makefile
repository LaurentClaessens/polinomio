main:main.cpp poly.o
	g++ main.cpp -o main  poly.o
poly.o: poly.cpp
	g++ -c poly.cpp -o poly.o
monomio.o:monomio.cpp  grado.o
	g++ -c monomio.cpp -o monomio.o
grado.o:grado.cpp 
	g++ -c grado.cpp -o grado.o

laurent:laurent_test.cpp poly.o
	g++ laurent_test.cpp -o laurent  poly.o

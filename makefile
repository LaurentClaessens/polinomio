main:main.cpp poly.o
	g++ main.cpp -o main  poly.o
poly.o: poly.cpp Monomial.o
	g++ -c poly.cpp -o poly.o
Monomial.o:Monomial.cpp  grado.o
	g++ -c Monomial.cpp -o Monomial.o
grado.o:grado.cpp 
	g++ -c grado.cpp -o grado.o
laurent:laurent_test.cpp poly.o
	g++ laurent_test.cpp -o laurent  poly.o

main:main.cpp Polynomial.o
	g++ main.cpp -o main  Polynomial.o
Polynomial.o: Polynomial.cpp Monomial.o
	g++ -c Polynomial.cpp -o Polynomial.o
Monomial.o:Monomial.cpp  grado.o
	g++ -c Monomial.cpp -o Monomial.o
grado.o:grado.cpp 
	g++ -c grado.cpp -o grado.o
smartp.o:smartp.cpp 
	g++ -c smartp.cpp -o smartp.o
laurent:laurent_test.cpp Polynomial.o
	g++ laurent_test.cpp -o laurent  Polynomial.o

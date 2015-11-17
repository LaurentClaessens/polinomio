main:main.cpp Polynomial.o
	g++ main.cpp -o main  Polynomial.o
Polynomial.o: Polynomial.cpp Monomial.o
	g++ -c Polynomial.cpp -o Polynomial.o
Monomial.o:Monomial.cpp  Degree.o
	g++ -c Monomial.cpp -o Monomial.o
Degree.o:Degree.cpp 
	g++ -c Degree.cpp -o Degree.o
coefficiente.o:coefficiente.cpp coefficiente.h
	g++ -c coefficiente.cpp -o coefficiente.o
smartp.o:smartp.cpp 
	g++ -c smartp.cpp -o smartp.o
laurent:laurent_test.cpp Polynomial.o
	g++ laurent_test.cpp -o laurent  Polynomial.o
coef_test:coef_test.cpp Coefficient.o
	g++ coef_test.cpp -o coef_test   Coefficient.o

INCS=`root-config --cflags`
LIBS=`root-config --libs`


compila: main.o funzioni.o
	g++ -o esercizio5.5 main.o funzioni.o ${INCS} ${LIBS}

funzioni.o: funzioni.cpp funzioni.h
	g++ -c funzioni.cpp 

main.o: main.cpp funzioni.h
	g++ -c main.cpp  ${INCS} ${LIBS}

clean: 
	rm *.o esercizio5.5 graph.pdf

esegui: 
	./esercizio5.5

tutto: compila esegui
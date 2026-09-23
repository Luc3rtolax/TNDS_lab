INCS=`root-config --cflags`
LIBS=`root-config --libs`

esercizio_5.3: esercizio_5.3.o posizioni.o puntomateriale.o campovettoriale.o particella.o
	g++ -o esercizio_5.3 esercizio_5.3.o posizioni.o Puntomateriale.o Campovettoriale.o Particella.o ${LIBS}


esercizio_5.3.o: main.cpp Particella.h Puntomateriale.h posizioni.h Campovettoriale.h
	g++ -c main.cpp -o esercizio_5.3.o ${INCS}       



posizioni.o: posizioni.h
	g++ -c posizioni.cpp

particella.o: Particella.h
	g++ -c Particella.cpp

campovettoriale.o: Campovettoriale.h posizioni.h
	g++ -c Campovettoriale.cpp 

puntomateriale.o: Puntomateriale.h Campovettoriale.h posizioni.h Particella.h
	g++ -c Puntomateriale.cpp

compila:
	./esercizio_5.3

clean: 
	rm *.o
	rm graph.pdf
	rm esercizio_5.3

tutto: esercizio_5.3 compila

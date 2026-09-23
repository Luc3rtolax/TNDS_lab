myLibs=  Funzionebase.o  Integrali.o
INCS=`root-config --cflags`
LIBS=`root-config --libs`

esercizio7.1: main.cpp ${myLibs}
	g++ -Wall -o $@ $^ ${LIBS}  ${INCS}

%.o : %.cpp %.h
	g++ -Wall -c $< ${INCS} ${LIBS}

compila:
	./esercizio7.1 100

tutto: esercizio7.1 compila

clean: 
	rm esercizio7.1 *.o
	rm Graph.pdf
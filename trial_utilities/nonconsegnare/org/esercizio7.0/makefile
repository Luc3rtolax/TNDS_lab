myLibs=  Funzionebase.o  Integrali.o
INCS=`root-config --cflags`
LIBS=`root-config --libs`

esercizio7.0: main.cpp ${myLibs}
	g++ -Wall -o $@ $^ ${LIBS}  ${INCS}

%.o : %.cpp %.h
	g++ -Wall -c $< ${INCS} ${LIBS}

compila: esercizio7.0

esegui: 
	./esercizio7.0 100
	

tutto: esercizio7.0 compila

clean: 
	rm esercizio7.0 *.o
	rm Graph.pdf
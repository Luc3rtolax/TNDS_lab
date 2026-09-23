myLibs= EsperimentoPrisma.o Funzioni.o Randomgen.o 
INCS=`root-config --cflags`
LIBS=`root-config --libs`

esercizio12.0: main.cpp ${myLibs}
	g++ -Wall -o $@ $^ ${LIBS}  ${INCS}

%.o : %.cpp %.h
	g++ -Wall -c $< ${INCS} ${LIBS}

compila: esercizio12.0 

esegui: 
	./esercizio12.0 

tutto: esercizio12.0 esegui

clean:
	rm *.o esercizio12.0 *.pdf


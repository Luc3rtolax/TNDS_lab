myLibs= Randomgen.o Funzionebase.o IntegraleMC.o Funzioni.o
INCS=`root-config --cflags`
LIBS=`root-config --libs`

esercizio10.2: main_analisi.cpp ${myLibs}
	g++ -Wall -o $@ $^ ${LIBS}  ${INCS}

%.o : %.cpp %.h
	g++ -Wall -c $< ${INCS} ${LIBS}

compila: esercizio10.2 

esegui: 
	./esercizio10.2 10000

tutto: esercizio10.2 esegui

clean:
	rm *.o esercizio10.2 *.pdf


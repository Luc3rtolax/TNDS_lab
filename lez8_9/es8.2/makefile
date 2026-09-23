myLibs=  Funzionebase.o  Integrali.o Equazionidifferenz.o Vectoroperators.o
INCS=`root-config --cflags`
LIBS=`root-config --libs`

esercizio8.2: main.cpp ${myLibs}
	g++ -Wall -o $@ $^ ${LIBS}  ${INCS}

%.o : %.cpp %.h
	g++ -Wall -c $< ${INCS} ${LIBS}

compila: esercizio8.2

esegui:
	./esercizio8.2 0.01
	
	
tutto: esercizio8.2 esegui

clean:
	rm *.o esercizio8.2 graph.pdf



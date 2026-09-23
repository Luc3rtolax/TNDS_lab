myLibs=  Funzionebase.o  Integrali.o Equazionidifferenz.o Vectoroperators.o
INCS=`root-config --cflags`
LIBS=`root-config --libs`

esercizio8.4: main.cpp ${myLibs}
	g++ -Wall -o $@ $^ ${LIBS}  ${INCS}

%.o : %.cpp %.h
	g++ -Wall -c $< ${INCS} ${LIBS}

compila: esercizio8.4
	
esegui:
	./esercizio8.4 0.01


tutto: esercizio8.4 esegui


clean:
	rm *.o esercizio8.4 graph.pdf



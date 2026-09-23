myLibs= Randomgen.o Funzionebase.o
INCS=`root-config --cflags`
LIBS=`root-config --libs`

esercizio10.1: main.cpp ${myLibs}
	g++ -Wall -o $@ $^ ${LIBS}  ${INCS}

%.o : %.cpp %.h
	g++ -Wall -c $< ${INCS} ${LIBS}

compila: esercizio10.1 

esegui: 
	./esercizio10.1

tutto: esercizio10.1 esegui

clean:
	rm *.o esercizio10.1 graph.pdf


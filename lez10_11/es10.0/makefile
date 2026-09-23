myLibs= Randomgen.o Funzionebase.o
INCS=`root-config --cflags`
LIBS=`root-config --libs`

esercizio10.0: main.cpp ${myLibs}
	g++ -Wall -o $@ $^ ${LIBS}  ${INCS}

%.o : %.cpp %.h
	g++ -Wall -c $< ${INCS} ${LIBS}

compila: esercizio10.0 

esegui: 
	./esercizio10.0

tutto: esercizio10.0 compila

clean:
	rm *.o esercizio10.0 graphs.pdf


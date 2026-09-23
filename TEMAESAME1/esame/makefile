myLibs=  Funzionebase.o  Integrali.o Randomgen.o IntegraleMC.o Funzioni.o
INCS=`root-config --cflags`
LIBS=`root-config --libs`

esercizio: main.cpp ${myLibs}
	g++ -Wall -o $@ $^ ${LIBS}  ${INCS}

%.o : %.cpp %.h
	g++ -Wall -c $< ${INCS} ${LIBS}

compila: esercizio

esegui:
	./esercizio 0.0001 100
	

tutto: esercizio esegui

clean: 
	rm  *.o *.pdf esercizio
	

# .PHONY: build
# build:
# 	bash ./build.sh
#rm *.o esercizio7.2 Graph.pdf
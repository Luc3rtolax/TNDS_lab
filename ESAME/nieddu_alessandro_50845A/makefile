myLibs=  Funzionebase.o  Integrali.o Randomgen.o IntegraleMC.o Funzioni.o Solutore.o
INCS=`root-config --cflags`
LIBS=`root-config --libs`

compito: main.cpp ${myLibs}
	g++ -Wall -o $@ $^ ${LIBS}  ${INCS}

%.o : %.cpp %.h
	g++ -Wall -c $< ${INCS} ${LIBS}

compila: compito

esegui:
	./compito 0.0001 100
	

tutto: compito esegui

clean: 
	rm  *.o *.pdf compito
	

# .PHONY: build
# build:
# 	bash ./build.sh
#rm *.o esercizio7.2 Graph.pdf
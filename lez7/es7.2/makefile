myLibs=  Funzionebase.o  Integrali.o
INCS=`root-config --cflags`
LIBS=`root-config --libs`

esercizio7.2: main.cpp ${myLibs}
	g++ -Wall -o $@ $^ ${LIBS}  ${INCS}

%.o : %.cpp %.h
	g++ -Wall -c $< ${INCS} ${LIBS}

compila: esercizio7.2

esegui:
	./esercizio7.2 0.0001 100
	

tutto: esercizio7.2 esegui

clean: 
	rm  *.o Graph.pdf esercizio7.2
	

# .PHONY: build
# build:
# 	bash ./build.sh
#rm *.o esercizio7.2 Graph.pdf
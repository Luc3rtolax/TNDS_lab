LIBS:=`root-config --libs`
INCS:=`root-config --cflags`


esercizio4.3: main.cpp funzioni.h posizioni.h
	g++ -o esercizio4.3 main.cpp  ${LIBS} ${INCS}


compila: 
	./esercizio4.3 dati.txt

clean: 
	rm esercizio4.3
	rm graf.pdf

tutto: esercizio4.3 compila
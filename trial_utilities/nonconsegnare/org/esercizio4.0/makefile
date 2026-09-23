LIBS:=`root-config --libs`
INCS:=`root-config --cflags`



compila: main.cpp funzioni.h
	g++ -o esercizio4.0 main.cpp ${INCS} ${LIBS} 

clean: 
	rm esercizio4.0
	rm trend.pdf
	
tutto: compila esegui

esegui: 
	./esercizio4.0

grafico: 
	evince trend.pdf

LIBS:=`root-config --libs`
INCS:=`root-config --cflags`


compila: main.cpp lib.h
	g++ -o esercizio3.2  main.cpp ${INCS} ${LIBS}
esegui:
	./esercizio3.2 1941.txt
clean: 
	rm  esercizio3.2 
tutto: compila esegui
	

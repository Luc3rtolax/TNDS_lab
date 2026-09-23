myLibs=  Funzionebase.o  Solutore.o

esercizio6.2: main.cpp ${myLibs}
	g++ -Wall -o $@ $^ 

%.o : %.cpp %.h
	g++ -Wall -c $< 

compila: esercizio6.2

esegui:
	./esercizio6.2

tutto: compila	esegui

clean: 
	rm esercizio6.2 *.o
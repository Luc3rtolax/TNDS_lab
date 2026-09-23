myLibs=  Funzionebase.o  Solutore.o

esercizio6.3: main.cpp ${myLibs}
	g++ -Wall -o $@ $^ 

%.o : %.cpp %.h
	g++ -Wall -c $<

compila: esercizio6.3 

esegui:
	./esercizio6.3

tutto: esercizio6.3 compila

clean: 
	rm esercizio6.3 *.o
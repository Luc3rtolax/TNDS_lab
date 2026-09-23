esercizio1.3: main.o lib.o
	g++ -o esercizio1.3 main.o lib.o


main.o: main.cpp lib.h
	g++ -c main.cpp


library.o: lib.cpp lib.h
	g++ -c lib.cpp

# Comando per compilare tutto
compila: esercizio1.3

# Comando per eseguire il programma
esegui:
	./esercizio1.3 365 1941.txt

# Comando per fare tutto: compilazione + esecuzione
tutto: compila esegui

# Comando per pulire i file oggetto e l'eseguibile
clean:
	rm -f *.o esercizio1.3 results.txt

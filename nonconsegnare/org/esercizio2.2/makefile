esercizio2.2: main.o lib.o
	g++ -o esercizio2.2 main.o lib.o


main.o: main.cpp lib.h Vector.h
	g++ -c main.cpp


library.o: lib.cpp lib.h Vector.h
	g++ -c lib.cpp

# Comando per compilare tutto
compila: esercizio2.2

# Comando per eseguire il programma
esegui:
	./esercizio2.2 365 1941.txt data.out

# Comando per fare tutto: compilazione + esecuzione
tutto: compila esegui

# Comando per pulire i file oggetto e l'eseguibile
clean:
	rm -f *.o esercizio2.2 *.out

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "Vector.h"

using namespace std;

double Media (const Vector&); // prendo lo stesso vettore non ne creo un altro
double Varianza (const Vector&);
double Mediana (Vector&);

Vector Carica_dati (int , const char* );
void Sel_Sort (Vector&);
void print (Vector );
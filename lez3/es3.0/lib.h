#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Vettore.h"
using namespace std;

template <typename T> T Media (const Vettore<T>&); // prendo lo stesso vettore non ne creo un altro
template <typename T> T  Varianza (const Vettore<T>&);
template <typename T> T  Mediana (Vettore<T>&);

template <typename T>  Vettore<T> Carica_dati (int , const char* );
template <typename T>  void Sel_Sort (Vettore<T>&);
template <typename T>  void print (Vettore<T>);


template <typename T> Vettore<T> Carica_dati (int n, const char* f) {
    ifstream fin (f);
    Vettore <T> V(n);
    if (!fin) {
        cout << "File non aperto correttamente "<< endl;
        exit (-1);
    }
    for (int i=0; i<n; i++) {
        T a;
        fin >> a;
        V.SetComponent (i ,a );
       }   
       
    fin.close();
    return V;
};

template <typename T> T Media (const Vettore<T>& V) {
    T acc=0;
    for (int i=0; i<V.GetN(); i++) {
        acc += V.GetComponent(i);
    }
    return acc/V.GetN();
};

template <typename T> T Varianza (const Vettore<T>& V) {
    T acc=0;
    T media=Media(V);
    for (int i=0; i<V.GetN(); i++  ) {
        acc += pow(V.GetComponent(i)-media, 2);
    }
    return acc/V.GetN();
};

template <typename T> void Sel_Sort (Vettore<T>& V) {
    for (int i=0; i<V.GetN(); i++ ) {
        for (int j=i+1; j<V.GetN(); j++) {
            if (V.GetComponent(i)>V.GetComponent(j)) {
                V.Scambia(i, j);
            }
        }
    }
};

template <typename T> T Mediana ( Vettore<T>& V) {
    Sel_Sort(V);
    int num=V.GetN();
    if (num%2==0) {
        return (V.GetComponent(num/2 -1)+V.GetComponent((num/2)/2));
    } else {
        return V.GetComponent(num/2);
    }
};

template <typename T> void print (Vettore<T> V) {
    for (int i=0; i<V.GetN(); i++) cout << V[i] <<endl;
};
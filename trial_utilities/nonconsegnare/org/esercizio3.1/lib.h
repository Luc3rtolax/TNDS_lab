#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T> double Media (const vector<T>&); // prendo lo stesso vettore non ne creo un altro
template <typename T> double  Varianza (const vector<T>&);
template <typename T> double  Mediana (vector<T>&);

template <typename T>  vector<T> Carica_dati (const char* );
template <typename T>  void print (vector<T>);
template <typename T>  void print (vector<T>, const char* );


template <typename T> vector<T> Carica_dati ( const char* f) {
    ifstream fin (f);
    vector <T> V;
    if (!fin) {
        cout << "File non aperto correttamente "<< endl;
        exit (-1);
    }
    while(fin) {
        T a;
        fin >> a;
        V.push_back(a);
    }
       
    fin.close();
    return V;
};

template <typename T> double Media (const vector<T>& V) {
    T acc=0;
    for (int i=0; i<V.size(); i++) {
        acc += V[i];
    }
    return acc/V.size();
};

template <typename T> double Varianza (const vector<T>& V) {
    T acc=0;
    T media=Media(V);
    for (int i=0; i<V.size(); i++  ) {
        acc += pow(V[i]-media, 2);
    }
    return acc/V.size();
};


template <typename T> double Mediana ( vector<T>& V) {
    sort(V.begin(), V.end());
    int num=V.size()-1;
    if (num%2==0) {
        double a;
        a=(num/2)/2;
        return (V[num/2 -1]+V[a]);
    } else {
        return V[num/2];
    }
};

template <typename T> void print (vector<T> V) {
    for (int i=0; i<V.size(); i++) cout << V[i] <<endl;
};

template <typename T>  void print (vector<T> V, const char* f) {
    ofstream fout;
    fout.open (f);
    for (int i=0; i< V.size(); i++ ) {
       
        fout <<  V[i] << endl;
    }
    fout << "Media: " << Media<double> (V)<< endl;
    fout << "Varianza: "<< Varianza<double> (V) << endl;
    fout << "Mediana: " << Mediana<double> (V) << endl;
    for (int i=0; i< V.size(); i++ ) {
        fout <<  V[i]<< endl;
    }
    fout.close();
}
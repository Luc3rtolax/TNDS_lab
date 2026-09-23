#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "TCanvas.h"
#include "TApplication.h"
#include "TH1F.h"
using namespace std;


template <typename T>  vector<T> Carica_dati (const char* );



template <typename T> vector<T> Carica_dati ( const char* f) {
    ifstream fin (f);
    vector <T> V;
    if (!fin) {
        cout << "File non aperto correttamente "<< endl;
        exit (-1);
    }


    T a;
    while(fin >> a) {
       //T a;
       // fin >> a;
        V.push_back(a);
    }
       
    fin.close();
    return V;
};


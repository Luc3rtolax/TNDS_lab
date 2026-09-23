#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include "TCanvas.h"
#include "TApplication.h"
#include "TH1F.h"
#include "TGraphErrors.h"

using namespace std;

template <typename T>
double Media(const vector<T> &); // prendo lo stesso vettore non ne creo un altro
template <typename T>
double somma_qdrt(const vector<T> &);

template <typename T>
vector<T> Carica_dati(const char *);
template <typename T>
double Error(const vector<T> &);

template <typename T>
vector<T> diminuisci_vector(const vector<T> &);

template <typename T>
vector<T> Carica_dati(const char *f)
{
    ifstream fin(f);
    vector<T> V;
    if (!fin)
    {
        cout << "File non aperto correttamente " << endl;
        exit(-1);
    }
    while (fin)
    {
        T a;
        fin >> a;
        V.push_back(a);
    }

    fin.close();
    return V;
};

template <typename T>
double Media(const vector<T> &V)
{

    T acc = 0;
    for (int i = 0; i < V.size(); i++)
    {

        acc += V[i];
    }
    return acc / V.size();
};

template <typename T>
double somma_qdrt(const vector<T> &V)
{

    T acc = 0;

    T media = Media<double>(V);

    for (int i = 0; i < V.size(); i++)
    {

        acc += pow(V[i] - media, 2);
    }
    return acc;
};

template <typename T>
double Error(const vector<T> &V)
{

    double sm = somma_qdrt<double>(V);

    int n = V.size();

    return sqrt(sm / n);
};

template <typename T>
vector<T> diminuisci_vector(int m, const vector<T> &V)
{
    int n = V.size();
    vector<T> v;
    for (int i = 0; i < n; i += m)
    {
        v.push_back(V[i]);
    }
    return v;
};

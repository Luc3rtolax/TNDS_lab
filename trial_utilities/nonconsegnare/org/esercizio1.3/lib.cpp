#include "lib.h"

double contarighe (const char* f){
    double dim = 1;
    ifstream in (f);
    string s;
    getline(in,s);
    if (!in){
        return -1;
    }
    while (!in.eof()){
        getline(in,s);
        dim ++;
    }
    return dim;
}

double* carica_dati(const char* f){
    
    int n=contarighe(f);
    double* D= new double[n];
    ifstream in;
    in.open (f);
    for (int i=0; i<n; i++) in >> D[i];
    in.close();
    return D;
}

double media_dati (double* D, double n) {
    double m=0;
    for (int i=0; i<n; i++){
        m += D[i];
    }
    return m/n;
}

double varianza (double* D, double n) {
    double m=media_dati(D, n);
    double v=0;
    for (int i=0; i<n; i++) {
        v+= pow(D[i]-m, 2);
        }
    return v/n;
}
void swap_double (double& a, double& b) {
    double c=a;
    a=b;
    b=c;
}

double* ordine_cr (double* D, double n) {
    int num=n;
    double* N=new double[num];
    for (int i=0; i<n; i++) {
        N[i]=D[i];
    }

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (N[i]>N[j]){
                swap (N[i],N[j]);
            }
        }
    }
    return N;
}

double mediana (double* D, double n) {
    int num=n;
    if (num%2==0) {
        return (D[num/2 -1]+D[num/2])/2;
    } else {
        return D[num/2];
    }
}

void print (double* D, int n, double m, double v, double med) {
    cout << "I dati in ordine di giorni sono: "<< endl;
    for (int i=0; i<n; i++) {
        cout << D[i] << endl;
    }
    cout << endl << "La media è "<< m<< endl;
    cout << "La varianza è "<< v<< endl;
    cout << "La mediana è "<< med << endl;
}

void print (double* D, int n, double m, double v, double med, const char* f) {
    ofstream fout;
    fout.open (f);
    fout << "I dati in ordine di giorni sono: "<< endl;
    for (int i=0; i<n; i++) {
        fout << D[i] << endl;
    }
    fout << endl << "La media è "<< m<< endl;
    fout << "La varianza è "<< v<< endl;
    fout << "La mediana è "<< med << endl;
    fout.close ();
}


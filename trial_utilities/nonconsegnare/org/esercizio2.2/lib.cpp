#include "lib.h"
#include "Vector.h"

Vector::Vector() {
    m_N=0;
    m_v=NULL;
}

Vector:: Vector(int  n) {
    m_N=n;
    m_v=new double[n];
    for (unsigned int i=0; i<n; i++) m_v[i]=0.;
}

Vector:: ~Vector() {
    delete [] m_v;
}

void Vector:: SetComponent(int i, double a) {
    if (i<m_N){
        m_v[i]=a;
    }    else {
            cout << "Indice non esiste " << endl;
            throw (3);
    }
}

double Vector:: GetComponent(int i) const {
    if (i<m_N) {
        return m_v[i];
    } else {
        cout << "Indice non esiste " << endl;
        throw (3);
    }
}

void Vector:: Scambia(int i, int j) {
    double z=GetComponent(i);
    SetComponent(i, GetComponent(j));
    SetComponent(j, z);
}

Vector:: Vector (const Vector& V) {
    m_N=V.GetN();
    m_v=new double[m_N];
    for (int i=0; i<m_N; i++ ) m_v[i]=V.GetComponent(i);
}

Vector& Vector:: operator=(const Vector& V) {
    m_N= V.GetN();
    if (m_v ) delete [] m_v;
    m_v=new double[m_N];
    for (int i=0; i<m_N; i++ ) m_v[i]=V.GetComponent(i);
    return *this;
}

double& Vector:: operator[] (int i) {
    if ( i<m_N ) {
    return m_v[i];
  } else {
    cout << "Errore: indice "<< endl;
    throw (3);
}}

Vector Carica_dati (int n, const char* f) {
    ifstream fin;
    fin.open (f);
    Vector V(n);
    for (int i=0;i<n; i++) {
        double a;
        fin >> a;
        V.SetComponent(i, a);
    }
    fin.close ();
    return V;
}

double Media (const Vector& V) {
    double acc=0;
    for (int i=0; i<V.GetN(); i++) {
        acc += V.GetComponent(i);
    }
    return acc/V.GetN();
}

double Varianza (const Vector& V) {
    double acc=0;
    double media=Media(V);
    for (int i=0; i<V.GetN(); i++  ) {
        acc += pow(V.GetComponent(i)-media, 2);
    }
    return acc/V.GetN();
}

void Sel_Sort (Vector& V) {
    for (int i=0; i<V.GetN(); i++ ) {
        for (int j=i+1; j<V.GetN(); j++) {
            if (V.GetComponent(i)>V.GetComponent(j)) {
                V.Scambia(i, j);
            }
        }
    }
}

double Mediana ( Vector& V) {
    Sel_Sort(V);
    int num=V.GetN();
    if (num%2==0) {
        return (V.GetComponent(num/2 -1)+V.GetComponent((num/2)/2));
    } else {
        return V.GetComponent(num/2);
    }
}

void print (Vector V) {
    for (int i=0; i<V.GetN(); i++) cout << V[i] <<endl;
}
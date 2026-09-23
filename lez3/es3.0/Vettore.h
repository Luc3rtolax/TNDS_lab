#ifndef Vettoreh
#define Vettoreh

#include <iostream>
using namespace std;

template <typename T> class Vettore {
    public:

    Vettore();
    Vettore(int );

    ~Vettore ();

    //copy constructor
    Vettore(const Vettore&);
    //operatore assegnaz
    Vettore& operator=(const Vettore& );

    int GetN() const {return m_N;};
    void SetComponent (int, T);
    T GetComponent (int) const;

    void Scambia (int , int );

    T& operator[] (int );


    private:

    int m_N;
    T* m_v;

};




template <typename T> Vettore<T>:: Vettore() {
    m_N=0;
    m_v=NULL;
};

template <typename T> Vettore<T>::Vettore(int  n) {
    m_N=n;
    m_v=new T[n];
    for (unsigned int i=0; i<n; i++) m_v[i]=0.;
};

template <typename T> Vettore<T>:: ~Vettore() {
    delete [] m_v;
};

template <typename T> void Vettore<T>:: SetComponent(int i, T a) {
    if (i<m_N){
        m_v[i]=a;
    }    else {
            cout << "Indice non esiste " << endl;
            throw (3);
    }
};

template <typename T> T Vettore<T>::  GetComponent(int i) const {
    if (i<m_N) {
        return m_v[i];
    } else {
        cout << "Indice non esiste " << endl;
        throw (3);
    }
};

template <typename T> void Vettore<T>::  Scambia(int i, int j) {
    double z=GetComponent(i);
    SetComponent(i, GetComponent(j));
    SetComponent(j, z);
};

template <typename T> Vettore<T>::Vettore (const Vettore& V) {
    m_N=V.GetN();
    m_v=new T[m_N];
    for (int i=0; i<m_N; i++ ) m_v[i]=V.GetComponent(i);
};

template <typename T> Vettore<T>& Vettore<T>::  operator=(const Vettore& V) {
    m_N= V.GetN();
    if (m_v ) delete [] m_v;
    m_v=new T[m_N];
    for (int i=0; i<m_N; i++ ) m_v[i]=V.GetComponent(i);
    return *this;
};

template <typename T> T& Vettore<T>::  operator[] (int i) {
    if ( i<m_N ) {
    return m_v[i];
  } else {
    cout << "Errore: indice "<< endl;
    throw (3);
}};


#endif 
#ifndef Vettoreh
#define Vettoreh

//#include "lib.h"


class Vector {
    public:

    Vector();
    Vector(int );

    ~Vector ();

    //copy constructor
    Vector(const Vector&);
    //operatore assegnaz
    Vector& operator=(const Vector& );

    int GetN() const {return m_N;};
    void SetComponent (int, double);
    double GetComponent (int) const;

    void Scambia (int , int );

    double& operator[] (int );


    private:

    int m_N;
    double* m_v;

};


#endif
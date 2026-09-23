#ifndef __Campovettoriale
#define __Campovettoriale
using namespace std;
#include "posizioni.h"
class Campovettoriale: public posizione{

    public:
    Campovettoriale(const posizione&);
    Campovettoriale(const posizione&, double Fx, double Fy, double Fz);
    Campovettoriale(double x, double y, double z, double Fx, double Fy, double Fz);

    Campovettoriale & operator+=( const Campovettoriale & ) ;
    Campovettoriale operator+( const Campovettoriale & ) const;

    double GetFx() const {return m_Fx;}
    double GetFy() const {return m_Fy;}
    double GetFz() const {return m_Fz;}

    void SetFx(double Fx) { m_Fx=Fx;}
    void SetFy(double Fy) { m_Fy=Fy;}
    void SetFz(double Fz) { m_Fz=Fz;}

    double Modulo() const;

    
    private:
    double m_Fx, m_Fy, m_Fz;
};



#endif
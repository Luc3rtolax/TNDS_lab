#include "Campovettoriale.h"

Campovettoriale:: Campovettoriale(const posizione& p): posizione(p){
    m_Fx=0;
    m_Fy=0;
    m_Fz=0;
};

Campovettoriale::   Campovettoriale(const posizione& p, double Fx, double Fy, double Fz): posizione(p) {
    m_Fx=Fx;
    m_Fy=Fy;
    m_Fz=Fz;
};

Campovettoriale::  Campovettoriale(double x, double y, double z, double Fx, double Fy, double Fz): posizione(x,y,z) {
    m_Fx=Fx;
    m_Fy=Fy;
    m_Fz=Fz;
};

Campovettoriale &  Campovettoriale::  operator+=( const Campovettoriale & v) {
    return (*this) = (*this)+v;
};

Campovettoriale   Campovettoriale:: operator+( const Campovettoriale & v) const {

    if ( ( v.GetX()!= GetX() ) || ( v.GetY()!= GetY() ) || ( v.GetZ()!= GetZ() ) ) {
    std::cout << "Somma di campi vettoriali in punti diversi non ammessa" << std::endl;
    exit (-11) ;
    } 
    Campovettoriale sum ( posizione( GetX(),GetY(), GetZ()) ) ; // creo un campo vettoriale nella posizione giusta
        sum.SetFx( GetFx() + v.GetFx()) ;  
        sum.SetFy( GetFy() + v.GetFy()) ;  
        sum.SetFz( GetFz() + v.GetFz()) ;  
    return sum;
};

double Campovettoriale:: Modulo() const{
    return sqrt(m_Fx*m_Fx+m_Fy*m_Fy+m_Fz*m_Fz);
};
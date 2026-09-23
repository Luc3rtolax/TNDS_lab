#include "funzioni.h"


    double posizione:: getDistance () const{
        return  sqrt( m_x*m_x + m_y * m_y + m_z * m_z );
    }
    double posizione:: GetX ()const  { return m_x;}
    double posizione:: GetY () const { return m_y;}
    double posizione:: GetZ () const { return m_z;}
    double posizione:: GetR() const {return sqrt( m_x*m_x + m_y * m_y + m_z * m_z );}
    double posizione:: GetTheta() const {return acos(m_z/GetR());}
    double posizione:: GetPhi() const {return atan2(m_y,m_x);}
    double posizione:: GetRho() const {return sqrt(m_x*m_x+m_y*m_y);}
    
   
    void posizione:: printPositions() { cout << "Posizione : x = " << m_x << " y = " << m_y << " z = " << m_z << endl; }



posizione posizione:: operator =(const posizione& p) {
  posizione a(p.m_x, p.m_y, p.m_z);
  return a;
};
 double posizione:: getDistance ( const posizione& p ) const {     
    double dx = p.GetX() - GetX() ;
    double dy = p.GetY() - GetY() ;
    double dz = p.GetZ() - GetZ() ;
    return sqrt(  dx*dx + dy*dy + dz*dz ) ;  
    } ;


void Particella:: print() const {
    cout << "Particella: massa="<< GetMassa()<< " carica="<<GetCarica() << endl;
};


Elettrone:: Elettrone(): Particella(9.1093826E-31,-1.60217653E-19) {

};
void Elettrone:: print() const {
    cout << "Elettrone: massa="<< GetMassa()<< " carica="<<GetCarica() << endl;
};

Protone:: Protone(): Particella(1.67E-27,-1.60217653E-19) {

};

void Protone:: print() const {
    cout << "Protone: massa="<< GetMassa()<< " carica="<<GetCarica() << endl;
};


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


Puntomateriale:: Puntomateriale(double massa, double carica, const posizione& p): posizione(p), Particella(massa, carica) {;};
Puntomateriale:: Puntomateriale(double massa, double carica, double x, double y, double z): posizione(x,y,z), Particella(massa, carica) {;};


Campovettoriale Puntomateriale:: CampoElettrico (const posizione& p) const {
    double C=8.99E9;
    if (p.getDistance()==0) {
        cout << "Campo nell'origine"<< endl;
        exit (12);
    }
    C=C*GetCarica()/pow(p.getDistance(),3);
    double dx,dy,dz;
    dx=p.GetX()-GetX();
    dy=p.GetY()-GetY();
    dz=p.GetZ()-GetZ();

    Campovettoriale v(p, C*dx, C*dy, C*dz);
    return v;
    

};

Campovettoriale Puntomateriale:: CampoGravitazionale(const posizione& p) const {
    double G=6.67E-11;
    if (p.getDistance()==0) {
        cout << "Campo nell'origine"<< endl;
        exit (12);
    }
    G=G*GetMassa()/pow(p.getDistance(),3);
    double dx,dy,dz;
    dx=p.GetX()-GetX();
    dy=p.GetY()-GetY();
    dz=p.GetZ()-GetZ();

    Campovettoriale v(p, G*dx, G*dy, G*dz);
    return v;

};




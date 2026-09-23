#include "posizioni.h"


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

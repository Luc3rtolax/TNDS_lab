#include <iostream>
using namespace std;

class posizione {
public:

  posizione() { m_x = 0 ; m_y = 0 ; m_z = 0; } ;

  posizione( double x, double y, double z ) { m_x = x; m_y=y ; m_z=z ; } ;


  double getDistance() const { return sqrt( m_x*m_x + m_y * m_y + m_z * m_z ) ;  } ;

  double GetX() const { return m_x ; } ;
  double GetY() const { return m_y ; } ;
  double GetZ() const { return m_z ; } ;

  void setX(double i) {m_x=i;};
  void setY(double i) {m_y=i;};

  void setZ(double i) {m_z=i;};

  double getDistance ( const posizione& p ) const {     
    double dx = p.GetX() - m_x ;
    double dy = p.GetY() - m_y ;
    double dz = p.GetZ() - m_z ;
    return sqrt(  dx*dx + dy*dy + dz*dz ) ;  
  } ;

  bool operator< ( const posizione & b ) const { return ( getDistance() < b.getDistance() ); } ;

  void printPositions() { cout << "Posizione : x = " << m_x << " y = " << m_y << " z = " << m_z << endl; }; 

  //posizione operator= (const posizione& p) ;

private:

  double m_x, m_y, m_z ;
};

// posizione posizione:: operator =(const posizione& p) {
//   posizione a(p.m_x, p.m_y, p.m_z);
//   return a;
// };

class comp_functor {

    public: 
        comp_functor() {m_ref.setX(0); m_ref.setY(0); m_ref.setZ(0);};
        comp_functor(posizione p) {m_ref=p;};
        bool operator() (const posizione& p1, const  posizione& p2) const { return p1.getDistance(m_ref)<p2.getDistance(m_ref);};

    private:
        posizione m_ref;
};


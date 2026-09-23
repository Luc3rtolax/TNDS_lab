#ifndef __posizioni
#define __posizioni
#include <iostream>
#include <cmath>
using namespace std;

class posizione {
public:

  posizione() { m_x = 0 ; m_y = 0 ; m_z = 0; } ;

  posizione( double x, double y, double z ) { m_x = x; m_y=y ; m_z=z ; } ;


  double getDistance() const;
//cartesiane
  double GetX() const ;
  double GetY() const ;
  double GetZ() const ;

  //sferiche
  double GetR() const;
  double GetTheta() const;
  double GetPhi() const;

  //cilindriche
  double GetRho() const;

  //cartesiane
  void SetX(double i) {m_x=i;};
  void SetY(double i) {m_y=i;};
  void SetZ(double i) {m_z=i;};
 

  double getDistance ( const posizione& p ) const ;

  bool operator< ( const posizione & b ) const { return ( getDistance() < b.getDistance() ); } ;

  void printPositions(); 

  posizione operator= (const posizione& p) ;

private:

  double m_x, m_y, m_z ;
};








class comp_functor {

    public: 
        comp_functor() {m_ref.SetX(0); m_ref.SetY(0); m_ref.SetZ(0);};
        comp_functor(posizione p) {m_ref=p;};
        bool operator() (const posizione& p1, const  posizione& p2) const { return p1.getDistance(m_ref)<p2.getDistance(m_ref);};

    private:
        posizione m_ref;
};

#endif
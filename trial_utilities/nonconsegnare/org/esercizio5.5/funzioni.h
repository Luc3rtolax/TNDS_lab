#include <iostream>
#include <cstdlib>
#include <cmath>

#include <string>
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

class Particella {
    public: 


    Particella() {m_m=0; m_c=0;};
    Particella(double m, double c) {m_m=m; m_c=c;};
    ~Particella() {};

    double GetMassa() const {return m_m;};
    double GetCarica() const {return m_c;};
    void print ()const;

    protected:
    double m_m;
    double m_c;
};

class Elettrone: public Particella {
    public:
    Elettrone();
    ~Elettrone() {};

    void print() const;
};

class Protone: public Particella {
    public:
    Protone();
    ~Protone() {};

    void print() const;
};



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


class Puntomateriale: public Particella , public posizione {
    public:

    Puntomateriale(double massa, double carica, const posizione&);
    Puntomateriale(double massa, double carica, double x, double y, double z);

    ~Puntomateriale() {;};

    Campovettoriale CampoElettrico (const posizione&) const;
    Campovettoriale CampoGravitazionale (const posizione&) const;
};




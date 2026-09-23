#include "Puntomateriale.h"

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


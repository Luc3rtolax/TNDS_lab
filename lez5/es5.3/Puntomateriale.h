#ifndef __Puntomateriale
#define __Puntomateriale

#include "posizioni.h"
#include "Campovettoriale.h"
#include "Particella.h"


class Puntomateriale: public Particella , public posizione {
    public:

    Puntomateriale(double massa, double carica, const posizione&);
    Puntomateriale(double massa, double carica, double x, double y, double z);

    ~Puntomateriale() {;};

    Campovettoriale CampoElettrico (const posizione&) const;
    Campovettoriale CampoGravitazionale (const posizione&) const;
};



#endif
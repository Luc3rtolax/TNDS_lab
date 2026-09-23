#include "Particella.h"

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
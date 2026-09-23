#include "lib.h"

int main (int argc, char** argv) {
    cout << "non inserire il numero dei dati" << endl;
    if (argc<3) {
        cout << "File inseriti in maniera sbagliata, corretto: "<< argv[0]<<" <nome_inpuntfile> <nome_outputfile> "<< endl;
        return 1;
    }   
    
    vector<double> V=Carica_dati<double> ( argv[1]);

    print<double> (V);
    print<double> (V, argv[2]);
    cout << "Media: " << Media<double> (V)<< endl;
    cout << "Varianza: "<< Varianza<double> (V) << endl;
    cout << "Mediana: " << Mediana<double> (V) << endl;
    

    print <double> (V);
   
    return 0;
}
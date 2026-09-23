#include "lib.h"
#include "Vector.h"

int main (int argc, char** argv) {

    if (argc<4) {
        cout << "File inseriti in maniera sbagliata, corretto:"<< argv[0]<<" <n_data> <nome_inpuntfile> <nome_outputfile> "<< endl;
        return 1;
    }

    int n_data=atoi(argv[1]);
     ofstream fout;
    fout.open( argv[3]);
    Vector V=Carica_dati (n_data, argv[2]);

    print (V);
    cout << "Media: " << Media (V)<< endl;
    cout << "Varianza: "<< Varianza (V) << endl;
    cout << "Mediana: " << Mediana (V) << endl;
    fout << "Media: " << Media (V)<< endl;
    fout << "Varianza: "<< Varianza (V) << endl;
    fout << "Mediana: " << Mediana (V) << endl;

    print (V);
    fout.close();
    

    return 0;
}
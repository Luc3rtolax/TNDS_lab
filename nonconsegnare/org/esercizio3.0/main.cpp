#include "lib.h"
#include "Vettore.h"

int main (int argc, char** argv) {

    if (argc<3) {
        cout << "File inseriti in maniera sbagliata, corretto:"<< argv[0]<<" <n_data> <nome_inpuntfile>  "<< endl;
        return 1;
    }

    
   
    int n_data=atoi(argv[1]);
    Vettore<double> V=Carica_dati<double> (n_data, argv[2]);

   
    


    print (V);
    cout << "Media: " << Media<double> (V)<< endl;
    cout << "Varianza: "<< Varianza<double> (V) << endl;
    cout << "Mediana: " << Mediana<double> (V) << endl;
    

    print (V);
   
    

    
    
    return 0;
}
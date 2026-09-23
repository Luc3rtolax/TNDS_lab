#include "lib.h"


int main (int argc, char** argv) {

    if (argc<3) {
        cout << "Uso scorretto, fare:"<< argv[0]<<" <n_data> <filename>" << endl;
        return -1;
    }
    double n_data=atof(argv[1]);
    char* file=argv[2];

    double* Dati=carica_dati(file);

    double media=media_dati (Dati, n_data);
    double var=varianza (Dati, n_data);

    double* ord=ordine_cr(Dati, n_data);
    double median=mediana (ord, n_data);
    int num=n_data;
    print (Dati, num,media, var, median);                   //stampa a video
    print (Dati, num,media, var, median, "results.txt");    //stampa su file   stesso nome funziona tramite overloading
     






    delete [] Dati;
    delete [] ord;
    return 0;

}
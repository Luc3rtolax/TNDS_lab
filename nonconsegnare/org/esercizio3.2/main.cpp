#include "lib.h"

int main (int argc, char** argv) {
    cout << "non inserire il numero dei dati" << endl;
    if (argc<2) {
        cout << "File inseriti in maniera sbagliata, corretto:"<< argv[0]<<"<nome_inpuntfile>  "<< endl;
        return 1;
    }

    vector<double> V=Carica_dati<double> ( argv[1]);

    TApplication app("App",0,0);

    TH1F h1 ("h1","Media Temp 1941",100, -20,20);
    h1.StatOverflows(kTRUE);
    for (int i=0; i<V.size(); i++) h1.Fill( V[i]);


    cout << "Media dei valori caricati = "<< h1.GetMean() << endl;
    
    
    TCanvas mycanvas ("h1","Media Temp 1941");
    h1.Draw();
    h1.GetXaxis()->SetTitle("delta temp (C^o)");
    
      
    app.Run();
    return 0;
}
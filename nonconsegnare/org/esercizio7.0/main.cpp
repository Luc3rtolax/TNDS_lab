#include "Funzionebase.h"
#include "Integrali.h"
#include <iomanip>
#include <cstdlib>
#include "TCanvas.h"
#include "TGraph.h"
#include "TApplication.h"
#include "TH1F.h"

//#define Singolopunto__

using namespace std;
double const Pi=3.141592653589793238462643383279502884197169399;

int main(int argc, char** argv) {

    #ifdef Singolopunto__
    if (argc<2) {
        cout << "Errore compilazione, usare: "<< argv[0]<< " <nsteps>"<< endl; 
        return 2;
    }
    unsigned int nsteps=atoi(argv[1]);
    #endif

    
    xsinx f;
    Midpoint integ(0,Pi/2);

    #ifdef Singolopunto__
    double I=integ.Integra(nsteps, f);
    cout << "Passi="<< setw(20)<<nsteps<< endl<< " Integrale della funzione xsinx tra 0 e pgreco/2 ="<<setw(20)<< I << endl;
    #endif

    TGraph g_errore;
    TCanvas c(".","errore di integrazione del metodo Midpoint");
    c.SetGridx();
    c.SetGridy();
    g_errore.SetTitle("Errore di integrazione del metodo Midpoint; numero di passi; errore assoluto");
    g_errore.Draw("AL");
    double Iv=1.;
    double I, err;
    unsigned int steps=10;

    for (unsigned int i=0; i<200; i++) {
        //h=(Pi/2)/steps;
        I=integ.Integra(steps,f);
        err=fabs(I-Iv);
        cout << steps << ") "<< err << endl;
        g_errore.SetPoint(i,steps, err);
        steps+=100;
    }


    c.SetLogy();
    c.SaveAs("Graph.pdf");



    return 0;
}
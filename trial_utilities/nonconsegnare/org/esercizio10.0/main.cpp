#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"


#include <iostream>

#include "Randomgen.h" 
#include "Funzionebase.h"
using namespace std;

int main()  {

    //dichiarazione elemente
    Randomgen myGen(1);
    Gauss G(1. ,1.);
    int nmax=10000;


    //cancas
    TCanvas C;
    C.Divide(2,2);
   
    C.cd(1);
    gPad->SetGridx();
    gPad->SetGridy();

        //uniforme
    TH1F unif("Uniforme", "Uniforme", 70, 4, 11);
    for (int k=0; k<nmax; k++) {
        unif.Fill(myGen.Unif(5.,10.));
    }
    unif.GetXaxis()->SetTitle("x [AU]");
    unif.GetYaxis()->SetTitle("N");
    unif.Draw();

    //exp
    C.cd(2);
    gPad->SetGridx();
    gPad->SetGridy();

    TH1F exp("Esponenziale", "Esponenziale", 70,0,10);
    for(int k=0; k<nmax; k++) {
        exp.Fill(myGen.Exp(1.));
    }
    exp.GetXaxis()->SetTitle("x [AU]");
    exp.GetYaxis()->SetTitle("N");
    exp.Draw();


    //Gaussiana box-muller
    C.cd(3);
    gPad->SetGridx();
    gPad->SetGridy();

    TH1F gauss("Gaussiana", "Gaussiana con media=1 e sigma=1", 70, -5, 7);
    for (int k=0; k<nmax; k++) {
        gauss.Fill(myGen.Gauss(1. , 1.));
    }
    gauss.GetXaxis()->SetTitle("x [AU]");
    gauss.GetYaxis()->SetTitle("N");
    gauss.Draw();

    //Gaussiana accept reject;

    C.cd(4);
    gPad->SetGridx();
    gPad->SetGridy();

    TH1F ar("Gaussian","Gaussiana accept-reject", 70 ,-5,7);
    
    for (int k=0; k<nmax; k++) {
        ar.Fill(myGen.Acceptreject(G, G.Getsigma()*5, -G.Getsigma()*5, G.Getmean()));
    }
    ar.GetXaxis()->SetTitle("x [AU]");
    ar.GetYaxis()->SetTitle("N");
    ar.Draw();



    

    C.Update();
    C.SaveAs("graphs.pdf");
    return 0;
}
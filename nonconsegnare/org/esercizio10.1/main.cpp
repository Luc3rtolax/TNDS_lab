#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"
#include "TPad.h"
#include "TAxis.h"
#include <vector>
#include <string>

#include <iostream>

#include "Randomgen.h" 
#include "Funzionebase.h"
using namespace std;

int main()  {

    //dichiarazione elemente
    Randomgen myGen(1);
    int max= 100000;

    TCanvas C("Verifica del teorema centrale", "Verifica del teorema centrale");
    TPad* PadA= new TPad("PadA", "Verifica del teorema centrale", 0.0, 0.5, 1.0, 1.0);
    PadA->Draw();
    PadA->cd();
    PadA->Divide(4,3);
    vector<double> varianza;
    double mean=0.5;
    for (int N=1; N<13; N++) {
        PadA->cd(N);
        string s="somma di " +to_string(N) + " elementi";
        TH1F* h=new TH1F(to_string(N).c_str(),s.c_str() ,100, -1, 12 ); 
        double var=0;
        
        for (int k=0; k<max; k++) {
            double rand=myGen.Sommarand(N);
            h->Fill(rand);
            var+=pow(rand-mean,2);
        }
        varianza.push_back(var/max);
        h->DrawCopy();
        mean+=0.5;
        delete h;
    }
    PadA->Modified();
    PadA->Update();
    
    C.Update();
    C.cd();
    TPad* PadB=new TPad("B", "Varianza all'aumentare di N", 0.0 ,0.0, 1.0, 0.5);
    PadB->Draw();
    PadB->cd();
    PadB->SetGridy();
    PadB->Modified();
    PadB->Update();
    TGraph V;
    for (unsigned int i=1; i<varianza.size(); i++) {
        V.SetPoint(i-1, i , varianza[i]);
    }
    V.SetMarkerStyle(29);
    V.SetMarkerColor(kBlue);
    V.SetTitle("Teorema del limite centrale");
    V.GetXaxis()->SetTitle("N");
    V.GetYaxis()->SetTitle("varianza");
    V.Draw("ALP");
    PadB->Modified();
    PadB->Update();
  


    C.cd();
    C.Update();


    C.SaveAs("graph.pdf");


    delete PadA;
    delete PadB;
    return 0;
}
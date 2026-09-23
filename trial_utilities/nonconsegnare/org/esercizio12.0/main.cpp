#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2.h"
#include "TGraph.h"
#include "TLegend.h"

#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

#include "Funzioni.h"
#include "EsperimentoPrisma.h"

#define N 10000
#define SEED 2849018

using namespace std;

int main()
{

    EsperimentoPrisma esp(SEED);

    vector<double> vth0, vth1, vth2, vdm1, vdm2, vn1, vn2, vA, vB;

    int pad=1;

    for(int i=0 ; i<N ; i++)
    {
        esp.Esegui();
        esp.Analizza();

        vth0.push_back(esp.getth0mis());
        vth1.push_back(esp.getth1mis());
        vth2.push_back(esp.getth2mis());

        vdm1.push_back(esp.getdm1mis());
        vdm2.push_back(esp.getdm2mis());

        vn1.push_back(esp.getn1mis());
        vn2.push_back(esp.getn2mis());

        vA.push_back(esp.getAmis());
        vB.push_back(esp.getBmis());

    }

    vector<TH1F*> istogrammi;
    vector<TH2F*> istogrammi2D;

    
    istogrammi.push_back(CreaIstogramma("hth0", "#theta_{0} misurato;rad;conteggi", vth0));
    istogrammi.push_back(CreaIstogramma("hth1", "#theta_{1} misurato;rad;conteggi", vth1));
    istogrammi.push_back(CreaIstogramma("hth2", "#theta_{2} misurato;rad;conteggi", vth2));
    istogrammi.push_back(CreaIstogramma("hdm1", "#delta_{m1} misurato;rad;conteggi", vdm1));
    istogrammi.push_back(CreaIstogramma("hdm2", "#delta_{m2} misurato;rad;conteggi", vdm2));
    istogrammi.push_back(CreaIstogramma("hn1", "n_{1} misurato;n;conteggi", vn1));
    istogrammi.push_back(CreaIstogramma("hn2", "n_{2} misurato;n;conteggi", vn2));
    istogrammi.push_back(CreaIstogramma("hA", "A misurato;A;conteggi", vA));
    istogrammi.push_back(CreaIstogramma("hB", "B misurato;B [m^{2}];conteggi", vB));

    istogrammi2D.push_back(CreaIstogramma2D("dcorr", "Residui 2D", vdm1, vdm2));
    istogrammi2D.push_back(CreaIstogramma2D("ncorr", "Residui n_{1,2}", vn1, vn2));
    istogrammi2D.push_back(CreaIstogramma2D("ABcorr", "Residui A e B", vA, vB));

    

    TCanvas canvasIstogrammi("canvasIstogrammi", "Distribuzioni", 1200, 1200);
    canvasIstogrammi.Divide(4,3);

    for(unsigned int i=0; i<istogrammi.size(); i++)
    {
        canvasIstogrammi.cd(pad);
        istogrammi[i]->Draw();
        pad++;
    }

    pad--;

    for(unsigned int i=0; i<istogrammi2D.size(); i++)
    {
        canvasIstogrammi.cd(pad);
        istogrammi2D[i]->Draw();
        pad++;
    }

    canvasIstogrammi.Print("Istogrammi.pdf");

    return 0;
}
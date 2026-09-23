#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TGraph.h"
#include "TLegend.h"

#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

#include "Funzioni.h"

using namespace std;

int main(int argc, char** argv)
{
    //TApplication app("app", &argc, argv);

    vector<int> valoriN {100, 500, 1000, 5000, 10000, 50000, 100000};
    vector<double> erroriMedia, erroriHitMiss;

    TCanvas canvasIstogrammi("canvasIstogrammi", "Distribuzioni - Media", 1200, 800);
    canvasIstogrammi.Divide(3, 3);

    TCanvas canvasIstogrammiHM("canvasIstogrammiHM", "Distribuzioni - Hit or Miss", 1200, 800);
    canvasIstogrammiHM.Divide(3, 3);

    vector<TH1F*> istogrammi, istogrammiHM;
    int pad = 1;

    for (int punti : valoriN) {

        vector<double> datiMedia   = LeggiFile("media_"   + to_string(punti) + ".txt");
        vector<double> datiHitMiss = LeggiFile("hitmiss_" + to_string(punti) + ".txt");

        string titolo = "N = " + to_string(punti) + ";Integrale;Conteggi";

        TH1F* h = new TH1F(("h_media_" + to_string(punti)).c_str(), titolo.c_str(), 100, 0.7, 1.3);
        for (double v : datiMedia) h->Fill(v);
        istogrammi.push_back(h);

        TH1F* hHM = new TH1F(("h_hitmiss_" + to_string(punti)).c_str(), titolo.c_str(), 100, 0.7, 1.3);
        for (double v : datiHitMiss) hHM->Fill(v);
        istogrammiHM.push_back(hHM);

        double meanMedia, meanHM;
        double stdMedia = DeviazioneStandard(datiMedia, meanMedia);
        double stdHM    = DeviazioneStandard(datiHitMiss, meanHM);

        erroriMedia.push_back(stdMedia);
        erroriHitMiss.push_back(stdHM);

        cout << "N = " << punti
             << "  media: " << meanMedia << " +- " << stdMedia
             << "   hit-or-miss: " << meanHM << " +- " << stdHM << endl;

        canvasIstogrammi.cd(pad);
        h->Draw();

        canvasIstogrammiHM.cd(pad);
        hHM->Draw();

        pad++;
    }
    canvasIstogrammi.SaveAs("distribuzioni_media.pdf");
    canvasIstogrammiHM.SaveAs("distribuzioni_hitmiss.pdf");

    TGraph gMedia, gHitMiss;
    for (size_t j = 0; j < valoriN.size(); j++) {
        gMedia.SetPoint(j, valoriN[j], erroriMedia[j]);
        gHitMiss.SetPoint(j, valoriN[j], erroriHitMiss[j]);
    }

    TCanvas canvasErrori("canvasErrori", "Errore vs N", 800, 600);
    canvasErrori.SetLogx();
    canvasErrori.SetLogy();
    canvasErrori.SetGrid();

    gMedia.SetTitle("Errore Monte Carlo;N;Deviazione standard");
    gMedia.SetMarkerStyle(20);
    gMedia.SetMarkerColor(kBlue);
    gMedia.SetLineColor(kBlue);
    gMedia.Draw("APL");

    gHitMiss.SetMarkerStyle(21);
    gHitMiss.SetMarkerColor(kRed);
    gHitMiss.SetLineColor(kRed);
    gHitMiss.Draw("PL SAME");

    TLegend leg(0.65, 0.75, 0.88, 0.88);
    leg.AddEntry(&gMedia, "Metodo della media", "lp");
    leg.AddEntry(&gHitMiss, "Hit-or-miss", "lp");
    leg.Draw();

    canvasErrori.SaveAs("errore_vs_N.pdf");

    for (TH1F* h : istogrammi) delete h;
    for (TH1F* h : istogrammiHM) delete h;

    return 0;
}
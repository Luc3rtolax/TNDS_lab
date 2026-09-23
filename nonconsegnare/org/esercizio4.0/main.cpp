#include "funzioni.h"

int main () {


    int alfa=12;
    string fname = "TemperatureMilano/" + to_string(alfa) + ".txt";


    int n= 2024-1941;
  
    TGraphErrors trend;
    int year=1941;

    for (int i=0; i< n; i++) {
        string fname = "TemperatureMilano/" + to_string(year) + ".txt";
        vector<double> v=Carica_dati<double>(fname.c_str());
        
        v=diminuisci_vector<double>(7, v);

        double media= Media<double> (v);
        double err= Error<double> (v);

        

        cout << "  Anno " << to_string(year) << "  delta medio = " << media << " +/- " << err <<  endl;

        trend.SetPoint(i, year, media);
        trend.SetPointError( i, 0 , err);
        year++;
    }

  
    



  TCanvas c("Temperature trend","Temperature trend");

    
  c.cd();
  c.SetGridx();
  c.SetGridy();

  trend.SetMarkerSize(1);
  trend.SetMarkerStyle(20);
  trend.SetFillColor(5);
  trend.SetMarkerColor(4);
  trend.SetLineWidth(0.01);

  trend.SetTitle("Temperature trend");
  trend.GetXaxis()->SetTitle("Anno");
  trend.GetYaxis()->SetTitle("#Delta (#circ C)");

  
  trend.Draw("apl3");
  trend.Draw("pX");

  c.SaveAs("trend.pdf");
  c.WaitPrimitive();

  return 0;
}
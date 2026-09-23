#include "Equazionidifferenz.h"
#include "Integrali.h"
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"
using namespace std;
int main(int argc, char** argv) {

    if (argc!=2) {
        cerr << "Usage: " << argv[0] << " <stepsize>" << endl;
        return -1;
    }

    Eulero euler;
    RangeKutta RK;

    Oscillatorearmonico osc(1.);

    double tmax=70.;
  
    double h=atof(argv[1]);
    
    vector<double> x {0. , 1.};
    double t=0.;

    TGraph graph;
    int nstep= int((tmax/h)+0.5);

    for (int step=0; step<nstep; step++) {
      graph.SetPoint(step,t,x[0]);
      x = RK.Passo(t,x,h,osc);
      t += h;
    }

    
  TCanvas c("c", "Oscillatore armonico", 800, 600);
  c.Divide(1,2);
  c.cd(1);
  c.SetGridx();
  c.SetGridy();
  string title = "Oscillatore armonico (Eulero h = " + convert(h) + ")" ;
  graph.SetTitle(title.c_str());
  graph.GetXaxis()->SetTitle("Tempo [s]");
  graph.GetYaxis()->SetTitle("Posizione x [m]");
  graph.Draw("ALP");





//////////////////////////////////





  TGraph error;
   
    double* hh = new double[10] {0.00009, 0.0001, 0.0002,  0.0005, 0.0009, 0.001, 0.002, 0.01, 0.05, 0.1};

    double somma;


  for (int y=0; y< 10; y++) {
    vector<double> v {0. , 1.};
    double t=0.;
    unsigned int step= int((tmax/hh[y])+0.5);
    for (unsigned int i=0; i<step; i++) {
      v = RK.Passo(t,v,hh[y],osc);
      t += hh[y];
    }
    somma=fabs(v[0]-sin(t));
    cout << y << "  "<< hh[y] << " "<< v[0] << " "<< somma<< endl;
    error.SetPoint(y,hh[y],somma);
  

  }
   
  c.cd(2);
  gPad->SetLogy();
  gPad->SetLogx();
  c.SetGridx();
  c.SetGridy();
  string titl = "Errore con metodo di Runge-Kutta " ;
  error.SetTitle(titl.c_str());
  error.GetXaxis()->SetTitle("Passo di integrazione h");
  error.GetYaxis()->SetTitle("Errore [m]");
  error.SetMarkerStyle(8);
  error.Sort();
  error.Draw("ALP");
  

  c.Update();
  c.SaveAs("graph.pdf");


  


  return 0;

}
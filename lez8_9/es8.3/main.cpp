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

#define AMAX 3
#define AMIN 0.1
#define ASPACE 0.1

int main(int argc, char **argv)
{

  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " <stepsize>" << endl;
    return -1;
  }

  Eulero euler;
  RangeKutta RK;

  Pendolo osc(1.);

  double tmax = 70.;

  double h = atof(argv[1]);

  vector<double> x{0., 1.};
  double t = 0.;

  TGraph graph;
  int nstep = int((tmax / h) + 0.5);

  for (int step = 0; step < nstep; step++)
  {
    graph.SetPoint(step, t, x[0]);
    x = RK.Passo(t, x, h, osc);
    t += h;
  }

  TCanvas c("c", "Pendolo", 800, 600);
  c.Divide(1, 2);
  c.cd(1);
  c.SetGridx();
  c.SetGridy();
  string title = "Pendolo (Runge-Kutta h = " + convert(h) + ")";
  graph.SetTitle(title.c_str());
  graph.GetXaxis()->SetTitle("Tempo [s]");
  graph.GetYaxis()->SetTitle("Posizione x [m]");
  graph.Draw("ALP");

  //////////////////////////////////

  double npoints = ((AMAX - AMIN) / ASPACE) + 1;

  TGraph graph2;

  for (unsigned int i = 0; i < npoints; i++)
  {
    double a = AMIN + i * ASPACE;

    vector<double> x{-a, 0.};
    double t = 0.;
    double v = 0.;

    while (v >= 0.)
    {
      v = x[1];
      x = RK.Passo(t, x, h, osc);
      t = t + h;
    }

    double t0 = t - h - v * h / (x[1] - v);
    double T = 4. * t0;

    graph2.SetPoint(i, a, T);
  }

  c.cd(2);
  graph2.SetTitle("Periodo del pendolo;Ampiezza [rad];Periodo [s]");
  graph2.SetMarkerStyle(20);
  graph2.Draw("AP");

  c.Update();
  c.SaveAs("graph.pdf");

  return 0;
}
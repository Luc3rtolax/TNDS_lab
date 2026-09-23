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

#define OMEGA0 10
#define ALPHA (1.0 / 30.0)
#define FORZANTE 10

#define FMIN 9
#define FMAX 11
#define FSPACE 0.05

int main(int argc, char **argv)
{

  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " <stepsize>" << endl;
    return -1;
  }

  Eulero euler;
  RangeKutta RK;

  Forzato osc(OMEGA0, ALPHA, FORZANTE);

  double tmax = (1 / ALPHA) * 10;
  // double tmax = 25;

  double h = atof(argv[1]);

  vector<double> x{0., 0.};
  double t = 0.;

  TGraph graph;
  int nstep = int((tmax / h) + 0.5);

  for (int step = 0; step < nstep; step++)
  {
    graph.SetPoint(step, t, x[0]);
    x = RK.Passo(t, x, h, osc);
    t += h;
  }

  TCanvas c("c", "Oscillatore forzato", 800, 600);
  c.Divide(1, 2);
  c.cd(1);
  c.SetGridx();
  c.SetGridy();
  string title = "Oscillatore forzato (Runge-Kutta h = " + convert(h) + ")";
  graph.SetTitle(title.c_str());
  graph.GetXaxis()->SetTitle("Tempo [s]");
  graph.GetYaxis()->SetTitle("Posizione x [m]");
  graph.Draw("ALP");

  //////////////////////////////////

  double npoints = ((FMAX - FMIN) / FSPACE) + 1;

  TGraph graph2;

  for (unsigned int i = 0; i < npoints; i++)
  {
    double a = FMIN + i * FSPACE;

    Forzato f(OMEGA0, ALPHA, a);

    vector<double> x{0., 0.};
    double t = 0.;
    // double v = 0.;
    // double d = 0.;

    for (int step = 0; step < nstep; step++)
    {
      x = RK.Passo(t, x, h, f);
      t += h;
    }
    while (x[1] < 0.)
    {
      x = RK.Passo(t, x, h, f);
      t += h;
    }

    double v = x[1];
    double d = x[0];

    while (v >= 0.)
    {
      v = x[1];
      d = x[0];
      x = RK.Passo(t, x, h, osc);
      t = t + h;
    }

    double ampiezza = d + (v / (v - x[1])) * (x[0] - d);

    graph2.SetPoint(i, a, ampiezza);
  }

  c.cd(2);
  graph2.SetTitle("Ampiezza dell'oscillatore; forzante[rad/s]; Ampiezza[m]");
  graph2.SetMarkerStyle(20);
  graph2.Draw("ALP");

  c.Update();
  c.SaveAs("graph.pdf");

  return 0;
}
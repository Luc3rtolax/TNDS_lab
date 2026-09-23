#include "Puntomateriale.h"

#include <cstdlib>
#include <cmath>
#include <iostream>
#include "TCanvas.h"
#include "TGraph.h"
#include "TApplication.h"
#include "TH1F.h"
//#define singolopunto

using namespace std;

int main(int argc, char** argv) {

    Elettrone e;
    Protone p;
    const double d=1.E-10;

    Puntomateriale elettrone(e.GetMassa(), e.GetCarica(),0.,0.,d/2.);
    Puntomateriale protone(p.GetMassa(),p.GetCarica(),0.,0.,-d/2.);


#ifdef singolopunto
    if ( argc!= 4) {
    cerr << "Usage: " << argv[0] << " <x> <y> <z>" << endl;
    exit(-1); 
    }

  
    posizione P( atof(argv[1]) , atof(argv[2]), atof(argv[3]) );
    Campovettoriale E = elettrone.CampoElettrico( P ) + protone.CampoElettrico( P ) ;

    cout << "E=(" << E.GetFx() << "," << E.GetFy() << "," << E.GetFz() << ")" << endl;
#endif
//ciclo per il grafico


double* graph=new double[901];
int y=0;
for (int i=100; i<1001; i++) {
    posizione s(0.,0.,i*d);
    Campovettoriale V=  elettrone.CampoElettrico( s) + protone.CampoElettrico( s) ;
    graph[y]=V.Modulo();
    cout << i<<") "<< graph[y]<< endl;
    y++;
};

TCanvas c("Campo elettrico ","Campo elettrico dipolo");

   c.cd();
  c.SetGridx();
  c.SetGridy();
  TGraph g(y);
for (int i = 0; i < y; i++) {
    g.SetPoint(i, 100 + i, graph[i]);
}
g.SetTitle("Campo elettrico dipolo; distanza (m^-10); |E|");
g.Draw("AL");
   
double a;
a=(log(graph[1]/graph[100]))/(log(101./200.));
cout << "asintotico a alfa^"<< a <<endl;

 
c.SaveAs("graph.pdf");


return  0;
}

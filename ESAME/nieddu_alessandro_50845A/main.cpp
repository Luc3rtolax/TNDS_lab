#include "Funzionebase.h"
#include "Integrali.h"
#include "IntegraleMC.h"
#include "Funzioni.h"
#include "Solutore.h"
#include "Randomgen.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "TCanvas.h"
#include "TGraph.h"
#include "TApplication.h"
#include "TH1F.h"
#include "TF1.h"

#define NSIMPSON 64
#define DELTA 0.01
#define punti 10000
#define deltaT 0.1

using namespace std;


int main()
{

    double x1, x2, x3;
    vector<double> u1={3.0,4.0};
    vector<double> u2={5.0,7.0};
    vector<double> u3={9.0,10.0};
    vector<double> MC1;
    double x1t, x2t;

    double prec;

    Bisezione Bis;
    funzES f;

    x1 = Bis.Cercazerireference(u1[0],u1[1],f);
    cout<<" x1 = "<<x1<<endl;

    x2 = Bis.Cercazerireference(u2[0],u2[1],f);
    cout<<" x2 = "<<x2<<endl;

    x3 = Bis.Cercazerireference(u3[0],u3[1],f);
    cout<<" x3 = "<<x3<<endl;

    Simpson integ(x1, x2);       // definisco il metodo di integrazione con intervallo simpson
    double I = integ.Integra(NSIMPSON, f);
    cout << " Integrale della funzione f(x) tra "<<x1<<" e "<<x2<<" con metodo simpson = " << I << endl;

    unsigned int y = 128;
    double I2 = integ.Integra( y, f);
    cout<<"CCCCCCCCCC :"<<I<<endl;
    cout<<"DDDDDDDDDD :"<<I2<<endl;
    prec=fabs(I-I2);

    cout<<"Precisione stimata simpson = "<<prec<<endl;


    IntegratoreMedia med(NSIMPSON);
    Randomgen rand(118);

    

    for(int i=0 ; i<punti ; i++)
    {
        x1t = rand.Unif(x1-(DELTA/2), x1+(DELTA/2));
        x2t = rand.Unif(x2-(DELTA/2), x2+(DELTA/2));

        MC1.push_back(med.Integra(f, x1t,x2t ,NSIMPSON , 0.));
    }

    double e2, mediatemp;

    mediatemp = Media(MC1);
    e2 = DeviazioneStandard(MC1, mediatemp);

    cout<<"Stima errore e2 = "<< e2 << endl;

    /////////////////////////////////////////////////////////////////////////////////////////

    double Ntemp=4, precprog;

    do
    {
        
    
    double Iprog = integ.Integra(Ntemp, f);
    cout << " Integrale della funzione f(x) tra "<<x1<<" e "<<x2<<" con metodo simpson = " << Iprog << endl;

    double Iprog2 = integ.Integra(Ntemp*2, f);

    precprog=fabs(Iprog-Iprog2);

    cout<<"Precisione stimata simpson = "<<precprog<<endl;
    cout<<"AAAAAAAAAAAAAAAA :"<<e2<<endl;
    cout<<"BBBBBBBBBBBBBBBB :"<<precprog<<endl;

    Ntemp += 2;

    } while (precprog>=e2);
    
    cout<<"stima simpson per avere incertezza >= "<<e2<<endl;
    cout<<"numero passi : "<<Ntemp-2<<endl;

////////////////////////////////////////////////////////////////////

    double t=x1;
    

    TGraph graph;
    double nstep = (fabs(x3-x1)/deltaT);
    double h=(fabs(x3-x1)/nstep);
    cout<<"STAMPO H "<<h<<endl;
    double x;

  for (int step =0 ; step < nstep; step++)
  {
    Simpson disegno(x1,t);
    x = disegno.Integra(NSIMPSON, f);
    graph.SetPoint(step, t, x);
    t = t + h;
  }

  TCanvas c("c", "Oscillatore forzato", 800, 600);
  c.SetGridx();
  c.SetGridy();
  string title = "Andamento funzione integrale";
  graph.SetTitle(title.c_str());
  graph.GetXaxis()->SetTitle("t");
  graph.GetYaxis()->SetTitle("val");
  graph.Draw("ALP");
  c.Update();
  c.SaveAs("graph.pdf");

    return 0;
}
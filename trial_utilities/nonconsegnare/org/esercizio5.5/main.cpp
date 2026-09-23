#include "funzioni.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TApplication.h"
#include <fstream>
#include "TH1F.h"

double const Pi=3.1415926535;

int main(int argc, char** argv) {

    Puntomateriale terra(5.97E27,0,0,0,0);

    double raggioT=6373E3;
    double raggioSat=raggioT+250000;
    double raggioMont=raggioT+1000;
    double massamont=1.26E13;
    double circnf=(raggioSat)*2*Pi;
    

    posizione P( 0,raggioSat, 0 );
    Campovettoriale E= terra.CampoGravitazionale(P);
    cout << "Campo gravitaz del satellite: "<< E.Modulo() << endl;

//creazione delle montagne come punti materiali

double* punti=new double[4162];
ofstream fout;
fout.open("dati.dat");
for (int y=0; y<4162; y++) {
    //definire la posizione del satellite che ruota attorno alla terra
    posizione S(raggioSat*cos(y*Pi/2080.6),raggioSat*sin(y*Pi/2080.6),0);
    Campovettoriale E= terra.CampoGravitazionale(S);
        //creazione campo vettoriale nella pos prestabilita
        for (int i=0; i<100; i++) {
            posizione posM(raggioMont*cos(i*Pi/10012),raggioMont*sin(i*Pi/10012),0);
            Puntomateriale mont(massamont, 0, posM);
            E+= mont.CampoGravitazionale(S);
                fout << mont.CampoGravitazionale(S).Modulo() << endl;
            
            
        }
        punti[y] =E.Modulo();
        
        
}

TCanvas c("Campo grav terrestre + catena montuosa ","Influenza catena montuosa su gravità terrestre");
fout.close();
c.cd();
c.SetGridx();
c.SetGridy();
TGraph g;
for (int i = 0; i < 4161; i++) {
    g.SetPoint(i, i, punti[i]);
}
g.SetTitle("Campo gravitazionale terra + catena montuosa; m^4; intensità campo gravitazionale");
g.Draw("AL");
g.GetXaxis()->SetRangeUser(-100, 6000);

c.SaveAs("graph.pdf");


delete[] punti;
return  0;
}

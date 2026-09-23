#include "Funzionebase.h"
#include "Integrali.h"
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include "TCanvas.h"
#include "TGraph.h"
#include "TApplication.h"
#include "TH1F.h"


#define GRAFICO
#define VALOREINTEGRALE 1.0

//TUTTI I METODI DI INTEGRAZIONE SONO IN QUESTO ESERCIZIO

using namespace std;

int main(int argc, char **argv)
{


    if (argc < 3)
    {
        cout << "Errore compilazione, usare: " << argv[0] << " <precisione>" << "numero di passi" << endl;
        return 2;
    }
    double prec = atof(argv[1]);  //prendo precisione
    int nstep = atoi(argv[2]);   //prendo il numero di passi


    xsinx f;   
    
    int scelta;

    do{
    cout<<"selezionare metodo di integrazione:"<<endl;
    cout<<"1) Metodo midpoint"<<endl;
    cout<<"2) Metodo simpson"<<endl;
    cout<<"3) Metodo trapezi"<<endl;
    cout<<"inserire scelta:";
    cin>>scelta;
    }while(scelta<1 || scelta>3);

    if(scelta==1)
    {
        Midpoint integ(0, M_PI / 2);       // definisco il metodo di integrazione con intervallo midpoint
        double I = integ.Integra(nstep, f);
        cout << " Integrale della funzione xsinx tra 0 e pgreco/2 con metodo midpoint = " << I << endl;
    }
    else if(scelta==2)
    {
        Simpson integ(0, M_PI / 2);       // definisco il metodo di integrazione con intervallo simpson
         double I = integ.Integra(nstep, f);
        cout << " Integrale della funzione xsinx tra 0 e pgreco/2 con metodo simpson = " << I << endl;
    }
    else if(scelta==3)
    {
    Trapezi integ(0, M_PI / 2);       // definisco il metodo di integrazione con intervallo trapezi
    double I = integ.Integra(prec, f);
    int cifsign=-log10(prec);
    cout << " precisione = "<< /*setw(10)<<*/ prec<< " Integrale della funzione xsinx tra 0 e pgreco/2 = "<<setprecision(cifsign) << I << endl;
    }

    Trapezi integT(0, M_PI / 2);       // definisco il metodo di integrazione con intervallo trapezi per il controllo dell'errore

#ifdef GRAFICO
    TGraph g_errore;
    TCanvas c(".", "errore di integrazione del metodo dei trapezi");
    c.SetGridx();
    c.SetGridy();
    g_errore.SetTitle("Errore di integrazione con il metodo dei trapezi; numero di passi; errore assoluto");

    double Iv = VALOREINTEGRALE; // valore esatto dell'integrale di x*sin(x) tra 0 e pi/2 ( lo metto io per evitare problemi di calcolo numerico)
    double Ii, err;

    for (unsigned int i = 1; i < 10000; i += 10)
    {
        Ii = integT.Integra(i, f);
        err = fabs(Ii - Iv);
        g_errore.SetPoint(g_errore.GetN(), i, err); 
    }

    g_errore.Draw("AL");
    c.SetLogx();
    c.SetLogy();
    c.Modified();
    c.Update();
    c.SaveAs("Graph.pdf");
#endif

    return 0;
}
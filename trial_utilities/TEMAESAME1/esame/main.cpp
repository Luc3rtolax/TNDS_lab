#include "Funzionebase.h"
#include "Integrali.h"
#include "IntegraleMC.h"
#include "Funzioni.h"
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include "TCanvas.h"
#include "TGraph.h"
#include "TApplication.h"
#include "TH1F.h"
#include "TF1.h"



#define GRAFICO
#define VALOREINTEGRALE ((3.0/16.0)*exp(2))
#define VALOREINTEGRALE2 1.5708

#define Einf 0
#define Esup (sqrt(exp(1)))
#define NS 512
#define P 0.0001

#define numeroStime 1000
#define NMC 16

using namespace std;

int main(int argc, char **argv)
{

    //double prec = P;  
    int nstep = NS;
    double erroreMP;


    funzTE1 f;   
    
        Midpoint integ(Einf, Esup);       // definisco il metodo di integrazione con intervallo midpoint
        double I = integ.Integra(nstep, f);
        cout << " Integrale della funzione tra 0 e sqrt(e) con metodo midpoint = " << I << endl;
        
    

    Midpoint integT(Einf, Esup);       // definisco il metodo di integrazione con intervallo trapezi per il controllo dell'errore


    TGraph g_errore, g_k;
    

    double Iv = VALOREINTEGRALE; 
    double Ii, err;

    for (unsigned int i = 2; i <= 1024; i = i*2)
    {
        Ii = integT.Integra(i, f);
        err = fabs(Ii - Iv);
        g_errore.SetPoint(g_errore.GetN(), i, err);
        g_k.SetPoint(g_k.GetN(), log((Esup-Einf)/i), log(err)); 
        cout<<i<<"  "<<Ii<<"  "<<err<<endl;

        if(i==16)
        {
            erroreMP=fabs(VALOREINTEGRALE-Ii);
        }
    }


    TCanvas c(".", "errorr di integrazione midpoint",1200,600);
    c.Divide(2,1);

    c.cd(1);
    gPad->SetGrid();
    gPad->SetLogx();
    gPad->SetLogy();

    g_errore.SetTitle("Errore di integrazione con il metodo midpoint; numero di passi; errore assoluto");
    g_errore.Draw("ALP");


    c.cd(2);
    gPad->SetGrid();

    g_k.SetTitle("log(err)=log(k1)+k2*log(h); passo integrazione; errore");
    g_k.Draw("AP");

    g_k.Fit("pol1","Q");

    TF1* retta = g_k.GetFunction("pol1");

    double intercetta = retta->GetParameter(0);
    double m = retta->GetParameter(1);

    cout<<endl<<"k1 = "<<exp(intercetta)<<endl;
    cout<<endl<<"k2 = "<<m<<endl;


    c.cd();
    c.Modified();
    c.Update();


    c.SaveAs("Midpoint.pdf");


//punto 3/4

    Midright integ2(Einf, Esup);       // definisco il metodo di integrazione con intervallo midpoint
    double I2 = integ2.Integra(nstep, f);
    cout << " Integrale della funzione tra 0 e sqrt(e) con metodo midright = " << I2 << endl;


    TGraph g_errore2, g_k2;
    

    // double Iv = VALOREINTEGRALE; 
    // double Ii, err;

    for (unsigned int i = 2; i <= 1024; i = i*2)
    {
        Ii = integ2.Integra(i, f);
        err = fabs(Ii - Iv);
        g_errore2.SetPoint(g_errore2.GetN(), i, err);
        g_k2.SetPoint(g_k2.GetN(), log((Esup-Einf)/i), log(err)); 
        cout<<i<<"  "<<Ii<<"  "<<err<<endl;
    }


    TCanvas c2(".", "error di integrazione midpoint",1200,600);
    c2.Divide(2,1);

    c2.cd(1);
    gPad->SetGrid();
    gPad->SetLogx();
    gPad->SetLogy();

    g_errore2.SetTitle("Errore di integrazione con il metodo midright; numero di passi; errore assoluto");
    g_errore2.Draw("ALP");


    c2.cd(2);
    gPad->SetGrid();

    g_k2.SetTitle("log(err)=log(k1)+k2*log(h); passo integrazione; errore");
    g_k2.Draw("AP");

    g_k2.Fit("pol1","Q");

    TF1* retta2 = g_k2.GetFunction("pol1");

    double intercetta2 = retta2->GetParameter(0);
    double m2 = retta2->GetParameter(1);

    cout<<endl<<"k1 = "<<exp(intercetta2)<<endl;
    cout<<endl<<"k2 = "<<m2<<endl;


    c2.cd();
    c2.Modified();
    c2.Update();


    c2.SaveAs("Midright.pdf");

//punto 5

    vector<double> stimemedia;
    IntegratoreMedia media(56);

    for(int i=0 ; i<numeroStime ; i++)
    {
        stimemedia.push_back(media.Integra(f, Einf, Esup, NMC, 0.));
    }

    double med = 69;

    cout<<"deviazione standard :"<<DeviazioneStandard(stimemedia,med)<<endl;
    cout<<"valore medio con montecarlo :"<<med<<endl;

    double k;
    double counter = 16;

    do
    {
        media.Integra(f, Einf, Esup, counter, 0.);
        k = media.GetErrore();
        counter = counter*1.5001  ;  //per calcolo preciso serve mettere incrementoo ++ ma ci vogliono 2 anni e mezzo
    } while (k>=erroreMP);


    cout<<"servono :"<<counter-1<<" punti per avere precisione minore o uguale a midpoint"<<endl;


//punto 7

    Midpoint dot7(0,2);

    funzTE2 last;

    double Ilast = dot7.Integra(nstep, last);
    cout << " Integrale della funzione tra 0 e 2 con metodo midpoint = " << Ilast << endl;

    TGraph g_errore3, g_k3;
    

    double Iv3 = VALOREINTEGRALE2; 
    double Ii3, err3;

    for (unsigned int i = 2; i <= 1024; i = i*2)
    {
        Ii3 = dot7.Integra(i, last);
        err3 = fabs(Ii3 - Iv3);
        g_errore3.SetPoint(g_errore3.GetN(), i, err3);
        g_k3.SetPoint(g_k3.GetN(), log((2.0)/i), log(err3)); 
        cout<<i<<"  "<<Ii3<<"  "<<err3<<endl;

        if(i==16)
        {
            erroreMP=fabs(VALOREINTEGRALE2-Ii3);
        }
    }


    TCanvas c3(".", "errorr di integrazione midpoint",1200,600);
    c3.Divide(2,1);

    c3.cd(1);
    gPad->SetGrid();
    gPad->SetLogx();
    gPad->SetLogy();

    g_errore3.SetTitle("Errore di integrazione con il metodo midpoint; numero di passi; errore assoluto");
    g_errore3.Draw("ALP");


    c3.cd(2);
    gPad->SetGrid();

    g_k3.SetTitle("log(err)=log(k1)+k2*log(h); passo integrazione; errore");
    g_k3.Draw("AP");

    g_k3.Fit("pol1","Q");

    TF1* retta3 = g_k3.GetFunction("pol1");

    double intercetta3 = retta3->GetParameter(0);
    double m3 = retta3->GetParameter(1);

    cout<<endl<<"k1 = "<<exp(intercetta3)<<endl;
    cout<<endl<<"k2 = "<<m3<<endl;


    c3.cd();
    c3.Modified();
    c3.Update();


    c3.SaveAs("Midpoint2.pdf");

    return 0;
}
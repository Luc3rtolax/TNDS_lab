#include "Funzioni.h"

// double Fmax(const Funzionebase& f, double inf, double sup, int npunti)
// {

//     double step = (sup-inf)/(npunti-1);
//     double max=0;
//     double x=0;
//     double val=0;

//     for(int i=0; i<npunti; i++)
//     {

//         x = inf + i * step;
//         val = f.Eval(x);

//         if(max < val)
//         {
//             max = val;
//         }

//     }

//     return max;
// }

vector<double> LeggiFile(const string &nomefile)
{
    vector<double> dati;
    ifstream fin(nomefile);
    double x;
    while (fin >> x)
        dati.push_back(x);
    return dati;
}

double DeviazioneStandard(const vector<double> &v, double &media)
{
    double somma = 0, somma2 = 0;
    int n = v.size();
    for (double x : v)
    {
        somma += x;
        somma2 += x * x;
    }
    media = somma / n;
    return sqrt((somma2 - n * media * media) / (n - 1));
}

TH1F *CreaIstogramma(const char *nome, const char *titolo, const vector<double> &valori)
{
    double vmin = *min_element(valori.begin(), valori.end());
    double vmax = *max_element(valori.begin(), valori.end());
    double margine = 0.1 * (vmax - vmin);

    TH1F *h = new TH1F(nome, titolo, NBIN, vmin - margine, vmax + margine);
    for (double x : valori)
        h->Fill(x);

    return h;
}

TH2F *CreaIstogramma2D(const char *nome, const char *titolo, const vector<double> &valoriX, const vector<double> &valoriY)
{
    double xmin = *min_element(valoriX.begin(), valoriX.end());
    double xmax = *max_element(valoriX.begin(), valoriX.end());
    double ymin = *min_element(valoriY.begin(), valoriY.end());
    double ymax = *max_element(valoriY.begin(), valoriY.end());

    double margineX = 0.1 * (xmax - xmin);
    double margineY = 0.1 * (ymax - ymin);

    TH2F *h = new TH2F(nome, titolo,
                       NBIN, xmin - margineX, xmax + margineX,
                       NBIN, ymin - margineY, ymax + margineY);

    for (size_t i = 0; i < valoriX.size(); i++)
        h->Fill(valoriX[i], valoriY[i]);

    return h;
}
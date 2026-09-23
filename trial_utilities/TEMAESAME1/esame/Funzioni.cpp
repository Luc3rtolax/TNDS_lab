#include "Funzioni.h"

double Fmax(const Funzionebase& f, double inf, double sup, int npunti)
{

    double step = (sup-inf)/(npunti-1);
    double max=0;
    double x=0;
    double val=0;

    for(int i=0; i<npunti; i++)
    {

        x = inf + i * step;
        val = f.Eval(x);

        if(max < val)
        {
            max = val;
        }

    }

    return max;
}

vector<double> LeggiFile(const string& nomefile)
{
    vector<double> dati;
    ifstream fin(nomefile);
    double x;
    while (fin >> x) dati.push_back(x);  
    return dati;
}

double DeviazioneStandard(const vector<double>& v, double& media)
{
    double somma = 0, somma2 = 0;
    int n = v.size();
    for (double x : v) { somma += x; somma2 += x*x; }
    media = somma / n;
    return sqrt((somma2 - n*media*media) / (n - 1));
}

double Media(const vector<double>& v)
{
    double somma=0;
    int n=v.size();

    for(unsigned int i=0; i<v.size(); i++)
    {
        somma += v[i];
    }

    return (somma/n);
}

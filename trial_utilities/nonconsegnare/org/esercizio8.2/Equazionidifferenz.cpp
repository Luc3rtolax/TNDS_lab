#include "Equazionidifferenz.h"

vector<double> Oscillatorearmonico:: Eval(double t, const vector<double> &a) const{



    vector<double> dxdt {a[1], -m_omega0*m_omega0*a[0]};
    return dxdt;
};

vector<double> Eulero:: Passo(double t, const vector<double>& x, double h, const Funzionevettbase &f)const{
    vector<double> ris(x.size());
   ris=x +h*f.Eval(t, x);
   return ris;

};

string convert ( double h ) {

  int cifre_significative = -log10(h);
  ostringstream streamObj3;
  streamObj3 << fixed;
  streamObj3 << setprecision(cifre_significative);
  streamObj3 << h;
  string strObj3 = streamObj3.str();
  return strObj3;

} ;

vector<double> RangeKutta:: Passo(double t, const vector<double>& x, double h, const Funzionevettbase &f)const{
vector<double> ris(x.size());
//quarto passo
double hmezzi=h/2;
vector<double> k1= f.Eval(t,x);
vector<double> k2=x+(k1*hmezzi);
                k2=f.Eval(t,k2);
vector<double> k3=x+(k2*hmezzi);
                k3=f.Eval(t,k3);
vector<double> k4=x+(h*k3);
                k4=f.Eval(t,k4);

return x+(k1+k2*2. +k3*2. +k4)*(h/6.);




};


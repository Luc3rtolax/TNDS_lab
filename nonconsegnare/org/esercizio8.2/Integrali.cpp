
#include "Integrali.h"

double Midpoint:: Integra(unsigned int nstep, const Funzionebase& f) {
    if (nstep <=0) {cout << "Errore, numero di passi e' negativo"<< endl; exit (33);};
    m_nstep=nstep;
    m_h=(m_b-m_a)/m_nstep;

    m_sum=0;
    for (unsigned int i=0; i<m_nstep; i++) {
        m_sum += f.Eval(m_a + (i+0.5)*m_h);
    }
    m_integral = m_sign*m_sum*m_h;
    return m_integral;
};

double Simpson:: Integra(unsigned int nstep, const Funzionebase& f){
    if (nstep <=0) {cout << "Errore, numero di passi e' negativo"<< endl; exit (33);};
    if (nstep%2!=0) {cout<< "Passi devono essere pari"<< endl; exit (67);};
    m_nstep=nstep;
    double steps=m_nstep;
    m_h=(m_b-m_a)/steps;
    m_sum=0;
    double dispari = 0.;
    double pari = 0.;
 

  for (unsigned int i=1; i<m_nstep; i++) {
        if (i%2==0)
            pari += 2.*f.Eval(m_a+i*m_h);
        else
            dispari += 4.*f.Eval(m_a+i*m_h);
    }



    double I, l;
    I=f.Eval(m_a)+ dispari + pari +f.Eval(m_b);
    l=m_h/3.;
    m_integral=l*I;
    return m_integral;
};

double Trapezi:: Integra (unsigned int nstep, const Funzionebase& f) {
    if (nstep <=0) {cout << "Errore, numero di passi e' negativo"<< endl; exit (33);};
    m_nstep=nstep;
    m_h=(m_b-m_a) / m_nstep;

    m_sum=0;
 

  for (unsigned int i=1; i<m_nstep; i++) {
    m_sum += f.Eval(m_a+i*m_h);
  }



    double I,a,b;
    a=f.Eval(m_a)/2;
    b=f.Eval(m_b)/2;


    I=a+m_sum+b;
    m_integral=m_h*I;
    return m_integral;
  
};

double Trapezi:: Integra(double prec, const Funzionebase& f  ) {
    if ((prec <= 0)||(prec>=1)) {cout << "La precisione deve essere un valore positivo,diverso da zero e minore di 1" << endl; exit(3);}

    double pr=prec+1;
    double I, Idue;
    unsigned int steps=1;

    while (pr>prec) {
        
        Idue=Integra(steps*2,f);
        I=Integra(steps,f);
        double F=Idue-I;
        pr=1.33333333333333333333333333333333333*fabs(F);
        steps++;
    }

    cout << "Passi " << steps<< endl;
    double m=Integra(steps, f);
    return m;
    

};

double Trapezi:: IntegraM(double prec, const Funzionebase& f){
    if ((prec <= 0)||(prec>=1)) {cout << "La precisione deve essere un valore positivo,diverso da zero e minore di 1" << endl; exit(3);}

    double precis=prec+1;
    double sigma=(f.Eval(m_b)-f.Eval(m_a))/2;
    double intervallo=(m_b-m_a);
    double I;
    double Idue=sigma*intervallo;
   
    int i=1;

    while (precis>prec) {
        I=Idue;

        for (double y=1; y<pow(2,i); y+=2) {
            sigma += f.Eval(m_a+(intervallo*(y/pow(2,i))));
        
        }
        Idue=sigma*intervallo/pow(2, i);
        double F=Idue-I;

        precis=1.33333333333333333333333333333333333*fabs(F);
      
        
        
        i++;
    }

    cout << "passi: "<< pow(2, i);
    m_integral=I;
    return I;

};

double Trapezi:: Integra(double h, vector<double>& v, const Funzionevettbase& f, const Equazionedifferenzbase& e){
    int N=static_cast<int>((m_b-m_a)/h);
    double sum;
    double t=m_a;
    sum=v[0]*0.5;
    for (int i=0; i< N-1; i++) {
       v= e.Passo(t,v,h,f);
       sum += v[0];
       t+=h;
    }
    v=e.Passo(t,v ,h,f);
    sum+= v[0]*0.5;
    m_integral=sum*h;
    return m_integral;
};

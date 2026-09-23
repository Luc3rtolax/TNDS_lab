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
    I=f.Eval(m_a)+dispari+pari+f.Eval(m_b);
    l=m_h/3.;
    m_integral=l*I;
    return m_integral;
};

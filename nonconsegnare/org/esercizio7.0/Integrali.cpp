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
}

#ifndef ESPERIMENTOPRISMA
#define ESPERIMENTOPRISMA

#include "Randomgen.h"
#include <math.h>

class EsperimentoPrisma
{

public:
    EsperimentoPrisma(unsigned int seed);
    ~EsperimentoPrisma() { ; };

    void Esegui();
    void Analizza();

    double getAinp() {return m_A_input; };
    double getAmis() { return m_A_misurato; };

    double getBinp() {return m_B_input; };
    double getBmis() { return m_B_misurato; };

    double getn1inp() {return m_n1_input; };
    double getn1mis() { return m_n1_misurato; };

    double getn2inp() {return m_n2_input; };
    double getn2mis() { return m_n2_misurato; };

    double getdm1inp() {return m_dm1_input; };
    double getdm1mis() { return m_dm1_misurato; };

    double getdm2inp() {return m_dm2_input; };
    double getdm2mis() { return m_dm2_misurato; };

    double getth0inp() {return m_th0_input; };
    double getth0mis() { return m_th0_misurato; };

    double getth1inp() {return m_th1_input; };
    double getth1mis() { return m_th1_misurato; };
    
    double getth2inp() {return m_th2_input; };
    double getth2mis() { return m_th2_misurato; };

    

private:
    // generatore di numeri casuali

    Randomgen m_rgen;

    // parametri dell'apparato sperimentale

    double m_lambda1, m_lambda2, m_alpha, m_sigmat;

    // valori delle quantita' misurabili :
    // input    : valori assunti come ipotesi nella simulazione
    // misurato : valore dopo la simulazione di misura

    double m_A_input, m_A_misurato;
    double m_B_input, m_B_misurato;
    double m_n1_input, m_n1_misurato;
    double m_n2_input, m_n2_misurato;
    double m_dm1_input, m_dm1_misurato;
    double m_dm2_input, m_dm2_misurato;
    double m_th0_input, m_th0_misurato;
    double m_th1_input, m_th1_misurato;
    double m_th2_input, m_th2_misurato;
};

#endif
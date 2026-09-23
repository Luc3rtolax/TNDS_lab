#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>

#include "Funzionebase.h"
#include "Funzioni.h"
#include "IntegraleMC.h"

#define MAX (M_PI / 2.0)
#define MIN 0.0

using namespace std;

int main()
{
    vector<int> valoriN {100, 500, 1000, 5000, 10000, 50000, 100000};
    const int numeroStime = 10000;

    xsinx f;

    double fmax = Fmax(f, MIN, MAX, 100000);
    cout << "Massimo stimato: " << fmax << endl;

    IntegratoreMedia media(20);
    IntegratoreHitMiss hitmiss(20);

    for (int punti : valoriN) {

        ofstream fileMedia("media_" + to_string(punti) + ".txt");
        ofstream fileHitMiss("hitmiss_" + to_string(punti) + ".txt");

        for (int i = 0; i < numeroStime; i++) {
            fileMedia   << media.Integra(f, MIN, MAX, punti, fmax)   << "\n";
            fileHitMiss << hitmiss.Integra(f, MIN, MAX, punti, fmax) << "\n";
        }

        cout << "N = " << punti << " completato." << endl;
    }

    return 0;
}
#ifndef FUNZIONI_H
#define FUNZIONI_H

#include "Funzionebase.h"
#include <vector>
#include <fstream>

double Fmax(const Funzionebase& f, double inf, double sup, int npunti);
vector<double> LeggiFile(const string& nomefile);
double DeviazioneStandard(const vector<double>& v, double& media);

#endif
#ifndef FUNZIONI_H
#define FUNZIONI_H


#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2.h"
#include "TGraph.h"
#include "TLegend.h"
 
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

const int NBIN=50;

//#include "Funzionebase.h"

//double Fmax(const Funzionebase& f, double inf, double sup, int npunti);
vector<double> LeggiFile(const string& nomefile);
double DeviazioneStandard(const vector<double>& v, double& media);
TH1F* CreaIstogramma(const char* nome, const char* titolo, const vector<double>& valori);
TH2F* CreaIstogramma2D(const char *nome, const char *titolo, const vector<double> &valoriX, const vector<double> &valoriY);

#endif
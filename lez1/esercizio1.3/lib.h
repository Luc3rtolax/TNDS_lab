#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

double contarighe (const char* );
double* carica_dati(const char* );
double media_dati (double* , double );
double varianza (double* , double );
void swap_double (double& , double& );
double* ordine_cr (double* , double );
double mediana (double* , double );
void print (double* , int,double , double , double );
void print (double* , int ,double , double , double, const char* f ); 

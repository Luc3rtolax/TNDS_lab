#include "Solutore.h"
#include <iomanip>
double const Pi= 3.14159;
int main() {
    double precision=1E-7;
    int cifre= -log10(precision);
    Tangente T;
    Bisezione B;
    for (int i=1; i<21; i++) {
        cout << setprecision(cifre)<< B.Cercazerireference(i*Pi,i*Pi+Pi/2, T) << endl;
    }










    return 0;
}
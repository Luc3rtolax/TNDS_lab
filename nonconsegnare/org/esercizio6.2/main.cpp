#include "Solutore.h"

int main() {
    double a,b;
    cout << "Estremo inferiore:" ;
    cin>> a;
    cout << "Estremo superiore" ;
    cin >> b;
    Parabola P(3,5,-2);
    Bisezione B;
    cout << B.Cercazerireference(a,b, P) << endl;
    return 0;
}
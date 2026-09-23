#include "Funzionebase.h"

int Parabola:: sign(double x) const {
    if (Eval(x)<=0) {
        if (Eval(x)==0) {
            return 0;
        } else {
            return -1;
        }
    } else {return 1;}
}
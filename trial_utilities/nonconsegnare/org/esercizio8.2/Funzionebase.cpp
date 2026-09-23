#include "Funzionebase.h"

float sign (double x) {
    if (x==0) {
        return 0;
    } else {
        if(x<0) {
            return -1;
        } else {
            return 1;
        }
    }
}

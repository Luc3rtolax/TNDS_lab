#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "TApplication.h"
#include "TGraph.h"
#include "TAxis.h"
#include "posizioni.h"
#include "TCanvas.h"

using namespace std;

vector<posizione> readfile (const char* );
void sort_by_closest (vector<posizione>& );
//void sort2 (vector<posizione>&);



vector<posizione> readfile (const char* f) {
    ifstream fin;
    fin.open(f);
    vector<posizione> V;
    int i=0;
    double x=0,y=0,z=0;

    while (fin >> x >> y >> z) {
    posizione p(x,y,z);
    V.push_back(p);
    }
    
    fin.close();
    return V;
} ;

// vector<posizione> readfile (const char* f) {
//     ifstream fin;
//     fin.open(f);
//     vector<posizione> V;
//     int i=0;
//     while (fin) {
//         double x,y,z;
//         fin >> x >> y >> z;
//         posizione p(x,y,z);
//         V.push_back(p);
//         i++;
//     }
//     fin.close();
//     return V;
// } ;

void sort_by_closest (vector<posizione>& V) {

    posizione ref(0,0,0);

    for (auto it = V.begin(); it !=V.end(); it++ ) {
     sort (it, V.end(), comp_functor(ref));
        ref=*it;
    }
};

/*void sort2 (vector<posizione>& V) {
    posizione ref(0,0,0);
    auto it=V.begin();
    vector<posizione> P;
   while(!V.null()) {
        

        posizione meno=V.min_element(it, V.end(), comp_functor(ref));

        P.push_back(meno);
        V.
    it++
    }
}*/



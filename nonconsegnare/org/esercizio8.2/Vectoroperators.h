#ifndef FUNZIONIVETT__
#define FUNZIONIVETT__

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

template <typename T> inline vector<T> operator +(const vector<T> &a, const vector <T> &b) {
    if (a.size()!=b.size()) {
        cout << "Vettori hannp dimensione diversa"<< endl;
        throw (11);
    }
    vector<T> res(a.size());

    transform(a.begin(), a.end(), b.begin(), res.begin(), plus<T>());
    return res;
};

template <typename T> inline T operator *(const vector<T> &a, const vector <T> &b) {
    if (a.size()!=b.size()) {
        cout << "Vettori hanno dimensione diversa"<< endl;
        throw (13);
    }
    T sum=0;
    sum=inner_product(a.begin(),a.end(), b.begin(), 1.);
    return sum;
};

template <typename T> inline vector<T> operator *(T c, const vector<T> &a) {
    vector<T> res(a.size());

    transform(a.begin(), a.end(), res.begin(), [&c](T x){return x* c;});
    return res;
};
template <typename T> inline vector<T> operator *( const vector<T> &a,T c) {
    vector<T> res(a.size());

    transform(a.begin(), a.end(), res.begin(), [&c](T x){return x* c;});
    return res;
};



#endif
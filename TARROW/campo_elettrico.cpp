// campo_elettrico.cpp
//
// Disegna il campo elettrico di due cariche puntiformi come campo
// vettoriale su una griglia: una freccia per ogni nodo, orientata come
// E_hat(x,y) nel nodo. La LUNGHEZZA della freccia e' proporzionale a
// log(|E|), rimappato nell'intervallo [LMIN,LMAX] trovato sui valori
// min/max di |E| effettivamente presenti in griglia (scala log perche'
// il modulo di E varia di ordini di grandezza vicino alle cariche).
//
// Compilazione:
//   g++ -std=c++17 campo_elettrico.cpp -o campo_elettrico `root-config --cflags --libs`
// oppure:
//   make

#include <TROOT.h>
#include <TCanvas.h>
#include <TH2F.h>
#include <TArrow.h>
#include <TMarker.h>
#include <TLatex.h>
#include <TStyle.h>

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Carica {
    double q, x, y;
};

const double k = 1.0;        // costante di scala: non cambia le direzioni
const double LIM = 1.0;      // dominio di disegno: [-LIM,LIM] x [-LIM,LIM]
const double D = 0.5;       // semidistanza tra le due cariche (disposte sull'asse y)
const int NGRID = 23;        // punti di griglia per lato (dispari: include il centro)
const double RMIN = 0.1;    // raggio di esclusione attorno a ciascuna carica
const double LMIN = 0.02;    // lunghezza minima di una freccia (campo piu' debole in griglia)
const double LMAX = 0.09;    // lunghezza massima di una freccia (campo piu' forte in griglia)


void CampoElettrico(double x, double y, const Carica &c1, const Carica &c2,
                     double &Ex, double &Ey) {
    double dx1 = x - c1.x, dy1 = y - c1.y;
    double r1 = sqrt(dx1*dx1 + dy1*dy1);
    double dx2 = x - c2.x, dy2 = y - c2.y;
    double r2 = sqrt(dx2*dx2 + dy2*dy2);

    Ex = 0.0; Ey = 0.0;
    if (r1 > 1e-12) { double r1_3 = r1*r1*r1; Ex += k*c1.q*dx1/r1_3; Ey += k*c1.q*dy1/r1_3; }
    if (r2 > 1e-12) { double r2_3 = r2*r2*r2; Ex += k*c2.q*dx2/r2_3; Ey += k*c2.q*dy2/r2_3; }
}

// ---------------------------------------------------------------------
// Dati di un nodo di griglia dove il campo e' definito e non nullo
// ---------------------------------------------------------------------
struct PuntoGriglia {
    double x, y;    // posizione del nodo
    double Ex, Ey;  // componenti del campo
    double E;       // modulo del campo
};

// ---------------------------------------------------------------------
// Disegna il marcatore di una carica: cerchietto colorato + segno
// ---------------------------------------------------------------------
void DisegnaCarica(const Carica &c) {
    int colore = (c.q >= 0) ? kRed+1 : kBlue+1;

    TMarker *m = new TMarker(c.x, c.y, 24); // cerchio aperto
    m->SetMarkerColor(colore);
    m->SetMarkerSize(2.2);
    m->Draw();

    TLatex *lab = new TLatex(c.x, c.y, c.q >= 0 ? "+" : "#minus");
    lab->SetTextAlign(22); // centrato orizzontalmente e verticalmente
    lab->SetTextColor(colore);
    lab->SetTextSize(0.03);
    lab->Draw();
}

// ---------------------------------------------------------------------
int main() {
    gROOT->SetBatch(kTRUE); // nessuna finestra grafica: salva direttamente su file
    gStyle->SetOptStat(0);

    double q1, q2, x1, x2, y1, y2;
    cout << "Valore della prima carica  q1 (con segno): ";
    cin >> q1;
    cout << "Ascissa prima carica  x1 (con segno): ";
    cin >> x1;
    cout << "Ordinata prima carica y1 (con segno): ";
    cin >> y1;
    cout << "Valore della prima carica  q2 (con segno): ";
    cin >> q2;
    cout << "Ascissa prima carica  x2 (con segno): ";
    cin >> x2;
    cout << "Ordinata prima carica y2 (con segno): ";
    cin >> y2;
    

    Carica c1{q1, x1, y1};
    Carica c2{q2, x2, y2};

    TCanvas *c = new TCanvas("c", "Campo due cariche puntiformi", 800, 800);

    // Frame vuoto per fissare assi/titolo prima di disegnare le frecce
    // (evita il problema di disegnare su un grafico non ancora popolato)
    TH2F *frame = new TH2F("frame", "Campo due cariche puntiformi;x [u.a.];y [u.a.]",
                            100, -LIM, LIM, 100, -LIM, LIM);
    frame->Draw();

    // --- Prima passata: calcolo il campo su tutta la griglia e trovo Emin, Emax ---
    vector<PuntoGriglia> punti;
    double Emin = 1e300, Emax = 0.0;

    for (int i = 0; i < NGRID; i++) {
        double x = -LIM + 2.0*LIM*i/(NGRID-1);
        for (int j = 0; j < NGRID; j++) {
            double y = -LIM + 2.0*LIM*j/(NGRID-1);

            double r1 = hypot(x - c1.x, y - c1.y);
            double r2 = hypot(x - c2.x, y - c2.y);
            if (r1 < RMIN || r2 < RMIN) continue; // troppo vicino a una carica

            double Ex, Ey;
            CampoElettrico(x, y, c1, c2, Ex, Ey);
            double E = hypot(Ex, Ey);
            if (E < 1e-9) continue; // punto di campo nullo (es. cariche uguali e opposte simmetriche)

            punti.push_back({x, y, Ex, Ey, E});
            Emin = min(Emin, E);
            Emax = max(Emax, E);
        }
    }

    // --- Seconda passata: mappo log(E) in [LMIN,LMAX] e disegno le frecce ---
    double logEmin = log10(Emin);
    double logEmax = log10(Emax);
    double deltaLog = logEmax - logEmin; // se le cariche sono uguali E e' quasi costante: deltaLog~0

    for (const auto &p : punti) {
        double t = (deltaLog > 1e-12) ? (log10(p.E) - logEmin)/deltaLog : 1.0;
        t = min(max(t, 0.0), 1.0); // clamp di sicurezza
        double L = LMIN + (LMAX - LMIN)*t;

        double dirx = p.Ex/p.E, diry = p.Ey/p.E;
        double x2 = p.x + L*dirx;
        double y2 = p.y + L*diry;

        TArrow *fr = new TArrow(p.x, p.y, x2, y2, 0.006, "|>");
        fr->SetLineColor(kBlack);
        fr->SetFillColor(kBlack);
        fr->SetLineWidth(1);
        fr->Draw();
    }

    DisegnaCarica(c1);
    DisegnaCarica(c2);

    c->Modified();
    c->Update();
    c->SaveAs("campo_elettrico.png");
    c->SaveAs("campo_elettrico.pdf");

    cout << "Fatto. Immagini salvate: campo_elettrico.png, campo_elettrico.pdf" << endl;
    return 0;
}
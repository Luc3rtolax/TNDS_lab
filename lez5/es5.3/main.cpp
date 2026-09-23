#include "Puntomateriale.h"

#include <cstdlib>
#include <cmath>
#include <iostream>
#include "TCanvas.h"
#include "TGraph.h"
#include "TApplication.h"
#include "TH1F.h"
// #define singolopunto
// #define tantipunti

using namespace std;

int main(int argc, char **argv)
{

    Elettrone e;
    Protone p;
    const double d = 1.E-10;

    Puntomateriale elettrone(e.GetMassa(), e.GetCarica(), 0., 0., d / 2.);
    Puntomateriale protone(p.GetMassa(), p.GetCarica(), 0., 0., -d / 2.);

    int scelta;
    cout << "1) Campo elettrico in un punto" << endl;
    cout << "2) Campo elettrico lungo l'asse z" << endl;
    cout << "Inserire scelta: ";
    cin >> scelta;

    switch (scelta)
    {
    case 1:
    {

        double x, y, z;

        cout << "Inserire coordinate: " << endl;
        while (true)
        {
            cout << "x: ";
            cin >> x;
            cout << "y: ";
            cin >> y;
            cout << "z: ";
            cin >> z;

            if (cin.fail())
            {
                cerr << "Input non valido. Riprova." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }

        posizione P(x, y, z);
        Campovettoriale E = elettrone.CampoElettrico(P) + protone.CampoElettrico(P);

        cout << "E=(" << E.GetFx() << "," << E.GetFy() << "," << E.GetFz() << ")" << endl;

        break;
    }
    case 2:
    {

        double *graph = new double[901];
        int y = 0;
        for (int i = 100; i < 1001; i++)
        {
            posizione s(0., 0., i * d);
            Campovettoriale V = elettrone.CampoElettrico(s) + protone.CampoElettrico(s);
            graph[y] = V.Modulo();
            cout << i << ") " << graph[y] << endl;
            y++;
        };

        TCanvas c("Campo elettrico ", "Campo elettrico dipolo");

        c.cd();
        c.SetGridx();
        c.SetGridy();
        TGraph g(y);
        for (int i = 0; i < y; i++)
        {
            g.SetPoint(i, 100 + i, graph[i]);
        }
        g.SetTitle("Campo elettrico dipolo; distanza (m^-10); |E|");
        g.Draw("AL");

        double a;
        a = (log(graph[1] / graph[100])) / (log(101. / 200.));
        cout << "asintotico a alfa^" << a << endl;

        c.SaveAs("graph.pdf");

        break;
    }
    default:
        cerr << "Scelta non valida" << endl;
        exit(-1);
    }

    return 0;
}

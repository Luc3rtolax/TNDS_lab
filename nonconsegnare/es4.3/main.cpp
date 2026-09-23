#include "funzioni.h
#define GRAPH

int main (int argc, char** argv) {

    if (argc <2) {
        cout << "Dati inseriti non correttamente, inserire "<<argv[0]<< " <nomefiledati> "<< endl;
    }

    vector<posizione> P= readfile(argv[1]);
cout << "dati letti: "<< endl;
   for (auto it=P.begin(); it!=P.end(); it++) it->printPositions(); 

   sort (P.begin(), P.end());
    cout << "sort normale" << endl;
    for (auto it=P.begin(); it!=P.end(); it++) it->printPositions(); 


   sort(P.begin(), P.end(), [&] (posizione i , posizione j ) { return i.getDistance() < j.getDistance() ;});
cout << "dati forse riordinati con comp lambda"<< endl << endl;

     for (auto it=P.begin(); it!=P.end(); it++) it->printPositions(); 

    sort_by_closest (P);


    cout << "riordinate con comp_functor " << P.size()<< endl<< endl;

for (auto it=P.begin(); it!=P.end(); it++) it->printPositions(); 


     TGraph mygraph;
   //#ifndef GRAPH
  mygraph.SetPoint(0, 0,0  );
  int counter = 1;
  for ( auto it = P.begin() ; it != P.end() ; it++ ) {    
    mygraph.SetPoint(counter, (*it).GetX(), (*it).GetY() );
    counter++;
  }

  mygraph.GetXaxis()->SetLimits(-10,10);
  mygraph.SetMinimum(-10);
  mygraph.SetMaximum(10);
  mygraph.GetXaxis()->SetTitle("X");
  mygraph.GetYaxis()->SetTitle("Y");
  mygraph.SetTitle("Percorso");
  mygraph.SetMarkerStyle(21);
  mygraph.SetMarkerSize(1);
  mygraph.SetLineColor(6);
  mygraph.Draw("ALP");
  mygraph.SaveAs("graf.pdf");


//#endif


cout << endl << endl;


    return 0;
}
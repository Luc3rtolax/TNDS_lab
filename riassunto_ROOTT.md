# Riassunto ROOT — Classi e Funzioni Principali

## 1. TCanvas — la "finestra" di disegno
```cpp
TCanvas *c1 = new TCanvas("c1", "titolo", 800, 600);
c1->Divide(2,2);      // divide in griglia (2 colonne x 2 righe)
c1->cd(1);            // seleziona il pad 1 (INDICIZZAZIONE DA 1, non da 0!)
// ... disegna qualcosa ...
c1->cd(2);
// ... disegna altro ...
c1->SaveAs("output.pdf");
```
**Ordine corretto:** `Divide()` → `cd(i)` → disegna nel pad i → `cd(i+1)` → ecc.

## 2. TGraph / TGraphErrors — grafici punto-punto
```cpp
TGraph *g = new TGraph(n, x, y);          // array di double, stessa lunghezza
TGraphErrors *ge = new TGraphErrors(n, x, y, ex, ey); // con errori su x e y

g->SetTitle("Titolo;Asse X;Asse Y");      // titolo;titoloX;titoloY (con ;)
g->SetMarkerStyle(20);
g->SetMarkerColor(kBlue);
g->GetXaxis()->SetTitle("x [unità]");     // alternativa a SetTitle
g->Draw("AP");                            // A=assi, P=punti, L=linea, "APL" combina
```
**Opzioni Draw comuni:** `"A"` disegna gli assi (necessario la prima volta), `"P"` punti, `"L"` linea, `"C"` curva liscia, `"same"` sovrappone senza nuovi assi.

## 3. Scale logaritmiche — ⚠️ BUG RICORRENTE
```cpp
c1->SetLogx();   // o SetLogy()
g->Draw("AP");   // ATTENZIONE: SetLogx/y va chiamato PRIMA di Draw()!
```
Se lo chiami dopo `Draw()`, il grafico non si aggiorna correttamente.

## 4. TH1F / TH2F — istogrammi
```cpp
#include "TH1.h"
#include "TH2.h"    // serve un include SEPARATO per TH2F, non basta TH1.h

TH1F *h1 = new TH1F("h1", "titolo;X;conteggi", nbin, xmin, xmax);
h1->Fill(valore);
h1->Draw();

TH2F *h2 = new TH2F("h2", "titolo", nbinx, xmin, xmax, nbiny, ymin, ymax);
h2->Fill(x, y);
h2->Draw("COLZ");   // COLZ = mappa colori con scala laterale
```

## 5. TF1 — funzioni matematiche/di fit
```cpp
TF1 *f1 = new TF1("f1", "[0]*x + [1]", xmin, xmax);  // parametri [0],[1],...
f1->SetParameters(a0, a1);
f1->Draw();
f1->Draw("same");     // per sovrapporre a un grafico già disegnato

// Fit di un grafico/istogramma:
g->Fit(f1, "Q");       // "Q" = quiet (poco output), "R" = usa range di f1
double a = f1->GetParameter(0);
double erra = f1->GetParError(0);
double chi2 = f1->GetChisquare();
```

## 6. TRandom3 — numeri casuali (Monte Carlo)
```cpp
TRandom3 *rand = new TRandom3(seed);   // seed=0 → seme basato sul tempo
double u = rand->Uniform(min, max);
double x = rand->Gaus(media, sigma);
```
**⚠️ BUG RICORRENTE:** l'oggetto `TRandom3` va creato **una sola volta fuori dal ciclo**, mai dentro il loop (altrimenti con seed fisso generi sempre la stessa sequenza/stesso numero).

## 7. TGaxis — assi personalizzati (uso avanzato)
Usato per disegnare un asse aggiuntivo (es. secondo asse Y con scala diversa) quando i grafici sovrapposti hanno range diversi.

## 8. Errori Monte Carlo — formula
```
errore = sigma / sqrt(N)
```
L'errore **diminuisce** con radice di N — se nel codice l'errore cresce con N, c'è un bug (es. moltiplichi invece di dividere).

## 9. Checklist bug classici (dalla tua esperienza)
| Bug | Fix |
|---|---|
| `SetLogx()`/`SetLogy()` dopo `Draw()` | Chiamarli PRIMA di `Draw()` |
| `#define ALPHA 1/30` → vale 0 | Usare `(1.0/30.0)` |
| `(3/16)` in una costante → vale 0 | Usare `(3.0/16.0)` |
| Ciclo `i++` su range enorme | Usare stepping moltiplicativo `i*=2` se serve |
| Errore MC che cresce con N | Dividi per `sqrt(N)`, non moltiplicare |
| `TH2F` "non dichiarato" | Serve `#include "TH2.h"` oltre a `TH1.h` |
| `while(fin) { fin >> a; }` | Usare `while(fin >> a)` (evita elemento fantasma) |
| `TRandom3` dentro il loop | Costruirlo una volta sola fuori dal loop |
| Linker error "undefined reference" | Controllare `const` uguale in `.h` e `.cpp` |

## 10. Fit() in dettaglio — su TGraph e su TH1F

`Fit()` funziona allo stesso modo sia su un `TGraph`/`TGraphErrors` che su un `TH1F`: prende una `TF1` e trova i parametri che minimizzano il chi2 (o la likelihood).

```cpp
// Su un grafico
g->Fit(f1, "Q");      // fit e basta

// Su un istogramma
h1->Fit(f1, "Q");      // stessa sintassi identica
```

**Opzioni principali della stringa (si possono combinare, es. "QR"):**
| Opzione | Significato |
|---|---|
| `""` (vuota) | Fit normale, stampa tutto il risultato in console |
| `"Q"` | Quiet: non stampa il risultato |
| `"V"` | Verbose: stampa tutti i dettagli (opposto di Q) |
| `"R"` | Usa il Range definito nel costruttore della TF1, non tutto l'asse |
| `"N"` | Non disegna la funzione fittata sul grafico/istogramma |
| `"S"` | Ritorna un `TFitResultPtr` (utile per accedere a matrice di covarianza ecc.) |
| `"+"` | Aggiunge la funzione alla lista esistente invece di sovrascriverla |
| `"M"` | Cerca di migliorare il fit con più tentativi (minimizzazione più robusta) |

**Dopo il fit, estrai i risultati da `f1` (non da `g` o `h1`):**
```cpp
double par0   = f1->GetParameter(0);
double err0   = f1->GetParError(0);
double chi2   = f1->GetChisquare();
int    ndf    = f1->GetNDF();
double chi2ndf = chi2 / ndf;          // vicino a 1 = fit buono
```

**Differenza concettuale grafico vs istogramma:**
- Su un `TGraphErrors`, il fit pesa i punti con gli errori che tu hai passato esplicitamente (`ey[i]`).
- Su un `TH1F`, il fit pesa ogni bin con l'errore statistico del bin (di default `sqrt(contenuto_bin)`, cioè Poisson), a meno che tu non l'abbia modificato a mano (vedi punto 11).

## 11. Deviazioni standard / errori sugli istogrammi

Ci sono **due concetti diversi** che si confondono facilmente:

**A) La deviazione standard (RMS) della distribuzione nell'istogramma**
```cpp
double stddev = h1->GetStdDev();   // deviazione standard della distribuzione
double mean   = h1->GetMean();
double errmean = h1->GetMeanError(); // errore sulla media
```
Questo è un numero solo, calcolato sui dati che hai riempito con `Fill()`.

**B) L'errore su ogni singolo bin (barre di errore nel disegno)**
Di default, se non fai nulla, ROOT NON calcola errori sensati sui bin (mostra `sqrt(N)` solo se attivi `Sumw2()`):
```cpp
h1->Sumw2();          // va chiamato PRIMA di riempire l'istogramma (Fill)
// ... poi fai i Fill() ...
h1->Draw("E");         // "E" disegna le barre di errore verticali sui bin
h1->Draw("E1");        // stile con "cappucci" sulle barre di errore
```
`Sumw2()` fa sì che ROOT tenga traccia correttamente della somma dei pesi al quadrato, così l'errore su ogni bin è `sqrt(contenuto)` gestito in modo consistente (fondamentale se sommi/dividi istogrammi dopo).

**Se vuoi impostare tu a mano l'errore di un bin specifico:**
```cpp
h1->SetBinError(i, valore_errore);   // i = indice del bin (1-based, non 0!)
double e = h1->GetBinError(i);       // per leggerlo
```

**Riassunto pratico:**
| Vuoi... | Usa |
|---|---|
| La deviazione standard di tutta la distribuzione | `GetStdDev()` |
| Le barre d'errore disegnate sui bin | `Sumw2()` + `Draw("E")` |
| Impostare/leggere l'errore di un bin preciso | `SetBinError(i, ...)` / `GetBinError(i)` |

## 12. Salvare output
```cpp
c1->SaveAs("nome.pdf");   // grafico
c1->SaveAs("nome.root");  // oggetti ROOT (per riaprire dopo)
```

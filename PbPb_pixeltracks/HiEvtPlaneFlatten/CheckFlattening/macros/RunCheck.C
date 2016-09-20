#include "TFile.h"
#include "TTree.h"
#include "TList.h"
#include "TCanvas.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TMath.h"
#include "TLatex.h"
#include "TDirectory.h"
#include <iostream>
#include <unistd.h>
#include <complex>
#include <cmath>

#include "HiEvtPlaneList.h"

using namespace hi;

static const int ncentbins = 5;
static const double centBins[]={0,20,40,60,80,100};
static const int NumRunBins = 8;
static const double runBins[]={262600,262800,262820,263100,263360,263380,263410,263550,263620};

string rpnames[NumEPNames];
TTree * tree;

double centval;
double vtx;
double epang[NumEPNames];
unsigned int  runno_;
Double_t rescor[NumEPNames];
Double_t rescorErr[NumEPNames];
TFile * tfin;
TH1D * cent[NumRunBins];
TH1D * runb;
Int_t NumEvnts; 
TString fname;

TCanvas * can[NumRunBins];
TH1D * hCent[NumRunBins];
TH1D * hHFm1[NumRunBins];
TH1D * hHFp1[NumRunBins];
TH1D * htrackm1mc[NumRunBins];
TH1D * htrackp1mc[NumRunBins];

TH1D * hHFm2[NumRunBins];
TH1D * hHFp2[NumRunBins];
TH1D * htrackm2[NumRunBins];
TH1D * htrackp2[NumRunBins];

TH1D * htrackmid2[NumRunBins];
TH1D * hCastor2[NumRunBins];


void FixHist(TH1D * h){
    h->SetYTitle("Counts");
    h->GetXaxis()->SetTitleFont(43);
    h->GetXaxis()->SetTitleSize(26);
    h->GetXaxis()->SetTitleOffset(2.2);
    h->GetYaxis()->SetTitleFont(43);
    h->GetYaxis()->SetTitleSize(26);
    h->GetYaxis()->SetTitleOffset(3.0);
}
void RunCheck(int MinCent = 0, int MaxCent = 80){
  tfin = new TFile("check.root","read");
  for(int i = 0; i<NumRunBins; i++) {
    cent[i] = new TH1D(Form("cent_%d_%d",(int)runBins[i],(int)runBins[i+1]),"cent",100,0,100);
    cent[i]->SetXTitle("Centrality");
    FixHist(cent[i]);
    cent[i]->SetYTitle("Counts");
    hHFm1[i] = new TH1D(Form("HFm1_%d_%d",(int)runBins[i],(int)runBins[i+1]),"HFm1",100,-4,4);
    hHFm1[i]->SetXTitle("#Psi_{HFm1}");
    FixHist(hHFm1[i]);
    hHFp1[i] = new TH1D(Form("HFp1_%d_%d",(int)runBins[i],(int)runBins[i+1]),"HFp1",100,-4,4);
    hHFp1[i]->SetXTitle("#Psi_{HFp1}");
    FixHist(hHFp1[i]);
    htrackm1mc[i] = new TH1D(Form("trackm1mc_%d_%d",(int)runBins[i],(int)runBins[i+1]),"trackm1mc",100,-4,4);
    htrackm1mc[i]->SetXTitle("#Psi_{trackm1mc}");
    FixHist(htrackm1mc[i]);
    htrackp1mc[i] = new TH1D(Form("trackp1mc_%d_%d",(int)runBins[i],(int)runBins[i+1]),"trackp1mc",100,-4,4);
    htrackp1mc[i]->SetXTitle("#Psi_{trackp1mc}");
    FixHist(htrackp1mc[i]);

    hHFm2[i] = new TH1D(Form("HFm2_%d_%d",(int)runBins[i],(int)runBins[i+1]),"HFm2",100,-2,2);
    hHFm2[i]->SetXTitle("#Psi_{HFm2}");
    FixHist(hHFm2[i]);
    hHFp2[i] = new TH1D(Form("HFp2_%d_%d",(int)runBins[i],(int)runBins[i+1]),"HFp2",100,-2,2);
    hHFp2[i]->SetXTitle("#Psi_{HFp2}");
    FixHist(hHFp2[i]);
    htrackm2[i] = new TH1D(Form("trackm2_%d_%d",(int)runBins[i],(int)runBins[i+1]),"trackm2",100,-2,2);
    htrackm2[i]->SetXTitle("#Psi_{trackm2}");
    FixHist(htrackm2[i]);
    htrackp2[i] = new TH1D(Form("trackp2_%d_%d",(int)runBins[i],(int)runBins[i+1]),"trackp2",100,-2,2);
    htrackp2[i]->SetXTitle("#Psi_{trackp2}");
    FixHist(htrackp2[i]);

    htrackmid2[i] = new TH1D(Form("trackmid2_%d_%d",(int)runBins[i],(int)runBins[i+1]),"trackmid2",100,-2,2);
    htrackmid2[i]->SetXTitle("#Psi_{trackmid2}");
    FixHist(htrackmid2[i]);
    hCastor2[i] = new TH1D(Form("Castor2_%d_%d",(int)runBins[i],(int)runBins[i+1]),"Castor2",100,-2,2);
    hCastor2[i]->SetXTitle("#Psi_{Castor2}");
    FixHist(hCastor2[i]);
  }
  runb = new TH1D("runb","runb",NumRunBins,runBins);
  tree = (TTree *) tfin->Get("checkflattening/tree");
  tree->SetBranchAddress("Cent",       &centval);
  tree->SetBranchAddress("Vtx",        &vtx);
  tree->SetBranchAddress("epang",      &epang);
  tree->SetBranchAddress("Run",        &runno_);
  tree->SetBranchAddress("Rescor",     &rescor);
  tree->SetBranchAddress("RescorErr",  &rescorErr);
  
  NumEvnts = tree->GetEntries() ;
  //  NumEvnts = 100000;
  cout<<"NumEvnts: "<<NumEvnts<<endl;
  for(int i = 0; i< NumEvnts; i++) {
    if(fmod(i,NumEvnts/20)==0) cout<<100*(double)i/(double) NumEvnts<<endl;
    tree->GetEntry(i);
    runb->Fill(runno_);
    int ibin = runb->GetXaxis()->FindBin(runno_)-1;
    cent[ibin]->Fill(centval);
    if(centval<MinCent || centval> MaxCent) continue;
    hHFm1[ibin]->Fill(epang[HFm1]);
    hHFp1[ibin]->Fill(epang[HFp1]);
    htrackm1mc[ibin]->Fill(epang[trackm1mc]);
    htrackp1mc[ibin]->Fill(epang[trackp1mc]);
    hHFm2[ibin]->Fill(epang[HFm2]);
    hHFp2[ibin]->Fill(epang[HFp2]);
    htrackm2[ibin]->Fill(epang[trackm2]);
    htrackp2[ibin]->Fill(epang[trackp2]);

    htrackmid2[ibin]->Fill(epang[trackmid2]);
    hCastor2[ibin]->Fill(epang[Castor2]);

  }

  TLatex * lruns[NumRunBins];
  TLatex * lcent[NumRunBins];
  for(int i = 0; i<NumRunBins; i++) {
    can[i] = new TCanvas(Form("Canvas_%d_%d",(int)runBins[i],(int)runBins[i+1]),Form("Canvas_%d_%d",(int)runBins[i],(int)runBins[i+1]),1200,1000);
    can[i]->Divide(4,3);
    can[i]->cd(1);
    hHFm1[i]->Draw();
    lruns[i] = new TLatex(-3,0.6*hHFm1[i]->GetMaximum(),Form("Runs: %d - %d",(int)runBins[i],(int)runBins[i+1]));
    lruns[i]->SetTextFont(43);
    lruns[i]->SetTextSize(18);
    lruns[i]->Draw();

    lcent[i] = new TLatex(-3,0.4*hHFm1[i]->GetMaximum(),Form("Cent: %d - %d",MinCent,MaxCent));
    lcent[i]->SetTextFont(43);
    lcent[i]->SetTextSize(18);
    lcent[i]->Draw();
    can[i]->cd(2);
    hHFp1[i]->Draw();
    can[i]->cd(3);
    htrackm1mc[i]->Draw();
    can[i]->cd(4);
    htrackp1mc[i]->Draw();

    can[i]->cd(5);
    hHFm2[i]->Draw();
    can[i]->cd(6);
    hHFp2[i]->Draw();
    can[i]->cd(7);
    htrackm2[i]->Draw();
    can[i]->cd(8);
    htrackp2[i]->Draw();

    can[i]->cd(9);
    htrackmid2[i]->Draw();
    can[i]->cd(10);
    hCastor2[i]->Draw();


    can[i]->cd(12);
    cent[i]->Draw();

    can[i]->Print(Form("%s.pdf",can[i]->GetName()),"pdf");
  }
}


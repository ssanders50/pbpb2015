void fixHist(TH1D *& h, double titleSize=28, double labelSize=24, TString Xtitle="", double xoff=1, TString Ytitle="", double yoff=1){
  h->GetXaxis()->CenterTitle();
  h->GetYaxis()->CenterTitle();
  h->GetXaxis()->SetTitleFont(43);
  h->GetYaxis()->SetTitleFont(43);
  h->GetXaxis()->SetLabelFont(43);
  h->GetYaxis()->SetLabelFont(43);
  h->GetXaxis()->SetTitleSize(titleSize);
  h->GetYaxis()->SetTitleSize(titleSize);
  h->GetXaxis()->SetLabelSize(labelSize);
  h->GetYaxis()->SetLabelSize(labelSize);
  h->SetXTitle(Xtitle.Data());
  h->SetYTitle(Ytitle.Data());
  h->GetXaxis()->SetTitleOffset(xoff);
  h->GetYaxis()->SetTitleOffset(yoff);
}
TLatex * tlabel(double x, double y, TString text, double size, int col){
  TLatex * tmp = new TLatex(x,y,text.Data());
  tmp->SetTextFont(43);
  tmp->SetTextSize(size);
  tmp->SetTextColor(col);
  tmp->Draw();
  return tmp;
}

TLegend * tleg(double xmin, double ymin, double xmax, double ymax, TString title, double size){
  TLegend * tmp = new TLegend(xmin,ymin,xmax,ymax,title.Data());
  tmp->SetFillColor(kWhite);
  tmp->SetBorderSize(0);
  tmp->SetTextFont(43);
  tmp->SetTextSize(size);
  return tmp;
}
void MakePlot(){	
  TFile * tf = new TFile("rpflat_combined.root");
  TH1D * hbefore_m[4];	
  TH1D * hafter_m[4];	
  TH1D * hbefore_p[4];
  TH1D * hafter_p[4];
  TCanvas * c = new TCanvas("c","c",1300,1000);
  c->Divide(2,3);
  for(int i = 0; i<3; i++) {
    hbefore_m[i] = (TH1D *)tf->Get(Form("hiEvtPlaneFlatCalib/HFm%d/psi",i+2));
    hbefore_m[i]->SetLineColor(kBlue);
    hbefore_m[i]->Rebin(4);
    fixHist(hbefore_m[i],28,22,Form("#Psi_{%d} (radians)",i+2),2.6,"Counts",3);
    hbefore_p[i] = (TH1D *)tf->Get(Form("hiEvtPlaneFlatCalib/HFp%d/psi",i+2));
    hbefore_p[i]->SetLineColor(kRed);
    hbefore_p[i]->Rebin(4);
    fixHist(hbefore_p[i],28,22,Form("#Psi_{%d} (radians)",i+2),2.6,"Counts",3);
    c->cd(i*2+1);
    gPad->SetBottomMargin(0.2);
    //gPad->SetRightMargin(0.02);
    //gPad->SetTopMargin(0.02);
    hbefore_m[i]->Draw("same");
    hbefore_p[i]->Draw("same");

  }
  c->cd(1);
  TLegend * leg = tleg(0.3,0.3,0.6,0.5,"",28);
  leg->AddEntry(hbefore_m[0],"HF-","lp");
  leg->AddEntry(hbefore_p[0],"HF+","lp");
  leg->Draw();
  tlabel(0,400,"BEFORE",32,kBlue)->Draw();
  tlabel(-1,650,"Hydjet (CMSSW_7_5_0)",30,kBlue)->Draw();
  for(int i = 0; i<3; i++) {
    hafter_m[i] = (TH1D *)tf->Get(Form("hiEvtPlaneFlatCalib/HFm%d/psiFlat",i+2));
    hafter_m[i]->SetLineColor(kBlue);
    hafter_m[i]->Rebin(4);
    fixHist(hafter_m[i],28,22,Form("#Psi_{%d} (radians)",i+2),2.6,"Counts",3);
    hafter_p[i] = (TH1D *)tf->Get(Form("hiEvtPlaneFlatCalib/HFp%d/psiFlat",i+2));
    hafter_p[i]->SetLineColor(kRed);
    hafter_p[i]->Rebin(4);
    fixHist(hafter_p[i],28,22,Form("#Psi_{%d} (radians)",i+2),2.6,"Counts",3);
    c->cd(i*2+2);
    gPad->SetBottomMargin(0.2);
    //gPad->SetRightMargin(0.02);
    //gPad->SetTopMargin(0.02);
    hafter_m[i]->Draw("same");
    hafter_p[i]->Draw("same");

  }
  c->cd(2);
  tlabel(0,400,"AFTER",32,kBlue)->Draw();
  c->Print("EP.pdf","pdf");
}

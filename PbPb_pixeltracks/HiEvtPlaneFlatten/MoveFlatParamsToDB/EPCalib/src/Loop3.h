#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH1I.h"
#include "TDirectory.h"
#include <iostream>
#include "string.h"
#include "stdio.h"

#include "EPCalib/HiEvtPlaneList.h"
#include "EPCalib/HiEvtPlaneFlatten.h"
void Loop3(){
  save = fopen("tmpsave","rb");
  cout<<"Loop 3:"<<endl;
  ncnt = 0;
  while(fread(&sout, sizeof(struct sout_struct), 1, save) >0) {
    EPcent = (float) sout.cent;
    EPvtx = (float) sout.vtx;
    EPntrk = sout.ntrk;
    EPrun = sout.run;
    vtx = sout.vtx;
    bin = sout.bin;
    centval=sout.cent;
    for(int j = 0; j<NumEPNames; j++) {
      double psiOffset = -10;
      double psiFlat = -10;
      EPAngs[j] = -10;
      if(sout.msum[j]>0) {
	psiOffset = flat[j]->getOffsetPsi(sout.ws[j],sout.wc[j]);
	if(centval<80 && fabs(vtx)<15&&bin>=0) {
	  hPsiOffset2[j]->Fill(psiOffset);	
	}
	psiFlat = flatOffset[j]->getFlatPsi(psiOffset,vtx,bin);
	EPAngs[j]=psiFlat;
	if(centval<80 && fabs(vtx)<15&&bin>=0) {
	  hPsiFlat[j]->Fill(psiFlat);
	}
      }
    }
    ++ncnt;
    //if(ncnt==100) break;
    EPtree->Fill();

  }
  
}

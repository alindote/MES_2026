#include "TROOT.h"
#include "TTree.h"
#include "TH2F.h"
#include "TArc.h"
#include "TLine.h"

TTree *gKnife = new TTree();

// This will be useful to check the beam aperture
TArc* aperture = new TArc(22.,22.,7.);
TLine* beamR = new TLine(9.,0.,9.,5.);

void LoadFile(){

	gStyle->SetOptStat(0);

	gKnife->SetMarkerStyle(20);
	gKnife->SetMarkerSize(0.1);

	gKnife->ReadFile("eDep_scorer.out","x:y:z:E:E2:i");

	gKnife->Draw("E");

	// These histograms may come in handy
	TH2F *h200 = new TH2F("h200","XY plane projection",45,0,44,45,0,44);
	TH2F *h201 = new TH2F("h201","E vs R",63,0,62,70,0,3.5);
	TH2F *h202 = new TH2F("h202","E vs z",45,0,44,70,0,3.5);

	aperture->SetFillColorAlpha(kWhite, 0.);
	beamR->SetLineColor(kRed);
	beamR->SetLineWidth(3);

	// some plot examples
	//gKnife->Draw("y:x>>h200","E>0","col");
	//gKnife->Draw("E:sqrt(x**2+y**2)>>h201");
	//gKnife->Draw("E:z>>h202");

}

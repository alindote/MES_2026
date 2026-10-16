{
gROOT -> Reset();
gStyle->SetOptStat(0);

TFile f("human_phantom.root");

TDirectory* dir = (TDirectory*)f.Get("human_phantom_ntuple");
TTree* ntuple = (TTree*)dir->Get("1");
ntuple -> Print();   
 
// Print the content of the ntuple  
Int_t nevent = Int_t(ntuple->GetEntries());

Double_t organID;
Double_t edep;
ntuple->GetBranch("organID")->SetAddress(&organID);      
ntuple->GetBranch("edep")->SetAddress(&edep);   

const int Norgans = 42;
const char *organs[Norgans]  = {"Brain","Head","Heart","LeftAdrenal","LeftArmBone","LeftBreast",	
				"LeftClavicle","LeftKidney","LeftLeg","LeftLegBone","LeftLung",	
				"LeftOvary","LeftScapula","LeftTeste","LowerLargeIntestine",
				"MaleGenitalia","MiddleLowerSpine","Pancreas","Pelvis",	"RibCage",	 	
				"RightAdrenal","RightArmBone","RightBreast","RightClavicle",	 
				"RightKidney","RightLeg","RightLegBone","RightLung","RightOvary",	 
				"RightScapula","RightTeste","Skull","SmallIntestine","Spleen",
				"Stomach","Thymus","Thyroid","Trunk","UpperLargeIntestine",
				"UpperSpine","UrinaryBladder","Uterus"};
const double mass[Norgans] = {1451,4595.45,111,7.751,1217.78,111,20.31,141.85,10252.1,2080.29,111,111,
				149.224,18.54,339.60,226.53,1120.57,60.17,900.10,1028.56,7.751,1217.78,
				111,20.31,142.372,10252.1,2080.29,111,111,149.805,18.54,1257.28,1006.21,
				173.625,396.86,24.8,111,43406.1,429.275,187.792,45.1,111};


TCanvas *c1 = new TCanvas("c1","demo bin labels",10,10,600,600);
//c1->SetGrid();
c1->SetBottomMargin(0.25);
c1->SetLeftMargin(0.15);
TH1F* h100 = new TH1F("h100","Absorbed energy",Norgans,0,41);
TH1F* h101 = new TH1F("h101","Absorbed dose",Norgans,0,41);

for ( Int_t i=0; i<nevent; i++ ) {
     ntuple->GetEvent(i);
     cout << "organ, edep (MeV): " 
          << organs[(int)organID] << ", " << edep << endl;
     h100->Fill(organs[(int)organID],edep);
   }

h100->LabelsDeflate("X");
h100->SetBarWidth(0.5);
h100->SetBarOffset(0.25);
h100->SetFillColor(49);
h100->LabelsOption("v");
h100->GetYaxis()->SetTitle("E (MeV)");
h100->Draw("histbar2");

}

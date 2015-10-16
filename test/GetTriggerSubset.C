#define GetTriggerSubset_cxx
#include "GetTriggerSubset.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void GetTriggerSubset::Loop(TString outputname)
{
	TFile *newfile = new TFile("Rootuple_TriggerSubset/"+outputname+"Subset.root", "RECREATE");
	TDirectory *newDir = newfile->mkdir("rootuple");
	newDir->cd();
	TTree *newtree = fChain->CloneTree(0);

	if (fChain == 0) return;

	Long64_t nentries = fChain->GetEntriesFast();

	Long64_t nbytes = 0, nb = 0;
	for (Long64_t jentry=0; jentry<nentries;jentry++) {
		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;
		nb = fChain->GetEntry(jentry);   nbytes += nb;

		bool flag = 0;
		if (outputname == "Charmonium_Jpsi") flag = ((trigger&73)==0 || (trigger&512)!=0 || dimuon_p4->M()<2.9 || dimuon_p4->M()>3.35); 
		else if (outputname == "Charmonium_psiprime") flag = ((trigger&18)==0 || (trigger&512)!=0 || dimuon_p4->M()<3.35 || dimuon_p4->M()>4.1);
		else if (outputname == "Charmonium_Bs") flag = ((trigger&256)==0 || (trigger&512)!=0 || dimuon_p4->M()<4.1 || dimuon_p4->M()>6.1);
		else if (outputname == "MuOnia_Upsilon") flag = ((trigger&36)==0 || (trigger&512)!=0 || dimuon_p4->M()<8.3 || dimuon_p4->M()>11.2);
		else if (outputname == "MuOnia_phi") flag = ((trigger&128)==0 || (trigger&512)!=0 || dimuon_p4->M()<0.84 || dimuon_p4->M()>1.3);
		else if (outputname == "DoubleMuonLowMass_") flag = ((trigger&512)==0 || dimuon_p4->M()<0.96 || dimuon_p4->M()>5);
		else if (outputname == "DoubleMuon_") flag = 0;
		if (flag) continue;
		newtree->Fill();
	}
	newfile->Write();
}

#define SinglePD_cxx
#include "SinglePD.h"
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TLatex.h>

void SinglePD::Loop(TString PD)
{
	double xbins[100000];
	xbins[0] = .1; 
	int nbins = 0;
	double binWidth=0.005; 
	for (int i=1; xbins[i-1]<500; i++) {
		xbins[i] = xbins[i-1]*(1+binWidth);
		nbins++;
		cout << nbins << " "<< xbins[i] << endl;
	}

	TH1F *hDimuonMass = new TH1F("hDimuonMass","hDimuonMass",nbins,xbins);
	TH1F *hDimuonMass_normal = new TH1F("hDimuonMass_normal","hDimuonMass_normal",10000,0.2,500);
	hDimuonMass->GetXaxis()->SetTitle("#mu^{+}#mu^{-} invariant mass [GeV]");
	hDimuonMass->GetYaxis()->SetTitle("Events / GeV");

	if (fChain == 0) return;

	Long64_t nentries = fChain->GetEntriesFast();
	//Long64_t nentries = 100000;

	Long64_t nbytes = 0, nb = 0;
	for (Long64_t jentry=0; jentry<nentries;jentry++) {
		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;
		nb = fChain->GetEntry(jentry);   nbytes += nb;
		// if (Cut(ientry) < 0) continue;
		double mass = dimuon_p4->M();
		//if (mass>80) cout<<trigger<<endl;
		//if (trigger == 256 || trigger == 16 || trigger ==264)continue;
		hDimuonMass_normal->Fill(mass);
		hDimuonMass->Fill(mass);
	}
	for (int i=1; i<=hDimuonMass->GetNbinsX(); i++) {
		hDimuonMass->SetBinContent(i, hDimuonMass->GetBinContent(i)/hDimuonMass->GetBinWidth(i));
	}

	TCanvas *c1 = new TCanvas("c1","c1",800,600);
	c1->SetLogx();
	c1->SetLogy();
	hDimuonMass->Draw("HIST");

	TLatex L;
	L.SetNDC();
	L.DrawLatex(0.3,0.3,"CMS Preliminary");
	L.DrawLatex(0.3,0.25,"2015 Run, 2.7 fb^{-1} (13 TeV)");
	L.DrawLatex(0.3,0.2,"PD: "+PD);
	//L.DrawLatex(0.31,0.82,"#omega");
	//L.DrawLatex(0.32,0.87,"#phi");
	//L.DrawLatex(0.4,0.86,"J/#psi");
	//L.DrawLatex(0.46,0.72,"#psi'");
	//L.DrawLatex(0.49,0.7,"B_{s}");
	//L.DrawLatex(0.55,0.82,"#Upsilon");
	//L.DrawLatex(0.77,0.76,"Z");

	c1->SaveAs("plots/dimuonMass_"+PD+".pdf");
	c1->SaveAs("plots/dimuonMass_"+PD+".png");

}

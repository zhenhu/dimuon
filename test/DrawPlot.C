#include "tdrstyle.C"
#include "CMS_lumi.C"

void GetHist(TString f, TH1F *h)
{
	TFile *input = TFile::Open(f,"READ");
	TTree *Tree = (TTree*)input->Get("rootuple/oniaTree");
	TLorentzVector  *dimuon_p4;
	Int_t run;
	Int_t lumi;
	dimuon_p4 = 0;
	TBranch        *b_dimuon_p4;
	TBranch        *b_run;
	TBranch        *b_lumi;
	Tree->SetBranchAddress("dimuon_p4", &dimuon_p4, &b_dimuon_p4);
	Tree->SetBranchAddress("run", &run, &b_run);
	Tree->SetBranchAddress("lumi", &lumi, &b_lumi);
	Int_t nentries = (Int_t)Tree->GetEntries();
	std::cout<<f<<" entries: "<<nentries<<std::endl;
	for (Long64_t kentry=0; kentry<nentries;kentry++) {
		Long64_t lentry = Tree->LoadTree(kentry);
		if (lentry < 0) break;
		b_dimuon_p4->GetEntry(kentry);
		b_run->GetEntry(kentry);
		b_lumi->GetEntry(kentry);
		//if (run>=251490 && run<=251509) continue;
		//if (run==251244 || run==251251 || run==251252 || run==251561 || run==251562) 
		/*if ( 
		  ( run==251168 && ( (lumi>=1   && lumi<=287) ||
		                     (lumi>=295 && lumi<=341) ) ) ||
		  ( run==251244 && ( (lumi>=85  && lumi<=86)  ||
		                     (lumi>=88  && lumi<=93)  ||
		                     (lumi>=96  && lumi<=156) ||
		                     (lumi>=158 && lumi<=442) ) ) ||
		  ( run==251251 && ( (lumi>=1   && lumi<=167) ) ) ||
		  ( run==251252 && ( (lumi>=1   && lumi<=554) ) )
		  )*/
		//if (run<251168) continue;
		//if (run==251721 && lumi>89) continue;
		{
			double mass = dimuon_p4->M();
			h->Fill(mass);
		}
	}
	for (int i=1; i<=h->GetNbinsX(); i++) {
		h->SetBinContent(i, h->GetBinContent(i)/h->GetBinWidth(i));
	}   

}

void DrawPlot() {

	setTDRStyle();

	writeExtraText = true;       // if extra text
	//extraText  = "Preliminary";  // default extra text is "Preliminary"
	lumi_13TeV = "2.7 fb^{-1}";
	lumi_8TeV  = "19.1 fb^{-1}"; // default is "19.7 fb^{-1}"
	lumi_7TeV  = "4.9 fb^{-1}";  // default is "5.1 fb^{-1}"
	int iPeriod = 4;    // 1=7TeV, 2=8TeV, 3=7+8TeV, 4=13TeV, 7=7+8+13TeV 
	int iPos = 11;

	double xbins[100000];
	xbins[0] = .1;
	int nbins = 0;
	double binWidth=0.004;//0.01; 
	for (int i=1; xbins[i-1]<500; i++) {
		xbins[i] = xbins[i-1]*(1+binWidth);
		nbins++;
		cout << nbins << " "<< xbins[i] << endl;
	}
	//cout << nbins << endl;

	TH1F *hDoubleMuon = new TH1F("hDoubleMuon","hDoubleMuon",nbins,xbins);
	GetHist("Rootuple_TriggerSubset/DoubleMuon_Subset.root",hDoubleMuon);
	hDoubleMuon->SetFillColor(kGray);
	hDoubleMuon->SetLineColor(kGray);
	hDoubleMuon->SetLineWidth(0);

	TH1F *hLowMass = new TH1F("hLowMass","hLowMass",nbins,xbins);
	GetHist("Rootuple_TriggerSubset/DoubleMuonLowMass_Subset.root",hLowMass);
	hLowMass->SetFillColor(kBlue-5);
	hLowMass->SetLineColor(kBlue-5);
	hLowMass->SetLineWidth(0);

	TH1F *hphi = new TH1F("hphi","hphi",nbins,xbins);
	GetHist("Rootuple_TriggerSubset/MuOnia_phiSubset.root",hphi);
	hphi->SetFillColor(kMagenta);
	hphi->SetLineColor(kMagenta);
	hphi->SetLineWidth(0);

	TH1F *hJpsi = new TH1F("hJpsi","hJpsi",nbins,xbins);
	GetHist("Rootuple_TriggerSubset/Charmonium_JpsiSubset.root",hJpsi);
	hJpsi->SetFillColor(kRed);
	hJpsi->SetLineColor(kRed);
	hJpsi->SetLineWidth(0);

	TH1F *hpsiprime = new TH1F("hpsiprime","hpsiprime",nbins,xbins);
	GetHist("Rootuple_TriggerSubset/Charmonium_psiprimeSubset.root",hpsiprime);
	hpsiprime->SetFillColor(kBlue);
	hpsiprime->SetLineColor(kBlue);
	hpsiprime->SetLineWidth(0);

	TH1F *hBs = new TH1F("hBs","hBs",nbins,xbins);
	GetHist("Rootuple_TriggerSubset/Charmonium_BsSubset.root",hBs);
	hBs->SetFillColor(kCyan);
	hBs->SetLineColor(kCyan);
	hBs->SetLineWidth(0);

	TH1F *hUpsilon = new TH1F("hUpsilon","hUpsilon",nbins,xbins);
	GetHist("Rootuple_TriggerSubset/MuOnia_UpsilonSubset.root",hUpsilon);
	hUpsilon->SetFillColor(kGreen+1);
	hUpsilon->SetLineColor(kGreen+1);
	hUpsilon->SetLineWidth(0);


	TH1F *hAll = new TH1F("hAll","hAll",nbins,xbins);
	hAll->Add(hDoubleMuon);
	hAll->Add(hLowMass);
	hAll->Add(hphi);
	hAll->Add(hJpsi);
	hAll->Add(hpsiprime);
	hAll->Add(hBs);
	hAll->Add(hUpsilon);

	THStack *hs = new THStack("hs","hs");
	hs->Add(hDoubleMuon);
	hs->Add(hLowMass);
	hs->Add(hphi);
	hs->Add(hJpsi);
	hs->Add(hpsiprime);
	hs->Add(hBs);
	hs->Add(hUpsilon);

	//  if( iPos==0 ) relPosX = 0.12;

	int W = 900;
	int H = 600;

	int H_ref = 600; 
	int W_ref = 920; 

	// references for T, B, L, R
	float T = 0.08*H_ref;
	float B = 0.13*H_ref; 
	float L = 0.12*W_ref;
	float R = 0.04*W_ref;

	TCanvas* canv = new TCanvas("dimuon","dimuon",50,50,W,H);
	canv->SetFillColor(0);
	canv->SetBorderMode(0);
	canv->SetFrameFillStyle(0);
	canv->SetFrameBorderMode(0);
	canv->SetLeftMargin( L/W );
	canv->SetRightMargin( R/W );
	canv->SetTopMargin( T/H );
	canv->SetBottomMargin( B/H );
	canv->SetTickx(0);
	canv->SetTicky(0);

	canv->SetLogx();
	canv->SetLogy();

	TH1F *hFrame= gPad->DrawFrame(0.3, 200, 200, 1e10); //Nov 13, Cert_246908-260627_13TeV_PromptReco_Collisions15_25ns_JSON_MuonPhys.txt
	hFrame->SetXTitle("#mu^{+}#mu^{-} invariant mass [GeV]");
	hFrame->SetYTitle("Events / GeV");

	hs->Draw("HISTsame");
	hAll->Draw("HISTsame");

	TLatex Latex;
	Latex.DrawLatex(0.7,20000*150,"#omega");
	Latex.DrawLatex(0.955,800000*150,"#phi");
	Latex.DrawLatex(2.6,3000000*150,"J/#psi");
	Latex.DrawLatex(3.4,300000*150,"#psi'");
	Latex.DrawLatex(4.6,40000*150,"B_{s}");
	Latex.DrawLatex(8.7,100000*150,"#Upsilon");
	Latex.DrawLatex(85,4000*150,"Z");

	leg = new TLegend(0.58,0.58,0.94,0.92);
	leg->SetFillColor(0);
	leg->SetHeader("Trigger paths");
	leg->AddEntry(hphi,"#phi","f");
	leg->AddEntry(hJpsi,"J/#psi","f");
	leg->AddEntry(hpsiprime,"#psi'","f");
	leg->AddEntry(hBs,"B_{s}","f");
	leg->AddEntry(hUpsilon,"#Upsilon","f");
	leg->AddEntry(hLowMass,"low mass double muon + track","f");
	leg->AddEntry(hDoubleMuon,"double muon inclusive","f");
	leg->Draw();

	CMS_lumi( canv, iPeriod, iPos );
	canv->Update();
	canv->RedrawAxis();
	canv->GetFrame()->Draw();

	canv->SaveAs("plots/dimuonMass_Run2015CD_25ns.png");
	canv->SaveAs("plots/dimuonMass_Run2015CD_25ns.pdf");
}

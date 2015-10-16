#include "SinglePD.C"
void runSinglePD()
{
	TChain * chain = new TChain("rootuple/oniaTree","");
	//TString PD = "DoubleMuon";        // all peaks from omega to Z
	//TString PD = "DoubleMuonLowMass"; // 
	TString PD = "Charmonium";        // Bs, Jpsi, psiprime 
	//TString PD = "MuOnia";            // phi, Upsilon

	chain->Add("/eos/uscms/store/user/zhenhu/"+PD+"/Onia2MuMuRootuple-Run2015D-"+PD+"-v1/RootupleAll.root"); 

	SinglePD a(chain);
	a.Loop(PD);
}

#include "SinglePD.C"
void runSinglePD()
{
	TChain * chain = new TChain("rootuple/oniaTree","");
	//TString PD = "DoubleMuon";        // all peaks from omega to Z
	//TString PD = "DoubleMuonLowMass"; // 
	TString PD = "Charmonium";        // Bs, Jpsi, psiprime 
	//TString PD = "MuOnia";            // phi, Upsilon

	chain->Add("root://cmsxrootd.fnal.gov//store/user/zhenhu/"+PD+"/Rootuple_all.root"); 
	SinglePD a(chain);
	a.Loop(PD);
}

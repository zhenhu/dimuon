#include "GetTriggerSubset.C"
void runGetTriggerSubset()
{
	std::vector<TString> PD, Trigger;
	PD.push_back("Charmonium");        Trigger.push_back("_Jpsi");
	PD.push_back("Charmonium");        Trigger.push_back("_psiprime");
	PD.push_back("Charmonium");        Trigger.push_back("_Bs");
	PD.push_back("MuOnia");            Trigger.push_back("_Upsilon");
	PD.push_back("MuOnia");            Trigger.push_back("_phi");
	PD.push_back("DoubleMuonLowMass"); Trigger.push_back("_");
	PD.push_back("DoubleMuon");        Trigger.push_back("_");

	for (int i=0; i<7; i++) {
		TChain * chain = new TChain("rootuple/oniaTree","");
		chain->Add("/eos/uscms/store/user/zhenhu/"+PD[i]+"/Rootuple_all.root"); 
		GetTriggerSubset a(chain);
		a.Loop(PD[i]+Trigger[i]);
	}
}

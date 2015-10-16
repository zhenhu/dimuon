//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jul 16 01:55:20 2015 by ROOT version 6.02/05
// from TTree oniaTree/Tree of Onia2MuMu
// found on file: /eos/uscms/store/user/zhenhu/Charmonium/Onia2MuMuRootuple-Run2015B-Charmonium-v2/f64ae4aafa8965110120322f8d8de3c5/RootupleAll.root
//////////////////////////////////////////////////////////

#ifndef GetTriggerSubset_h
#define GetTriggerSubset_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TLorentzVector.h"

class GetTriggerSubset {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   Int_t           lumi;
   Int_t           event;
   Int_t           irank;
   Int_t           trigger;
   TLorentzVector  *dimuon_p4;
   TLorentzVector  *muonP_p4;
   TLorentzVector  *muonN_p4;
   Float_t         MassErr;
   Float_t         vProb;
   Float_t         DCA;
   Float_t         ppdlPV;
   Float_t         ppdlErrPV;
   Float_t         cosAlpha;
   Int_t           numPrimaryVertices;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_event;   //!
   TBranch        *b_irank;   //!
   TBranch        *b_trigger;   //!
   TBranch        *b_dimuon_p4;   //!
   TBranch        *b_muonP_p4;   //!
   TBranch        *b_muonN_p4;   //!
   TBranch        *b_MassErr;   //!
   TBranch        *b_vProb;   //!
   TBranch        *b_DCA;   //!
   TBranch        *b_ppdlPV;   //!
   TBranch        *b_ppdlErrPV;   //!
   TBranch        *b_cosAlpha;   //!
   TBranch        *b_numPrimaryVertices;   //!

   GetTriggerSubset(TTree *tree=0);
   virtual ~GetTriggerSubset();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(TString outputname);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef GetTriggerSubset_cxx
GetTriggerSubset::GetTriggerSubset(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/uscms/store/user/zhenhu/Charmonium/Onia2MuMuRootuple-Run2015B-Charmonium-v2/f64ae4aafa8965110120322f8d8de3c5/RootupleAll.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/eos/uscms/store/user/zhenhu/Charmonium/Onia2MuMuRootuple-Run2015B-Charmonium-v2/f64ae4aafa8965110120322f8d8de3c5/RootupleAll.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/eos/uscms/store/user/zhenhu/Charmonium/Onia2MuMuRootuple-Run2015B-Charmonium-v2/f64ae4aafa8965110120322f8d8de3c5/RootupleAll.root:/rootuple");
      dir->GetObject("oniaTree",tree);

   }
   Init(tree);
}

GetTriggerSubset::~GetTriggerSubset()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t GetTriggerSubset::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t GetTriggerSubset::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void GetTriggerSubset::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times whlumirunning on PROOF
   // (once per file to be processed).

   // Set object pointer
   dimuon_p4 = 0;
   muonP_p4 = 0;
   muonN_p4 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("irank", &irank, &b_irank);
   fChain->SetBranchAddress("trigger", &trigger, &b_trigger);
   fChain->SetBranchAddress("dimuon_p4", &dimuon_p4, &b_dimuon_p4);
   fChain->SetBranchAddress("muonP_p4", &muonP_p4, &b_muonP_p4);
   fChain->SetBranchAddress("muonN_p4", &muonN_p4, &b_muonN_p4);
   fChain->SetBranchAddress("MassErr", &MassErr, &b_MassErr);
   fChain->SetBranchAddress("vProb", &vProb, &b_vProb);
   fChain->SetBranchAddress("DCA", &DCA, &b_DCA);
   fChain->SetBranchAddress("ppdlPV", &ppdlPV, &b_ppdlPV);
   fChain->SetBranchAddress("ppdlErrPV", &ppdlErrPV, &b_ppdlErrPV);
   fChain->SetBranchAddress("cosAlpha", &cosAlpha, &b_cosAlpha);
   fChain->SetBranchAddress("numPrimaryVertices", &numPrimaryVertices, &b_numPrimaryVertices);
   Notify();
}

Bool_t GetTriggerSubset::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void GetTriggerSubset::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t GetTriggerSubset::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef GetTriggerSubset_cxx

import FWCore.ParameterSet.Config as cms
process = cms.Process("Rootuple")

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 500

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))

process.source = cms.Source("PoolSource",
   fileNames = cms.untracked.vstring('file:/eos/uscms/store/user/lpcmuon/Run2017/Charmonium/BPHSkim-v1-Run2017B-PromptReco-v1/170712_013151/0000/BPHSkim_106.root')
)

process.TFileService = cms.Service("TFileService",
   fileName = cms.string('Rootuple_test.root'),
)

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True))

process.load('dimuon.Onia.Onia2MuMuRootupler_cfi')
process.p = cms.Path(process.rootuple)

process.rootuple.isMC = cms.bool(False)                 # is mc?
process.rootuple.onia_mass_cuts = cms.vdouble(0.1,500)    # you may need to adjust this

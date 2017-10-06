from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

dataSet = "MuOnia" # Charmonium  MuOnia  DoubleMuon  DoubleMuonLowMass
run = "2017B"
skimVersion = "v1"
userId = "75fb2e6615d4f613acbb8a1c973010c7"
ntupleVersion = "v1"

config.General.requestName = dataSet + run + ntupleVersion
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '../runOnia2MuMuRootupler.py'
#config.JobType.outputFiles = ['Rootuple_test.root']

#config.Data.inputDataset = '/Charmonium/asanchez-BPHSkim-v1-Run2016B-PromptReco-v2-f3371d8706d2a64e31e991df87f57a46/USER'
config.Data.inputDataset = '/' + dataSet +'/zhenhu-BPHSkim-' + skimVersion + '-Run' + run + '-PromptReco-v1-' + userId + '/USER'
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 10

config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = False
config.Data.outputDatasetTag  = 'Run' + run + '-Onia2MuMuRootuple-' + ntupleVersion
config.Site.storageSite = 'T3_US_FNALLPC'

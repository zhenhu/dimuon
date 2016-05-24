from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'DoubleMuon2016Bv1'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '../runOnia2MuMuRootupler.py'
#config.JobType.outputFiles = ['Rootuple_test.root']

config.Data.inputDataset = '/DoubleMuon/asanchez-BPHSkim-v1-Run2016B-PromptReco-v2-f3371d8706d2a64e31e991df87f57a46/USER'
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 10

config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = False
config.Data.outputDatasetTag  = 'Run2016B-Onia2MuMuRootuple-v1'
config.Site.storageSite = 'T3_US_FNALLPC'

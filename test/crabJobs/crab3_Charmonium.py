from WMCore.Configuration import Configuration
config = Configuration()

config.section_('General')
config.General.transferOutputs = True
#config.General.requestName = 'Charmonium2015Cv1'
config.General.requestName = 'Charmonium2015Dv4'

config.section_('JobType')
config.JobType.psetName = '../runOnia2MuMuRootupler.py'
config.JobType.pluginName = 'Analysis'
#config.JobType.outputFiles = ['Onia2MuMuPAT.root']

config.section_('Data')
#config.Data.inputDataset = '/Charmonium/zhenhu-Run2015C-Onia2MuMuPAT-v1-ca8022810ea1b04e8e12c6056abc0a7d/USER'
config.Data.inputDataset = '/Charmonium/zhenhu-Run2015D-Onia2MuMuPAT-v4-ca8022810ea1b04e8e12c6056abc0a7d/USER'
config.Data.inputDBS = 'phys03'
config.Data.unitsPerJob = 50
config.Data.splitting = 'LumiBased'
#config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
#config.Data.outLFNDirBase = '/store/user/yik/myfourmuonNtpl/muonia/2015Dwith25nsv3'
#config.Data.lumiMask = 'Cert_246908-258159_13TeV_PromptReco_Collisions15_25ns_JSON_MuonPhys.txt'
config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions15/13TeV/Cert_246908-260627_13TeV_PromptReco_Collisions15_25ns_JSON_MuonPhys.txt'
#config.Data.runRange = '193093-193999' # '193093-194075'
config.Data.publication = True
#config.Data.outputDatasetTag = 'Run2015C-Onia2MuMuRootuple-v1'
config.Data.outputDatasetTag = 'Run2015D-Onia2MuMuRootuple-v4'
config.Data.ignoreLocality = True

config.section_('User')

config.section_('Site')
config.Site.storageSite = 'T3_US_FNALLPC' 


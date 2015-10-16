from WMCore.Configuration import Configuration
config = Configuration()

config.section_('General')
config.General.transferOutputs = True
config.General.requestName = 'Charmonium2015Dv1'

config.section_('JobType')
config.JobType.psetName = '../runOnia2MuMuRootupler.py'
config.JobType.pluginName = 'Analysis'
#config.JobType.outputFiles = ['Onia2MuMuPAT.root']

config.section_('Data')
config.Data.inputDataset = '/Charmonium/zhenhu-Onia2MuMuPAT-Run2015D-Charmonium-v1-27683f6dcdbf9b00562643341d80f784/USER'
config.Data.inputDBS = 'phys03'
config.Data.unitsPerJob = 50
config.Data.splitting = 'LumiBased'
#config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
#config.Data.outLFNDirBase = '/store/user/yik/myfourmuonNtpl/muonia/2015Dwith25nsv3'
#config.Data.lumiMask = 'Cert_246908-258159_13TeV_PromptReco_Collisions15_25ns_JSON_MuonPhys.txt'
config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions15/13TeV/Cert_246908-258159_13TeV_PromptReco_Collisions15_25ns_JSON_MuonPhys_v2.txt'
#config.Data.runRange = '193093-193999' # '193093-194075'
config.Data.publication = True
config.Data.publishDataName = 'Onia2MuMuRootuple-Run2015D-Charmonium-v1'
config.Data.ignoreLocality = True

config.section_('User')

config.section_('Site')
config.Site.storageSite = 'T3_US_FNALLPC' 


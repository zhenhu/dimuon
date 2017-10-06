#Onia2MuMu Rootupler

The Onia2MuMu Rootupler. This package is mean to be run after the BPH CompactSkim. 

* **Onia2MuMuRootupler** - Rootupler of the Onia2MuMu objects
* **OniaMM**             - Rootupler for genparticles objects, AOD

* Setup: (should run with the same release in CompactSkim, but may run in any other)

```
cmsrel CMSSW_9_2_10
cd CMSSW_9_2_10/src/
cmsenv
git clone git@github.com:zhenhu/dimuon.git dimuon/Onia
cd dimuon/Onia/
scram b
```

* Run local test: (use your favorite input sample)

```
cd test
vi runOnia2MuMuRootupler.py
cmsRun runOnia2MuMuRootupler.py
```
You may need to uodate the trigger paths in Onia/src/Onia2MuMuRootupler.cc

* Produce root trees with this package for each dataset: Charmonium, MuOnia, DoubleMuon, DoubleMuonLowMass

The crab3 config: Onia/test/crabJobs/crab3_all.py


#Make the dimuom mass spectrum plot

* (Optional) Draw a plot for a single dataset 
```
root -l runSinglePD.C++
```

* Produce data subsets for different triggers 
```
root -l runGetTriggerSubset.C++
```

* Draw combined plot 
```
root -l DrawPlot.C
```

#Official BPH CompactSkim

* Setup: it has been part of CMSSW_7_5_X onwards, but for earlier version, you can do: 

```
export SCRAM_ARCH=slc6_amd64_gcc491
source /cvmfs/cms.cern.ch/cmsset_default.sh
cmsrel CMSSW_7_4_6_patch6
cd CMSSW_7_4_6_patch6/src/
cmsenv
git cms-merge-topic alberto-sanchez:onia2mumu-74x
scram b
``` 

* Run: (adjust the inputs)

```
vi HeavyFlavorAnalysis/Skimming/test/runCompactSkim.py
cmsRun HeavyFlavorAnalysis/Skimming/test/runCompactSkim.py
```


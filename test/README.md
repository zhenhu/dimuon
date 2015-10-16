Step 1: Produce root trees with this package for each dataset
You may need to add more trigger path in Ponia/Onia/src/Onia2MuMuRootupler.cc
The crab configs are in Onia/test/crabJobs/

Step 2: Draw plot for the single dataset
root -l runSinglePD.C++

Step 3: Produce data subsets for different triggers
root -l runGetTriggerSubset.C++

Step 4: Draw combined plot
Switch back to ROOT5
root -l DrawPlot.C

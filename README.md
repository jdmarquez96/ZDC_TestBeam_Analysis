# ZDC_TestBeam_Analysis
# Instructions for Running on LxPlus with CMSSW

log on to Lxplus with username and passwork

If using Windows use putty

input

source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc7_amd64_gcc700


get CMSSW by input:
cmsrel CMSSW_10_6_4

cd CMSSW_10_6_4/src

cmsenv

git clone this repository in src directory

create executable by input:

./Make.sh ZDC_ANALYZER.cc

# Running the code

You can run the analyzer via 

./ZDC_ANALYZER output.root input.root

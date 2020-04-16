# ZDC_TestBeam_Analysis
# Instructions for Running on LxPlus with CMSSW

log on to Lxplus with username and password

If using Windows use putty

Git clone respository ( you should first fork repository so you can edit code easily)

set up enviorment via:

. setenv.sh

Make executable via:

./Make.sh ZDC_ANALYZER.cc

# Running the code

You can run the analyzer via 

./ZDC_ANALYZER output.root input.root

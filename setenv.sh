#!/bin/bash
source /cvmfs/cms.cern.ch/cmsset_default.sh export SCRAM_ARCH=slc7_amd64_gcc700

alias cmake='/cvmfs/sft.cern.ch/lcg/contrib/CMake/3.13.4/Linux-x86_64/bin/cmake'

# setup GCC
. /cvmfs/sft.cern.ch/lcg/contrib/gcc/8/x86_64-centos7/setup.sh

# setup ROOT
. /cvmfs/sft.cern.ch/lcg/app/releases/ROOT/6.14.06/x86_64-centos7-gcc48-opt/bin/thisroot.sh

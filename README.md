# P^3 Codes

Maintainer: Jonathan Williams


## Description

This is a collection of codes which may be useful for parsing the particle analysis files outputted by PACE4.

## How to Install

Use 'make' to compile.  Many of the codes require CERN ROOT to be installed (available at https://root.cern.ch/).  Codes that do not depend on ROOT may be compiled using 'make no_root'.  gf3 is recommended for viewing .mca format spectrum files.

To make codes which depend on ROOT, environment variables related to ROOT must be set up properly.  This can be done by adding to your .bashrc (and then reloading the terminal):

```
#ROOT configuration
export ROOTSYS=/path/to/root
export ROOTINC=$ROOTSYS/include
export ROOTLIB=$ROOTSYS/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTLIB
```

Run the codes with no arguments to see a description of the code and a list of required parameters.


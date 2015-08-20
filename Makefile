ROOT = $(shell $(ROOTSYS)/bin/root-config --glibs) -I$(ROOTSYS)/include

all: ESpectrum ESpectrum_gateExi ESpectrum_gateAngle InitialSpin ExiVsInitialSpin
no_root: ESpectrum ESpectrum_gateExi ESpectrum_gateAngle

ESpectrum: ESpectrum.c
	g++ ESpectrum.c -Wall -o2 -o PACE_ESpectrum

ESpectrum_gateExi: ESpectrum_gateExi.c
	g++ ESpectrum_gateExi.c -Wall -o2 -o PACE_ESpectrum_gateExi

ESpectrum_gateAngle: ESpectrum_gateAngle.c
	g++ ESpectrum_gateAngle.c -Wall -o2 -o PACE_ESpectrum_gateAngle

InitialSpin: InitialSpin.c
	g++ InitialSpin.c -Wall -o2 $(ROOT) -o PACE_InitialSpin

ExiVsInitialSpin: ExiVsInitialSpin.c
	g++ ExiVsInitialSpin.c -Wall -o2 $(ROOT) -o PACE_ExiVsInitialSpin

clean:
	rm -rf *~ PACE_*

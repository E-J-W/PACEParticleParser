ROOT = $(shell $(ROOTSYS)/bin/root-config --glibs) -I$(ROOTSYS)/include

all: ESpectrum ESpectrum_gateExi ESpectrum_gateAngle InitialSpin ExiVsInitialSpin DeltaExi_SecondaryParticles DeltaExi_FirstParticle DeltaExi_TwoParticles PopulationStats
no_root: ESpectrum ESpectrum_gateExi ESpectrum_gateAngle DeltaExi_SecondaryParticles DeltaExi_FirstParticle DeltaExi_TwoParticles PopulationStats

ESpectrum: ESpectrum.c
	g++ ESpectrum.c -Wall -o2 -o PACE_ESpectrum

ESpectrum_gateExi: ESpectrum_gateExi.c
	g++ ESpectrum_gateExi.c -Wall -o2 -o PACE_ESpectrum_gateExi

ESpectrum_gateAngle: ESpectrum_gateAngle.c
	g++ ESpectrum_gateAngle.c -Wall -o2 -o PACE_ESpectrum_gateAngle

InitialSpin: InitialSpin.c
	g++ InitialSpin.c -std=c++17 -Wall -o2 $(ROOT) -o PACE_InitialSpin

ExiVsInitialSpin: ExiVsInitialSpin.c
	g++ ExiVsInitialSpin.c -std=c++17 -Wall -o2 $(ROOT) -o PACE_ExiVsInitialSpin

DeltaExi_FirstParticle: DeltaExi_FirstParticle.c
	g++ DeltaExi_FirstParticle.c -Wall -o2 -o PACE_DeltaExi_FirstParticle

DeltaExi_SecondaryParticles: DeltaExi_SecondaryParticles.c
	g++ DeltaExi_SecondaryParticles.c -Wall -o2 -o PACE_DeltaExi_SecondaryParticles

DeltaExi_TwoParticles: DeltaExi_TwoParticles.c
	g++ DeltaExi_TwoParticles.c -Wall -o2 -o PACE_DeltaExi_TwoParticles
	
PopulationStats: PopulationStats.c
	g++ PopulationStats.c -Wall -o2 -o PACE_PopulationStats

clean:
	rm -rf *~ PACE_*

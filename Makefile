all: ESpectrum ESpectrum_gateExi ESpectrum_gateAngle

ESpectrum: ESpectrum.c
	gcc ESpectrum.c -Wall -o2 -o PACE_ESpectrum

ESpectrum_gateExi: ESpectrum_gateExi.c
	gcc ESpectrum_gateExi.c -Wall -o2 -o PACE_ESpectrum_gateExi

ESpectrum_gateAngle: ESpectrum_gateAngle.c
	gcc ESpectrum_gateAngle.c -Wall -o2 -o PACE_ESpectrum_gateAngle

#force_count_wendi: force_count_wendi.c
#	gcc force_count_wendi.c rs232.c wendi_functions.c -Wall -o2 -o force_count_wendi

clean:
	rm -rf *~ PACE_ESpectrum PACE_ESpectrum_gateExi PACE_ESpectrum_gateAngle

CC = gcc
F77 = gfortran
LD = g++

CFLAGS := -g -O2  -march=armv5 -mfp=vfp3
LDFLAGS:= -g -static $(BENCHDIR)/CINT2000/186.crafty/src/*.o\
									$(BENCHDIR)/CINT2000/175.vpr/src/*.o\
									$(BENCHDIR)/CINT2000/181.mcf/src/*.o\
									$(BENCHDIR)/CINT2000/197.parser/src/*.o\
									$(BENCHDIR)/CINT2000/254.gap/src/*.o\
									$(BENCHDIR)/CINT2000/255.vortex/src/*.o\
									$(BENCHDIR)/CINT2000/300.twolf/src/*.o\
									$(BENCHDIR)/CFP2000/171.swim/src/*.o\
									$(BENCHDIR)/CFP2000/168.wupwise/src/*.o\
									$(BENCHDIR)/CFP2000/172.mgrid/src/*.o\
									$(BENCHDIR)/CFP2000/173.applu/src/*.o\
									$(BENCHDIR)/CFP2000/177.mesa/src/*.o\
									$(BENCHDIR)/CFP2000/179.art/src/*.o\
									$(BENCHDIR)/CFP2000/183.equake/src/*.o\
									$(BENCH06DIR)/benchspec/CPU2006/400.perlbench/src/*.o\
									$(BENCH06DIR)/benchspec/CPU2006/401.bzip2/src/*.o\
									$(BENCH06DIR)/benchspec/CPU2006/403.gcc/src/*.o\
									$(BENCH06DIR)/benchspec/CPU2006/410.bwaves/src/*.o\
									$(BENCH06DIR)/benchspec/CPU2006/433.milc/src/*.o\
									$(BENCH06DIR)/benchspec/CPU2006/437.leslie3d/src/*.o\
									$(BENCH06DIR)/benchspec/CPU2006/444.namd/src/*.o\
									$(BENCH06DIR)/benchspec/CPU2006/450.soplex/src/*.o\
									$(BENCH06DIR)/benchspec/CPU2006/453.povray/src/*.o\
									$(BENCH06DIR)/benchspec/CPU2006/462.libquantum/src/*.o\
									$(BENCH06DIR)/benchspec/CPU2006/473.astar/src/*.o\
									$(BENCH06DIR)/benchspec/CPU2006/482.sphinx3/src/*.o\
									$(BENCH06DIR)/benchspec/CPU2006/447.dealII/src/*.o\
									$(PARSECDIR)/pkgs/apps/blackscholes/obj/arm-linux.armelrate/*.o\
									$(PARSECDIR)/pkgs/apps/fluidanimate/obj/arm-linux.armelrate/*.o\
									$(PARSECDIR)/pkgs/apps/swaptions/obj/arm-linux.armelrate/*.o\
									$(PARSECDIR)/pkgs/apps/x264/obj/arm-linux.armelrate/*.o\
									$(PARSECDIR)/pkgs/apps/x264/obj/arm-linux.armelrate/*/*.o\
									$(PARSECDIR)/pkgs/apps/bodytrack/obj/arm-linux.armelrate/*/*.o\
									$(PARSECDIR)/pkgs/apps/bodytrack/obj/arm-linux.armelrate/*/*/*.o\
									$(PARSECDIR)/pkgs/apps/facesim/obj/arm-linux.armelrate/*/*/*/*.o\
									$(PARSECDIR)/pkgs/apps/facesim/obj/arm-linux.armelrate/TaskQ/lib/*.o\
									$(PARSECDIR)/pkgs/apps/ferret/obj/arm-linux.armelrate/parsec/lib/*.a\
									$(PARSECDIR)/pkgs/apps/ferret/obj/arm-linux.armelrate/parsec/obj/*.o\
									$(PARSECDIR)/pkgs/libs/imagick/inst/arm-linux.armelrate/lib/*.a\
									$(PARSECDIR)/pkgs/libs/ssl/inst/arm-linux.armelrate/lib/*.a\
									$(PARSECDIR)/pkgs/libs/zlib/inst/arm-linux.armelrate/lib/*.a\
									$(PARSECDIR)/pkgs/kernels/canneal/obj/arm-linux.armelrate/*.o\
									$(SPLASH2DIR)/codes/apps/ocean/non_contiguous_partitions/*.o\
									$(SPLASH2DIR)/codes/kernels/lu/non_contiguous_blocks/*.o\
									$(SPLASH2DIR)/codes/kernels/fft/*.o\
									$(SPLASH2DIR)/codes/kernels/radix/*.o\
									$(SPLASH2DIR)/codes/apps/fmm/*.o\
									-L$(ARMCUDALIB)/include  
LIBS   := -lrt -lgfortran -lm -lmycudart -lpthread -lgsl -lgslcblas -lstdc++ -ljpeg -lcrypto -lz



all: launcher 

launcher: launcher2.o
	$(LD) $(LDFLAGS) $< $(LIBS) -o $@
#	cp launcher ~/benchsuits

launcher.o: launcher2.c
	$(CC) -O2 -c $< $(CFLAGS) $(LIBS) 

clean:
		-@rm -f launcher 
		-@rm -f *.o


#FILE = basicmath_large.c   rad2deg.c  cubic.c   isqrt.c 
FILE = main.c fftmisc.c  fourierf.c
CC=mipseb-linux-gcc
CFLAGS=-mips2 -mabi=32 -static -Wa,-non_shared -mno-abicalls
LDFLAGS= -static -Wl,--script=/home/sesc/sescutils/src/mint.x
OBJ = $(patsubst %.c,%.o,$(FILE))
all:$(OBJ)
$(OBJ):%.o:%.c
	$(CC) $(CFLAGS) -c  $<
#OBJ = main.o fftmisc.o  fourierf.o
#FILE = main.c fftmisc.c  fourierf.c
#CFLAGS = -static -O3 -g
#
#fft: ${OBJ} Makefile
#	gcc  ${CFLAGS} ${OBJ} -o fft -lm
#fftmisc.o: fftmisc.c
#	gcc ${CFLAGS} -c fftmisc.c
#fourierf.o: fourierf.c
#	gcc ${CFLAGS} -c fourierf.c
#main.o: main.c
#	gcc ${CFLAGS} -c main.c
#
#clean:
#	rm -rf *.o fft output*

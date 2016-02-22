# By default, the code is compiled for a "big endian" machine.
# To compile on a "little endian" machine set the LITTLE_ENDIAN flag.
# To make smaller object code, but run a little slower, don't use UNROLL_LOOPS.
# To use NIST's modified SHA of 7/11/94, define USE_MODIFIED_SHA
#FILE1 =  rad2deg.c  cubic.c   isqrt.c
FILE = sha_driver.c sha.c
CC=mipseb-linux-gcc

#all: basicmath_small basicmath_large
CFLAGS=-mips2 -mabi=32 -static -Wa,-non_shared -mno-abicalls
LDFLAGS= -static -Wl,--script=/home/sesc/sescutils/src/mint.x
OBJ = $(patsubst %.c,%.o,$(FILE))
all:$(OBJ)
#basicmath_small:$(OBJ) basicmath_small.o
#	$(CC)   $(LDFLAGS) $^ -o basicmath_small -lm
$(OBJ):%.o:%.c
	$(CC) $(CFLAGS) -c  $<


#CC = gcc
#CFLAGS = -O3 -Wall
#
#sha:	sha_driver.o sha.o
#	$(CC) -o $@ sha_driver.o sha.o
#	strip $@

clean:
	rm -rf *.o sha output*

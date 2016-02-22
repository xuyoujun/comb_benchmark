FILE = crc_32.c
CC=mipseb-linux-gcc

#all: basicmath_small basicmath_large
CFLAGS=-mips2 -mabi=32 -static -Wa,-non_shared -mno-abicalls
LDFLAGS= -static -Wl,--script=/home/sesc/sescutils/src/mint.x
OBJ = $(patsubst %.c,%.o,$(FILE))
all:$(OBJ)
$(OBJ):%.o:%.c
	$(CC) $(CFLAGS) -c  $<

#crc: crc_32.c Makefile
#	gcc -static crc_32.c -O3 -o crc 

clean:
	rm -rf crc output*  *.o

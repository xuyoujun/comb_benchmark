#FILE1 =  rad2deg.c  cubic.c   isqrt.c
FILE = basicmath_small.c   rad2deg.c  cubic.c   isqrt.c 
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
		 
#basicmath_large: ${OBJ} basicmath_large.o
#	$(CC)  $^ ${LDFLAGS} -o basicmath_large -lm

clean:
	@rm -rf basicmath_small basicmath_large output*  *.o

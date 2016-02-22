FILE = patricia.c patricia_test.c
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

#ipatricia: patricia.c patricia_test.c
#	gcc -static patricia.c patricia_test.c -O3 -o patricia

clean:
	rm -rf patricia output* *.o

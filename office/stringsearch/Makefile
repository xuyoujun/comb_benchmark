FILE := bmhasrch.c  bmhisrch.c  bmhsrch.c  pbmsrch_small.c   pbmsrch_large.c 
CC=mipseb-linux-gcc
CFLAGS=-mips2 -mabi=32 -static -Wa,-non_shared -mno-abicalls
LDFLAGS= -static -Wl,--script=/home/sesc/sescutils/src/mint.x
OBJ = $(patsubst %.c,%.o,$(FILE))
all:$(OBJ)
#basicmath_small:$(OBJ) basicmath_small.o
#	$(CC)   $(LDFLAGS) $^ -o basicmath_small -lm
$(OBJ):%.o:%.c
	$(CC) $(CFLAGS) -c  $<

#all: search_small search_large
#
#search_small: ${FILE1} Makefile
#	gcc -static ${FILE1} -O3 -o search_small
#
#search_large: ${FILE2} Makefile
#	gcc -static ${FILE2} -O3 -o search_large
#
clean:
	rm -rf search_small search_large output*  *.o

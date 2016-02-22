FILE = bitcnt_1.c bitcnt_2.c bitcnt_3.c bitcnt_4.c bitcnts.c bitfiles.c bitstrng.c bstr_i.c 
OBJ=$(patsubst %.c,%.o,$(FILE))
CC = mipseb-linux-gcc
CFLAGS=-mips2 -mabi=32 -static -Wa,-non_shared -mno-abicalls
LDFLAGS= -static -Wl,--script=/home/sesc/sescutils/src/mint.x
all:$(OBJ)
#bitcnts:$(OBJ)
#	$(CC) $(LDFLAGS) ${OBJ} -o bitcnts
$(OBJ):%.o:%.c
	$(CC) $(CFLAGS) -c $< 

clean:
	rm -rf bitcnts output*  *.o

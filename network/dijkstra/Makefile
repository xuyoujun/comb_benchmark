FILE = dijkstra_large.c dijkstra_small.c
CC=mipseb-linux-gcc

#all: basicmath_small basicmath_large
CFLAGS=-mips2 -mabi=32 -static -Wa,-non_shared -mno-abicalls
LDFLAGS= -static -Wl,--script=/home/sesc/sescutils/src/mint.x
OBJ = $(patsubst %.c,%.o,$(FILE))
	
#all:  dijkstra_large dijkstra_small
all:$(OBJ)

$(OBJ):%.o:%.c
	 $(CC) $(CFLAGS) -c $<
#dijkstra_large: dijkstra_large.c Makefile
#	gcc -static dijkstra_large.c -O3 -o dijkstra_large

#dijkstra_small: dijkstra_small.c Makefile
#	gcc -static dijkstra_small.c -O3 -o dijkstra_small 

clean:
	rm -rf dijkstra_large dijkstra_small output*  *.o

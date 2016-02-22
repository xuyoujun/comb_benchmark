cc=mipseb-linux-gcc
CFLAGS=-mips2 -mabi=32 -static -Wa,-non_shared -mno-abicalls -Wl,--script=/home/sesc/sescutils/src/mint.x,-static

hello:hellosesc.c
	${cc} ${CFLAGS} $< -o $@

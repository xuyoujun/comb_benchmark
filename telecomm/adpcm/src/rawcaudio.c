/* testc - Test adpcm coder */

#include "adpcm.h"
#include <stdio.h>
#include <fcntl.h>
struct adpcm_state state;

#define NSAMPLES 1000

char	abuf[NSAMPLES/2];
short	sbuf[NSAMPLES];

int rawcaudio_main(void *p) {
    int n;
    int fd = open("large.pcm", O_RDONLY);
    while(1) {
	n = read(fd, sbuf, NSAMPLES*2);
	if ( n < 0 ) {
	    perror("input file");
	    exit(1);
	}
	if ( n == 0 ) break;
	adpcm_coder(sbuf, abuf, n/2, &state);
	write(1, abuf, n/4);
    }
    fprintf(stderr, "Final valprev=%d, index=%d\n",
	    state.valprev, state.index);
    exit(0);
}

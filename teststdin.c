#include <stdio.h>
  int main(void)
 {
		    /* redirect standard output to a file */
	if(freopen("OUTPUT.FIL", "w", stdout) == NULL)
		fprintf(stderr, "error redirectingstdout\n");
		      /* this output will go to a file */
	printf("This will go into a file.");
		        /* close the standard output stream */
	fclose(stdout);
	return 0;
 }

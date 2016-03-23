
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"sescapi.h"
struct thread_data
{
  int argc;
  char **argv;
  int done;
};


int fft_main(void *);
#define numP 9
int main(int argc, char *argv[]) {
int i,j,k;
struct thread_data ** thread_args = (struct thread_data**)malloc(numP * sizeof(struct thrad_data*));
for(j = 0; j < numP; j++){
	thread_args[j] = (struct thread_data *) malloc(sizeof(struct thread_data));
}

 i =  0 ;
thread_args[i]->argc = 3;
thread_args[i]->argv = (char **)malloc(3*sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[0],0,20);
memcpy(thread_args[i]->argv[0],"fft_mian",20); 
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[1],"8",20); 
thread_args[i]->argv[2] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[2],"32768",20); 


 i =  0 ;
sesc_spawn((void*)fft_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);

}

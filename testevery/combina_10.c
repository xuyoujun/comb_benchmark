
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


int CRC32_main(void *);
#define numP 9
int main(int argc, char *argv[]) {
int i,j,k;
struct thread_data ** thread_args = (struct thread_data**)malloc(numP * sizeof(struct thrad_data*));
for(j = 0; j < numP; j++){
	thread_args[j] = (struct thread_data *) malloc(sizeof(struct thread_data));
}

 i =  0 ;
thread_args[i]->argc = 2;
thread_args[i]->argv = (char **)malloc(2*sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[0],0,20);
memcpy(thread_args[i]->argv[0],"CRC32_mian",20); 
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[1],"large.pcm",20); 


 i =  0 ;
sesc_spawn((void*)CRC32_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);

}

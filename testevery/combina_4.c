
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


int djpeg_main(void *);
#define numP 9
int main(int argc, char *argv[]) {
int i,j,k;
struct thread_data ** thread_args = (struct thread_data**)malloc(numP * sizeof(struct thrad_data*));
for(j = 0; j < numP; j++){
	thread_args[j] = (struct thread_data *) malloc(sizeof(struct thread_data));
}

 i =  0 ;
thread_args[i]->argc = 7;
thread_args[i]->argv = (char **)malloc(7*sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[0],0,20);
memcpy(thread_args[i]->argv[0],"djpeg_mian",20);
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[1],"-dct",20); 
thread_args[i]->argv[2] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[2],"int",20); 
thread_args[i]->argv[3] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[3],"-ppm",20); 
thread_args[i]->argv[4] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[4],"-outfile",20); 
thread_args[i]->argv[5] = (char *)malloc(30 *sizeof(char));
memcpy(thread_args[i]->argv[5],"output_large_encode.jpeg",30); 
thread_args[i]->argv[6] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[6],"input_large.jpg",20); 


 i =  0 ;
sesc_spawn((void*)djpeg_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);

}


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


int basicmath_main(void *);
int bitcount_main(void *);
int cjpeg_main(void *);
int djpeg_main(void *);
int dijkstra_large_main(void *);
int patricia_main(void *);
int sha_main(void *);
int rawdaudio_main(void *);
int rawcaudio_main(void *);
int CRC32_main(void *);
int fft_main(void *);
#define numP 9
int main(int argc, char *argv[]) {
int i,j,k;
struct thread_data ** thread_args = (struct thread_data**)malloc(numP * sizeof(struct thrad_data*));
for(j = 0; j < numP; j++){
	thread_args[j] = (struct thread_data *) malloc(sizeof(struct thread_data));
}

 i =  0 ;
thread_args[i]->argc = 1;
thread_args[i]->argv = (char **)malloc(sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[0],"basicmath_mian",20); 


 i =  1 ;
thread_args[i]->argc = 2;
thread_args[i]->argv = (char **)malloc(2*sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[0],"bitcount_mian",20); 
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[1],"75000",20); 


 i =  2 ;
thread_args[i]->argc = 8;
thread_args[i]->argv = (char **)malloc(8*sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[0],"cjpeg_mian",20) ;
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[1],"-dct",20); 
thread_args[i]->argv[2] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[2],"int",20); 
thread_args[i]->argv[3] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[3],"-progressive",20); 
thread_args[i]->argv[4] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[4],"-opt",20); 
thread_args[i]->argv[5] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[5],"-outfile",20); 
thread_args[i]->argv[6] = (char *)malloc(30 *sizeof(char));
memcpy(thread_args[i]->argv[6],"output_large_encode.jpeg",30); 
thread_args[i]->argv[7] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[7],"input_large.ppm",20); 


i =  3 ;
thread_args[i]->argc = 2;
thread_args[i]->argv = (char **)malloc(2*sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[0],"dijkstra_large_mian",20); 
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[1],"input.dat",20); 
 i =  4 ;
thread_args[i]->argc = 7;
thread_args[i]->argv = (char **)malloc(7*sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
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




 i =  5 ;
thread_args[i]->argc = 2;
thread_args[i]->argv = (char **)malloc(2*sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[0],"patricia_mian",20); 
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));
memcpy(thread_args[i]->argv[1],"large.udp",20); 


// i =  6 ;
//thread_args[i]->argc = 2;
//thread_args[i]->argv = (char **)malloc(2*sizeof(char *));
//thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
//memcpy(thread_args[i]->argv[0],"sha_mian",20); 
//thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));
//memcpy(thread_args[i]->argv[1],"input_large.asc",20); 


// i =  7 ;
//thread_args[i]->argc = 1;
//thread_args[i]->argv = (char **)malloc(2*sizeof(char *));
//thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
//memcpy(thread_args[i]->argv[0],"rawcaudio_mian",20); 


 i =  0 ;
sesc_spawn((void*)basicmath_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);

 i =  1 ;
sesc_spawn((void*)bitcount_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);

 i =  2 ;
sesc_spawn((void*)cjpeg_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);
 i =  3 ;
sesc_spawn((void*)dijkstra_large_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);

 i =  4 ;
sesc_spawn((void*)djpeg_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);


// i =  5 ;
//sesc_spawn((void*)patricia_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);

// i =  6 ;
//sesc_spawn((void*)sha_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);

// i =  7 ;
//sesc_spawn((void*)rawcaudio_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);

}

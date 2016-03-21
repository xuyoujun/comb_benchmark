
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
int patricia_main(void *);
int sha_main(void *);
int rawdaudio_main(void *);
int rawcaudio_main(void *);
int CRC32_main(void *);
int fft_main(void *);
int fft_main(void *);
#define numP 9
int main(int argc, char *argv[]) {
int i,j,k;
struct thread_data ** thread_args = (struct thread_data**)malloc(numP * sizeof(struct thrad_data*));
for(j = 0; j < numP; j++){
	thread_args[j] = (struct thread_data *) malloc(sizeof(struct thread_data));
}

 i =  0 ;
thread_args[i]->argc = 4;
thread_args[i]->argv = (char **)malloc(4*sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[0],0,20);
memcpy(thread_args[i]->argv[0],"fft_mian",8); 
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[1],0,20);
memcpy(thread_args[i]->argv[1],"8",1); 
thread_args[i]->argv[2] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[2],0,20);
memcpy(thread_args[i]->argv[2],"32768",5); 
thread_args[i]->argv[3] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[3],0,20);
memcpy(thread_args[i]->argv[3],"-i",2); 


 i =  1 ;
thread_args[i]->argc = 3;
thread_args[i]->argv = (char **)malloc(3*sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[0],0,20);
memcpy(thread_args[i]->argv[0],"fft_mian",8); 
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[1],0,20);
memcpy(thread_args[i]->argv[1],"8",1); 
thread_args[i]->argv[2] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[2],0,20);
memcpy(thread_args[i]->argv[2],"32768",5); 


 i =  2 ;
thread_args[i]->argc = 2;
thread_args[i]->argv = (char **)malloc(2*sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[0],0,20);
memcpy(thread_args[i]->argv[0],"CRC32_mian",10); 
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[1],0,20);
memcpy(thread_args[i]->argv[1],"large.pcm",9); 


 i =  3 ;
thread_args[i]->argc = 2;
thread_args[i]->argv = (char **)malloc(2*sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[0],0,20);
memcpy(thread_args[i]->argv[0],"patricia_mian",13); 
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[1],0,20);
memcpy(thread_args[i]->argv[1],"large.udp",10); 


 i =  4;
thread_args[i]->argc = 1;
thread_args[i]->argv = (char **)malloc(2*sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[0],0,20);
memcpy(thread_args[i]->argv[0],"rawcaudio_mian",14); 


 i =  5 ;
thread_args[i]->argc = 1;
thread_args[i]->argv = (char **)malloc(sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[0],0,20);
memcpy(thread_args[i]->argv[0],"rawdaudio_mian",14); 


 i =  6 ;
thread_args[i]->argc = 2;
thread_args[i]->argv = (char **)malloc(2*sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[0],0,20);
memcpy(thread_args[i]->argv[0],"sha_mian",8); 
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[1],0,20);
memcpy(thread_args[i]->argv[1],"input_large.asc",15); 


 i =  7 ;
thread_args[i]->argc = 1;
thread_args[i]->argv = (char **)malloc(sizeof(char *));
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));
memset(thread_args[i]->argv[0],0,20);
memcpy(thread_args[i]->argv[0],"basicmath_mian",sizeof("basicmath_mian")); 




 i =  0 ;
sesc_spawn((void*)fft_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);

 i =  1 ;
sesc_spawn((void*)fft_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);

 i =  2 ;
sesc_spawn((void*)CRC32_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);

 i =  3 ;
sesc_spawn((void*)patricia_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);
 i =  4 ;
sesc_spawn((void*)rawcaudio_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);

 i =  5 ;
sesc_spawn((void*)rawdaudio_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);

 i =  6 ;
sesc_spawn((void*)sha_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);

 i =  7 ;
sesc_spawn((void*)basicmath_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);



}

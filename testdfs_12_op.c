#include <stdio.h>
#include <stdlib.h>
//#include <file.h>
#include <string.h>
int myindex = 0;
char name[32];
//int k;
char *headPragram;
char *funcdeclare[12] = {
"int rawcaudio_main(void *);",
"int rawdaudio_main(void *);",
"int sha_main(void *);",
"int basicmath_main(void *);",
"int fft_main(void *);",
"int fft_main(void *);",
"int CRC32_main(void *);",
"int patricia_main(void *);",
"int cjpeg_main(void *);",
"int djpeg_main(void *);",
"int bitcount_main(void *);",
"int dijkstra_large_main(void *);",
};

char *main_head ;

char *thread_args[12] = {
"thread_args[i]->argc = 1;\n\
thread_args[i]->argv = (char **)malloc(2*sizeof(char *));\n\
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[0],0,20);\n\
memcpy(thread_args[i]->argv[0],\"rawcaudio_mian\",14); \n\
",
"thread_args[i]->argc = 1;\n\
thread_args[i]->argv = (char **)malloc(sizeof(char *));\n\
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[0],0,20);\n\
memcpy(thread_args[i]->argv[0],\"rawdaudio_mian\",14); \n\
",
"thread_args[i]->argc = 2;\n\
thread_args[i]->argv = (char **)malloc(2*sizeof(char *));\n\
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[0],0,20);\n\
memcpy(thread_args[i]->argv[0],\"sha_mian\",8); \n\
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[1],0,20);\n\
memcpy(thread_args[i]->argv[1],\"input_large.asc\",15); \n\
",
"thread_args[i]->argc = 1;\n\
thread_args[i]->argv = (char **)malloc(sizeof(char *));\n\
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[0],0,20);\n\
memcpy(thread_args[i]->argv[0],\"basicmath_mian\",sizeof(\"basicmath_mian\")); \n\
",
"thread_args[i]->argc = 4;\n\
thread_args[i]->argv = (char **)malloc(4*sizeof(char *));\n\
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[0],0,20);\n\
memcpy(thread_args[i]->argv[0],\"fft_mian\",8); \n\
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[1],0,20);\n\
memcpy(thread_args[i]->argv[1],\"8\",1); \n\
thread_args[i]->argv[2] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[2],0,20);\n\
memcpy(thread_args[i]->argv[2],\"32768\",5); \n\
thread_args[i]->argv[3] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[3],0,20);\n\
memcpy(thread_args[i]->argv[3],\"-i\",2); \n\
",
"thread_args[i]->argc = 3;\n\
thread_args[i]->argv = (char **)malloc(3*sizeof(char *));\n\
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[0],0,20);\n\
memcpy(thread_args[i]->argv[0],\"fft_mian\",8); \n\
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[1],0,20);\n\
memcpy(thread_args[i]->argv[1],\"8\",1); \n\
thread_args[i]->argv[2] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[2],0,20);\n\
memcpy(thread_args[i]->argv[2],\"32768\",5); \n\
",
"thread_args[i]->argc = 2;\n\
thread_args[i]->argv = (char **)malloc(2*sizeof(char *));\n\
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[0],0,20);\n\
memcpy(thread_args[i]->argv[0],\"CRC32_mian\",10); \n\
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[1],0,20);\n\
memcpy(thread_args[i]->argv[1],\"large.pcm\",9); \n\
",
"thread_args[i]->argc = 2;\n\
thread_args[i]->argv = (char **)malloc(2*sizeof(char *));\n\
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[0],0,20);\n\
memcpy(thread_args[i]->argv[0],\"patricia_mian\",13); \n\
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[1],0,20);\n\
memcpy(thread_args[i]->argv[1],\"large.udp\",10); \n\
",
"thread_args[i]->argc = 8;\n\
thread_args[i]->argv = (char **)malloc(8*sizeof(char *));\n\
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[0],0,20);\n\
memcpy(thread_args[i]->argv[0],\"cjpeg_mian\",10) ;\n\
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[1],0,20);\n\
memcpy(thread_args[i]->argv[1],\"-dct\",4); \n\
thread_args[i]->argv[2] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[2],0,20);\n\
memcpy(thread_args[i]->argv[2],\"int\",3); \n\
thread_args[i]->argv[3] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[3],0,20);\n\
memcpy(thread_args[i]->argv[3],\"-progressive\",12); \n\
thread_args[i]->argv[4] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[4],0,20);\n\
memcpy(thread_args[i]->argv[4],\"-opt\",4); \n\
thread_args[i]->argv[5] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[5],0,20);\n\
memcpy(thread_args[i]->argv[5],\"-outfile\",8); \n\
thread_args[i]->argv[6] = (char *)malloc(30 *sizeof(char));\n\
memset(thread_args[i]->argv[6],0,30);\n\
memcpy(thread_args[i]->argv[6],\"output_large_encode.jpeg\",24); \n\
thread_args[i]->argv[7] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[7],0,20);\n\
memcpy(thread_args[i]->argv[7],\"input_large.ppm\",15); \n\
",
"thread_args[i]->argc = 7;\n\
thread_args[i]->argv = (char **)malloc(7*sizeof(char *));\n\
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[0],0,20);\n\
memcpy(thread_args[i]->argv[0],\"djpeg_mian\",10);\n\
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[1],0,20);\n\
memcpy(thread_args[i]->argv[1],\"-dct\",4); \n\
thread_args[i]->argv[2] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[2],0,20);\n\
memcpy(thread_args[i]->argv[2],\"int\",3); \n\
thread_args[i]->argv[3] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[3],0,20);\n\
memcpy(thread_args[i]->argv[3],\"-ppm\",4); \n\
thread_args[i]->argv[4] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[4],0,20);\n\
memcpy(thread_args[i]->argv[4],\"-outfile\",8); \n\
thread_args[i]->argv[5] = (char *)malloc(30 *sizeof(char));\n\
memset(thread_args[i]->argv[5],0,30);\n\
memcpy(thread_args[i]->argv[5],\"output_large_encode.jpeg\",24); \n\
thread_args[i]->argv[6] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[6],0,20);\n\
memcpy(thread_args[i]->argv[6],\"input_large.jpg\",15); \n\
",
"thread_args[i]->argc = 2;\n\
thread_args[i]->argv = (char **)malloc(2*sizeof(char *));\n\
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[0],0,20);\n\
memcpy(thread_args[i]->argv[0],\"dijkstra_mian\",19); \n\
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[1],0,20);\n\
memcpy(thread_args[i]->argv[1],\"input.dat\",9); \n\
",
"thread_args[i]->argc = 2;\n\
thread_args[i]->argv = (char **)malloc(2*sizeof(char *));\n\
thread_args[i]->argv[0] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[0],0,20);\n\
memcpy(thread_args[i]->argv[0],\"bitcount_mian\",13); \n\
thread_args[i]->argv[1] = (char *)malloc(20 *sizeof(char));\n\
memset(thread_args[i]->argv[1],0,20);\n\
memcpy(thread_args[i]->argv[1],\"75000\",5); \n\
",
};
char * threads[12] = {
 "sesc_spawn((void*)rawcaudio_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);",
 "sesc_spawn((void*)rawdaudio_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);",
 "sesc_spawn((void*)sha_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);",
 "sesc_spawn((void*)basicmath_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);",
 "sesc_spawn((void*)fft_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);",
 "sesc_spawn((void*)fft_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);",
 "sesc_spawn((void*)CRC32_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);",
 "sesc_spawn((void*)patricia_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);",
 "sesc_spawn((void*)cjpeg_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);",
 "sesc_spawn((void*)djpeg_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);",
 "sesc_spawn((void*)dijkstra_large_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);",
 "sesc_spawn((void*)bitcount_main,(void *)thread_args[i],SESC_FLAG_MAP| i + 1);",
};
void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void dfs(char **A,int B[],int C[],int counter ,int start, int end){
	int i;
	int k;
	if(counter == 8){
		memset(name,0,32 * sizeof(char));
	//	myindex++;
	        k= sprintf(name,"%s","combina_");//itoa(++myindex,suffix,10);
		k += sprintf(name+k,"%d",++myindex);
	        k = sprintf(name + k, "%s",".c");	
		FILE *fd = fopen(name,"w");
//		printf("%s\n",name);
		fprintf(fd,"\n%s\n",headPragram);
		for(i = 0; i < 12; i++){
			fprintf(fd,"\n%s",funcdeclare[i]);
		}
		fprintf(fd,"\n%s\n",main_head);
		

		for( i = 7; i >= 0 ; i--){
			fprintf(fd,"\n %s %d %s","i = ",7 - i,";");
			fprintf(fd,"\n%s\n",thread_args[B[i]]);
			//printf("%s ",A[B[i]]);
		}
		for(i = 7 ; i >= 0; i--){
			fprintf(fd,"\n %s %d %s","i = ",7 - i,";");
			fprintf(fd,"\n%s\n",threads[B[i]]);
		
		}
		fprintf(fd,"\n%s","}\n"); 
		fclose(fd);
		return;
	}
	else{
		for( i = start; i < end; i++){
		//	swap(C+ start,C+i);
			B[counter ++] = i;
			dfs(A,B,C,counter,i+1,end);
			counter--;
		//	swap(C+ start,C+i);
		}
	}
}

int main(){
headPragram =
"#include <unistd.h>\n\
#include <stdio.h>\n\
#include <stdlib.h>\n\
#include <string.h>\n\
#include\"sescapi.h\"\n\
struct thread_data\n\
{\n\
  int argc;\n\
  char **argv;\n\
  int done;\n\
};\n";
main_head = "#define numP 9\n\
int main(int argc, char *argv[]) {\n\
int i,j,k;\n\
struct thread_data ** thread_args = (struct thread_data**)malloc(numP * sizeof(struct thrad_data*));\n\
for(j = 0; j < numP; j++){\n\
	thread_args[j] = (struct thread_data *) malloc(sizeof(struct thread_data));\n\
}";



	char *A[13] = {"basicmath","bitcount","cjpeg","djpeg","dijkstra","patricia","stringsearch","sha","rawcaudio","rawdaudio","CRC32","FFT","FFTI"};
	int B[13];
        int C[13] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
	dfs(A,B,C,0,0,12);
//	printf("myindex = %d\n",myindex);
	return 0;
}

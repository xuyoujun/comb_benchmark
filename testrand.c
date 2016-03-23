#include <stdio.h>

#include <stdlib.h>


int main(){
	int  upper = 495;
	int  A[100];
	int i , j ,k = 0;
	i = 0;
	srand((unsigned int)time(0));
	int temp;
	while(i <= 100){
		temp = 1 + rand()%495;
		for(j = 0 ; j < i; j++){
			if(A[j] == temp) k++;
		}
		if(k == 0){
			A[i++] = temp;
		}
		k = 0;
	}

	FILE *fp;
	fp = fopen("rand.txt","w");
	for(i = 0 ; i < 100;i++)
		fprintf(fp,"%s%d  ","combina_",A[i]);



}

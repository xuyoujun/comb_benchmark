#include <stdio.h>
#include <stdlib.h>


int main(){
	
	char *str = "'combina_Tot_";
	FILE *fp = fopen("For_Matlab.txt","w");
	int i;
	for(i = 0; i < 400; i++){
		fprintf(fp,"%s",str);	
		fprintf(fp,"%d",i + 1);	
		fprintf(fp,"%s",".txt'");	
		fprintf(fp,"%s",",");
		if( (i + 1)%8 == 0){
			fprintf(fp,"%s","...");	
			fprintf(fp,"%c",'\n');	
		}	
	
	}
	close(fp);

	return 0;
}

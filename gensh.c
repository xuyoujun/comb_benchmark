#include<stdio.h>

#include <stdlib.h>


int main()
{
	int i;
	char *str1 = "./sesc.mem  -ccombina.conf -w100000  combina_";
	char *str2 =" mv out.txt combina_out_";
	char *str3 =" mv outTot.txt combina_Tot_";
	char *str4 =  "echo \"************************combina_";

	FILE * fp = fopen("run_combina.sh","w");
	for(i = 400; i <= 500;i++){
		fprintf(fp,"%s",str1);
		fprintf(fp,"%d",i);
		fprintf(fp,"%s\n"," > output.txt");
		fprintf(fp,"%s",str2);
		fprintf(fp,"%d%s\n",i,".txt");
		fprintf(fp,"%s",str3);
		fprintf(fp,"%d%s\n",i,".txt");
		fprintf(fp,"%s",str4);
		fprintf(fp,"%d%s\n",i,"\"");
		fprintf(fp,"\n");

		
	}

	return 0;
}

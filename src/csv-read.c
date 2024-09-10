#include <Fecs/csv/read.h>
#include <stdio.h>

void csvReadFile(list* csv,char* path)
{
	FILE* fp;
	if(!(fp=fopen(path,"r"))){
		printf("ERROR: Can't Open File\n");
	}
	char c = 48;
	while((c = fgetc(fp))<0){
		printf("%c -",c);
	}
	printf("%c -",c);
}
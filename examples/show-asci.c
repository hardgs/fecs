#include <stdio.h>
#include <string.h>

int convertStrtoInt(char* str)
{
	int result = 0;
	int size = strlen(str)-3;
	int num = 1;
	for(int i=0;i<=size;i++){
		for(int j=1;j<=(size-i);j++)
			num = num * 10;
		result = result + ((str[i]-48)*num);
		num = 1;
	}
	return result;
}
int main()
{
	char c = -1;
	printf("Int: %d, String: %s\n",convertStrtoInt("8989"),"8989");
	for(int i=0;i<=255/5;i++){
		for(int j=0;j<5;j++){
			c+=1;
			printf(" %c : %d ",c,c);
		}
		printf("\n");
	}
	return 0;
}
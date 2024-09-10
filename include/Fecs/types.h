#ifndef FECS_TYPES_H
#define FECS_TYPES_H

#include <string.h>

/* Convert Int String To Int */
int strToInt(char* str)
{
	int result = 0;
	int size = strlen(str)-1;
	int num = 1;
	for(int i=0;i<=size;i++){
		for(int j=1;j<=(size-i);j++)
			num = num * 10;
		result = result + ((str[i]-48)*num);
		num = 1;
	}
	return result;
}
#endif
#ifndef FECS_POINTER_H
#define FECS_POINTER_H

static inline int* newInt(int i)
{
	int* tmp = malloc(sizeof(int));
	*tmp = i;
	return tmp;
}
static inline float* newFloat(float i)
{
	float* tmp = malloc(sizeof(float));
	*tmp = i;
	return tmp;
}
static inline double* newDouble(double i)
{
	double* tmp = malloc(sizeof(double));
	*tmp = i;
	return tmp;
}
static inline char* newChar(char i)
{
	char* tmp = malloc(sizeof(char));
	*tmp = i;
	return tmp;
}
static inline char* newString(char* i)
{
	char* tmp = malloc(strlen(i));
	strcpy(tmp,i);
	return tmp;
}

#endif
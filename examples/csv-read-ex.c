#include <Fecs/csv/read.h>
#include <conio.h>

int main()
{
	list table;
	csvReadFile(&table,"basic.csv");
	getch();
	return 0;
}
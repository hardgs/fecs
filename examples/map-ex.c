#include <stdio.h>
#include <Fecs/list.h>
#include <Fecs/map.h>
#include <conio.h>

int main(){
	map aiMemory;
	initMap(&aiMemory);
	char* key = "gold";
	char* value = "Apple";
	char* key2 = "line";
	char* value2 = "gogo"; 
	addKeyValue(&aiMemory,key,value);
	//addKeyValue(&aiMemory,key2,value2);
	setKey(&aiMemory,key,value);
	printf("%s \n",value);
	printf("%s Is \"gold\" Key Value\n",(char*)getKey(&aiMemory,value));
	printf("%s Is Key\n",(char*)getKeyByValue(&aiMemory,value));
	
	getch();
	return 0;
}
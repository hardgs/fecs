/*
  * Writed by Hardgs
  * My Page In Github: www.github.com/hardgs
  * Fast Easy C STL.
*/
#ifndef FECS_MAP_H
#define FECS_MAP_H

#include <stdlib.h>
#include <Fecs/list.h>

// Variables
struct map
{
	list keys;
	list values;
};
typedef struct map map;

// Methods

/*
	* Init Map 
*/
void initMap(map* target);
/*
	* Add Key And Value To Map
*/
void addKeyValue(map* target,void* key,void* value);
/*
	* Delete A Key With Value
*/
void deleteKey(map* target,void* key);
/*
	* Get All Keys: Return List
*/
list getKeys(map* target);
/*
	* Get All Values: Return List
*/
list getValues(map* target);
/*
	* Get Value By Key
*/
void* getKey(map* target,void* key);
/*
	* Get Key By Value
*/
void* getKeyByValue(map* target,void* value);
/*
	* Set Key Name
*/
void setKey(map* target,void* key,void* new_key);
/*
	* Set Value By Key
*/
void setValue(map* target,void* key,void* value);

#endif
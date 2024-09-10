#include <Fecs/map.h>
#include <Fecs/list.h>


/*
	* Init Map 
*/
void initMap(map* target)
{
	initList(&target->keys);
	initList(&target->values);
}
/*
	* Add Key And Value To Map
*/
void addKeyValue(map* target,void* key,void* value)
{
	// Add Key
	node* temp = (node*)malloc(sizeof(node));
	temp->value = key;
	addItem(&target->keys,temp);
	
	// Reset Temp And Add Value
	temp = (node*)malloc(sizeof(node));
	temp->value = value;
	addItem(&target->values,temp);
}
/*
	* Delete A Key With Value
*/
void deleteKey(map* target,void* key)
{
	int index = getIndexByItemValue(&target->keys,key);
	deleteItemByIndex(&target->keys,index);
	deleteItemByIndex(&target->values,index);
}
/*
	* Get All Keys: Return List
*/
list getKeys(map* target)
{
	return target->keys;
}
/*
	* Get All Values: Return List
*/
list getValues(map* target)
{
	return target->values;
}
/*
	* Get Value By Key
*/
void* getKey(map* target,void* key)
{
	int index = getIndexByItemValue(&target->keys,key);
	return getItemByIndex(&target->values,index)->value;
}
/*
	* Get Key By Value
*/
void* getKeyByValue(map* target,void* value)
{
	int index = getIndexByItemValue(&target->values,value);
	return getItemByIndex(&target->keys,index)->value;
}
/*
	* Set Key Name
*/
void setKey(map* target,void* key,void* new_key)
{
	setItemValueByIndex(&target->keys,getIndexByItemValue(&target->keys,key),new_key);
	return;
}
/*
	* Set Value By Key
*/
void setValue(map* target,void* key,void* new_value)
{
	setItemValueByIndex(&target->values,getIndexByItemValue(&target->keys,key),new_value);
	return;
}

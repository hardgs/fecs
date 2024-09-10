#include <stddef.h>
#include <stdlib.h>
#include <Fecs/list.h>
#include <stdio.h>

/*
	* i can optimized Better With Set "end list" with ->next
	* I new Update. :)
*/
// Methods
/*
	* Initing List For Work
*/
void initList(list* target)
{
	target->first = NULL;
	target->last = NULL;
}
/*
	* Add Item To List
*/
void addItem(list* target,node* item)
{
	if(target->first==NULL){
		target->first = target->last = item;
	}else{
		target->last->next = item;
		target->last = item;
	}
	item->next = NULL;
}
/*
	* Get Index By Item
	* Index Started Form Zero (0)
*/
int getIndexByItem(list* target,node* item)
{
	node* temp = target->first;
	// First Make A For Loop For List
	for(int i=0;i<getSizeList(target);i++){
		if(temp==item){
			return i;
		}
		temp = temp->next;
	}
}
/*
	* Get Index by Item Value
*/
int getIndexByItemValue(list* target,void* value)
{
	node* temp = target->first;
	// First Make A For Loop For List
	for(int i=0;i<getSizeList(target);i++){
		if(temp->value==value){
			return i;
		}
		temp = temp->next;
	}
}

/*
	* Get Item By Index 
	* Index Started From Zero (0)
*/
node* getItemByIndex(list* target,int index)
{
	if(index == 0){
		return target->first;
	}else{
		node* temp = target->first;
		for(int i=0;i<index;i++){
			temp = temp->next;
		}
		return temp;
	}
}
/*
	* Delete Item By Index
	* Index Started From Zero (0)
*/
void deleteItemByIndex(list* target,int index)
{
	node* prev = getItemByIndex(target,index-1);
	node* def = getItemByIndex(target,index);
	if(def==target->last && def!=target->first){
		target->last = prev;
	}
	else if(def==target->first && def==target->last){
		target->first = target->last = NULL;
	}
	else if(def==target->first && def!=target->last){
		target->first = def->next;
	}
	else{
		prev->next = def->next;
	}
	//free(def);
}
/*
	* Delete Item By self
*/
void deleteItem(list* target,node* item)
{
	deleteItemByIndex(target,getIndexByItem(target,item));
}
/*
	* Get Size Of List
*/
int getSizeList(list* target)
{
	if(target->first==NULL){
		return 0;
	}else{
		int i=1;
		node* temp = target->first;
		while(temp != target->last){
			i++;
			temp = temp->next;
		}
		return i;
	}
}
/*
	* Set Item Value By Key
*/
void setItemValueByIndex(list* target,int index,void* value)
{
	node* temp = target->first;
	int i=0;
	while(temp->next!=NULL){
		temp = temp->next;
		i++;
		if(i==index){
			temp->value = value;
			return;
		}
	}
	temp->value = value;
}


// These Methods For Easy Access And Use.
node* newNodeInt(int i)
{
	node* temp = (node*)malloc(sizeof(node));
	int* data = (int*)malloc(sizeof(int));
	*data = i;
	temp->value = data;
	return temp;
}
node* newNodeChars(char* str)
{
	node* temp = (node*)malloc(sizeof(node));
	char** data = (char**)malloc(sizeof(char)*sizeof(str));
	*data = str;
	temp->value = data;
	return temp;
}

node* newNodeFloat(float f)
{
	node* temp = (node*)malloc(sizeof(node));
	float* data = (float*)malloc(sizeof(float));
	*data = f;
	temp->value = data;
	return temp;
}

node* newNodeDouble(double d)
{
	node* temp = (node*)malloc(sizeof(node));
	double* data = (double*)malloc(sizeof(double));
	*data = d;
	temp->value = data;
	return temp;
}

node* newNodeChar(char c)
{
	node* temp = (node*)malloc(sizeof(node));
	char* data = (char*)malloc(sizeof(char));
	*data = c;
	temp->value = data;
	return temp;
}
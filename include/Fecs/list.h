/*
  * Writed by Hardgs
  * My Page In Github: www.github.com/hardgs
  * Fast Easy C STL.
*/
#ifndef FECS_LIST_H
#define FECS_LIST_H

// Variables
struct node
{
	void* value;
	struct node* next;
};
struct list
{
	struct node* first;
	struct node* last;
};
typedef struct node node;
typedef struct list list;

// Methods
/*
	* Initing List For Work
*/
void initList(list* target);
/*
	* Add Item To List
*/
void addItem(list* target,node* item);
/*
	* Get Index By Item
*/
int getIndexByItem(list* target,node* item);

/*
	* Get Index by Item Value
*/
int getIndexByItemValue(list* target,void* value);
/*
	* Get Item By Index 
*/
node* getItemByIndex(list* target,int index);
/*
	* Delete Item By Index
*/
void deleteItemByIndex(list* target,int index);
/*
	* Delete Item By self
*/
void deleteItem(list* target,node* item);
/*
	* Get Size Of List
*/
int getSizeList(list* target);
/*
	* Set Item Value By Key
*/
void setItemValueByIndex(list* target,int index,void* value);


// These Methods For Easy Use.
node* newNodeInt(int i);
node* newNodeChars(char* str);
node* newNodeFloat(float f);
node* newNodeDouble(double d);
node* newNodeChar(char c);
#endif
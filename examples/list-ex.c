#include <Fecs/list.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int chose = 8;
	int number=3;
	int* input;
	list nList;
	node inode;
	initList(&nList);
	inode.value = &number;
	addItem(&nList,&inode);
	deleteItem(&nList,&inode);
	while(1){
		node* item = (node*)malloc(sizeof(node));
		input = (int*)malloc(sizeof(int));
		// Print Titles
		printf("[1]: Add [2]: Show [3]: Delete [4]: Exit\n");
		printf("[?]: ");
		scanf("%d",&chose);
		
		switch(chose){
			case 1:scanf("%d",input);/*item->value = input*/;addItem(&nList,newNodeInt(*input));break;
			case 2:
				printf("Size: %d\n",getSizeList(&nList));
				node* temp = nList.first;
				for(int i=0;i<getSizeList(&nList);i++){
					printf("%d\n",*(int*)temp->value);
					temp = temp->next;
				}
				break;
			case 3:
				scanf("%d",input);
				deleteItemByIndex(&nList,*input);
				break;
			case 4:return 0;break;
		}
		
	}
	return 0;
}
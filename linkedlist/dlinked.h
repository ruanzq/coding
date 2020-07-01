#include<stdio.h>
#include<stdlib.h>
typedef struct l{
	int value;
	struct l * up;
	struct l * down;
}list;

int len(list * head);

list * init(void);

list * _create(int value);

list * get(list * head,int value);

int insert(list * head,int index,int value);

list * rm(list * head,int index);

void travel(list * head);

int len(list * head){
	return head->value;
}

list * init(void){
	printf("file name : dlinked\n");
	return _create(0);
}

list * _create(int value){
	list * newItem = (list *)malloc(sizeof(list));
	newItem->down = NULL;
	newItem->up = NULL;
	newItem->value = value;
	return newItem;
}

list * get(list * head,int index){
	int step = -1;
	list * cur = NULL;
	while(head){
		if(index == step){
			cur = head;
			break;
		}else{
			step++;
			head = head->down;
		}
	}
	return cur;
}

int insert(list * head,int index,int value){
	if(index >= 0 && index <= len(head)){
		list * before = get(head,index-1);
		list * newItem = _create(value);
		newItem->down = before->down;
		newItem->up = before;
		before->down = newItem;
		if(newItem->down){
			newItem->down->up = newItem;
		}
		head->value++;
	}
	return len(head);
}

list * rm(list * head,int index){
	if(index >=0 && index < len(head)){
		list * cur = get(head,index);
		list * before = cur->up;
		before->down = cur->down;
		if(cur->down){
			cur->down->up = before;
		}
		head->value--;
		return cur;
	}
	return NULL;
}
void travel(list * head){
	while(head->down){
		head = head->down;
		printf("%d,",head->value);
	}
	printf("\n");
}

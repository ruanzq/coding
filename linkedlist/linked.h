/*
 * List int-based
 * Singly linked list
 * Author : ruanzq
 * Email : 954542623@qq.com
 * */
#include<stdio.h>
#include<stdlib.h>
typedef struct l{
	int value;
	struct l * tail;
}list;

// Base functions
int len(list * head);

list * init(void);

list * create(int value);

list * get(list * head,int index);

int insert(list * head,int index,int value);

list * rm(list * head,int index);

void travel(list *);

// Extended stack functions
list * pop(list * head);

int push(list * head);

// Extended queue functions
int in(list * head);

list * out(list * head);

void travel(list * head){
	while(head->tail){
		head = head->tail;
		printf("%d,",head->value);
	}
	printf("\n");
}
int len(list * head){
	return head->value;
}

list * init(void){
	printf("file name linked\n");
	return create(0);
}

list * create(int value){
	list * newItem = (list *)malloc(sizeof(list));
	newItem->value = value;
	newItem->tail = NULL;
	return newItem;
}

list * get(list * head,int index){
	int step = -1;
	list * returnItem = NULL;
	while(head){
		if(index == step){
			returnItem = head;
			break;
		}else{
			head = head->tail;
			step++;
		}
	}
	return returnItem;
}

int insert(list * head,int index,int value){
	if(index >=0 && index <= len(head)){
		list * before = get(head,index-1);
		list * cur = create(value);
		cur->tail = before->tail;
		before->tail = cur;
		head->value++;
	}
	return len(head);
}

list * rm(list * head,int index){
	list * cur = NULL;
	if(index >= 0 && index < len(head)){
		list * before = get(head,index-1);
		cur = before->tail;
		before->tail = cur->tail;
		head->value--;
	}
	return cur;
}

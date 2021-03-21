/*
* 基于单向链表的数组
* @Author:ruanzq
* @Github:https://github.com/ruanzq/
* @Date:2021年3月21日
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct l{
	int value;
	struct l * tail;
}list;

// Base functions
int len(list * head);

// 初始化链表，返回头节点
list * init(void);

// 创建一个新节点
list * create(int value);

// 返回索引位置的节点或null
list * get(list * head,int index);

// 在索引位置插入一个值为value的新元素
int insert(list * head,int index,int value);

// 移除索引位置的节点并返回
list * rm(list * head,int index);

// 遍历链表输出存放的数据
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
	printf("initialize\n");
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

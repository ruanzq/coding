#include <stdio.h>
#include <stdlib.h>

typedef struct nodes{
	struct nodes * next;
	struct nodes * pre;
	int data;
}node;

int count(node * head);

node * create_node(int value);

node * get(node * head,int index);

node * find(node * head,int value);

//基础函数移除节点 element，成功则返回0
int _remove_node(node * n);

//移除索引处的节点，成功则返回0
int remove_by_index(node * head,int index);

//移除第一个值为vlaue的节点，成功则返回0
int remove_by_value(node * head,int value);

int insert(node * head,int index,int value);

void traversal(node * head);

int count(node * head){
	int i = 0;
	for(;head->next;i++)
		head = head->next;
	return i;
}

node * create_node(int value){
	node * newNode = (node *)malloc(sizeof(newNode));
	newNode->next = NULL;
	newNode->pre = NULL;
	newNode->data = value;
	return newNode;
}

node * get(node * head,int index){
	node * result = NULL;
	for(int count = -1;count <= index && head != NULL;count++){
		if(count == index){
			result = head;
			break;
		}
		head = head->next;
	}
	return result;
}

node * find(node * head,int value){
	node * result = NULL;
	while(head->next){
		head = head->next;
		if(head->data == value){
			result = head;
			break;
		}
	}
	return result;
}

int insert(node * head,int index,int value){
	int  status = -1;
	node * before = get(head,index-1);
	node * newNode = create_node(value);

	if(before && newNode){
		newNode->next = before->next;
		newNode->pre = before;
		before->next = newNode;
		if(newNode->next){
			newNode->next->pre = newNode;
		}
		status = 0;
	}
	return status;	
}
int _remove_node(node * before){
	int status = -1;
	if(before && before->next){
		node * t = before->next;
		before->next = t->next;
		if(t->next){
			t->next->pre = before;
		}
		free(t);
		status = 0;
	}
	return status;
}

int remove_by_index(node * head,int index){
	node * n = get(head,index-1);
	return _remove_node(n);
}

int remove_by_value(node * head,int value){
	int status = -1;
	while(head->next){
		head = head->next;
		if(head->data == value){
			status = _remove_node(head);
			break;
		}
	}
	return status;
}
void traversal(node * head){
	while(head->next){
		head = head->next;
		printf("%d,",head->data);
	}
	printf("\n");
}

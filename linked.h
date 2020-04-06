/*
 * 单向链表设计
 * anthor:ruanzq
 * email:954542623@qq.com
 * github:https://www.baidu.com/ruanzq
 */
#include <stdio.h>
#include <stdlib.h>
// 定义链表节点结构
typedef struct nodes{
	int data;
	struct nodes * next;
}node;

// 计算链表长度
int count(node * head);

// 返回一个具有值value的新节点
node * create_node(int value);

/* 返回索引处为index的节点，索引越界,head为null,则返回null;
 * 合法的索引为[-1,count(head)-1];
 * -1代表返回头结点，为了处理操作一致性设计;
 */
node * get(node * head,int index);

// 返回链表中，从头结点开始的第一个值为value的节点，找不到则返回null
node * find(node * head,int value);
/*
 * 于索引处插入一个值value的新节点
 * 返回0代表操作成功
 */
int insert(node * head,int index,int value);

// 删除索引处的节点并释放占用的内存
// 返回0代表操作成功
int remove_by_index(node * head,int index);

// 打印整个单向链表
void traversal(node *head);

int count(node * head){
	int len = -1;
	while(head != NULL){
		len++;
		head = head->next;
	}
	return len;
}

node * create_node(int value){
	node * temp = (node *)malloc(sizeof(node));
	temp->data = value;
	temp->next = NULL;
	return temp;
}

node * get(node * head,int index){
	int count = -1;
	node * result = NULL;
	while(count <= index && head != NULL){
		if(count == index){
			result = head;
		}
		head = head->next;
		count++;
	}
	return result;
}

node * find(node * head,int value){
	node * result = NULL;
	while(head->next != NULL){
		head = head->next;
		if(head->data == value){
			result = head;
			break;
		}
	}
	return result;
}

int insert(node * head,int index,int value){
	node * before = get(head,index-1);
	node * newNode = create_node(value);
	int status = -1;
	if(before != NULL && newNode != NULL){
		newNode->next = before->next;
		before->next = newNode;
		status = 0;
	}
	return status;
}

int remove_by_index(node * head,int index){
	node * before = get(head,index-1);
	int status = -1;
	if(before != NULL && before->next != NULL){
		node * temp = before->next;
		before->next = temp->next;
		free(temp);
		status = 0;
	}
	return status;
}

void traversal(node * head){
	if(count(head) > 0){
		while(head->next != NULL){
			head=head->next;
			printf("%d,",head->data);
		}
		printf("\n");
	}
}

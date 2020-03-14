/*
 * 双向链表的设计与实现
*/
#include<stdio.h>
#include<stdlib.h>

struct linked{
	struct linked * previous;
	struct linked * next;
	int data;
};
// 初始化一个新的双向链表，返回头结点
struct linked * init(void);

// 返回双向链表的长度
int length(struct linked *);

// 索引i处插住值v
struct linked * insert_node(struct linked *,int i,int v);

// 删除索引i出的节点
int remove_node(struct linked *,int i);

// 返回索引i处的值
struct linked * get(struct linked *,int i);

// 打印链表的所有值
void display(struct linked * head);
int main(void){
	struct linked * fp = init();
	printf("链表长度为： %d\n",length(fp));
	for(int i = 1;i <10;i++){
		insert_node(fp,0,i);
	}
	printf("链表长度为： %d\n",length(fp));
	display(fp);
	insert_node(fp,8,666);
	insert_node(fp,10,666);
	insert_node(fp,0,10009);
	insert_node(fp,5,9999);
	printf("链表长度为： %d\n",length(fp));
	display(fp);
	return 0;
}

int length(struct linked * head){
	int count = 0;
	struct linked * cur = head->next;
	while(cur != NULL){
		cur = cur->next;
		count++;
	}
	return count;
}
struct linked * init(void){
	struct linked * head = (struct linked *)malloc(sizeof(struct linked));
	head->previous = NULL;
	head->next = NULL;
	head->data = 0;
	return head;
}
struct linked * insert_node(struct linked * head,int i,int value){
	struct linked * before = get(head,i-1);

	if(before !=NULL){	
		struct linked * newNode = (struct linked *)malloc(sizeof(struct linked));
		newNode->data = value;
		newNode->previous = before;
		newNode->next = before->next;
		before->next = newNode;
		if(newNode->next != NULL){
			newNode->next->previous = newNode;
		}
		return newNode;
	}
	return NULL;
}
int remove_node(struct linked * head,int i){
	struct linked * cur = get(head,i);
	if(cur == NULL){
		return -1;
	}else{
		cur->previous->next = cur->next;
		if( cur->next != NULL){
			cur->next->previous = cur->previous;
		}
		free(cur);
	}
}
struct linked * get(struct linked * head,int i){
	int count = 0;
	while(count <= i){
		head = head->next;
		count++;
	}
	return head;
}
void display(struct linked *head){
	while(head->next != NULL){
		head = head->next;
		printf("%d,",head->data);
	}
	printf("\n");
}

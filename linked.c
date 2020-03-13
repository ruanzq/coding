/*
 * 单向链表的设计与实现
 * author ： ruanzq
 * email  : 954542623@qq.com
 * github page : https://www.github.com/ruanzq
 */
#include<stdio.h>
#include<stdlib.h>

struct linked{
	int data;
	struct linked * next;
};
// 返回链表长度
int length(struct linked *);

// 创建一个链表
struct linked * init(void);

// 向索引i处插入一个值v
int insert(struct linked *,int i,int v);

// 删除索引i处的值
int del(struct linked *,int i);

// 判断链表是否为空
int isEmpty(struct linked *);

// 打印整个链表
void display(struct linked *);

// 返回索引i处的节点
struct linked * get(struct linked * head,int i);

// 返回第一個值为v的节点
struct linked * locate(struct linked *,int v);
int main(void){
	struct linked * fp = init();
	for(int i = 0; i < 30; i++){
		insert(fp,i,i);
	}
	display(fp);
	printf("\nlinked length is %d\n",length(fp));
	del(fp,0);
	del(fp,0);
	del(fp,0);
	del(fp,0);
	insert(fp,0,666);
	insert(fp,1,77);
	printf("\nlinked length is %d\n",length(fp));
	display(fp);
	printf("\n %d %d",get(fp,0)->data,get(fp,5)->data);
	return 0;
}
struct linked * init(){
	struct linked * p = (struct linked *)malloc(sizeof(struct linked));
	p->next = NULL;
	return p;
}
int isEmpty(struct linked * s){
	return s->next == NULL;
}
int length(struct linked * head){
	struct linked * cur = head->next;
	int count = 0;
	while(cur != NULL){
		cur = cur->next;
		count++;
	}
	return count;
}
int insert(struct linked * head,int i,int v){
	struct linked * cur = head;
	int count = 0;
	while(count != i){
		cur = cur->next;
		count++;
	}
	struct linked * t = (struct linked *)malloc(sizeof(struct linked));
	t->data = v;
	t->next = cur->next;
	cur->next = t;
	return 1;
}
int del(struct linked  * head,int i){
	struct linked * cur = head;
	int count = 0;
	while(count != i){
		cur = cur->next;
		count++;
	}
	struct linked * t = cur->next;
	cur->next = t->next;
	free(t);
}
void display(struct linked * head){
	while(head->next != NULL){
		head = head->next;
		printf("%d,",head->data);
	}
	printf("\n");
}
struct linked * get(struct linked *head,int i){
	int count = 0;
	while(count <= i && head != NULL){
		head = head->next;
		count++;
	}
	return head;
}
struct linked * locate(struct linked * head,int v){
	head = head->next;
	while(head != NULL){
		if(head->data == v)
			break;
		head = head->next;
	}
	return head;
}

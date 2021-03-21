/*
* 队列 链表实现 带头结点
* @author:ruanzq
* @github:https://github.com/ruanzq/
* @date:2021年3月21日
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	struct n * next;
	int data;
}node;

typedef struct  q{
	node * front;
	node * rear;
}Q;

node * _build(int v); //创建一个节点

Q * init(void); //初始化一个新的循环队列

int isNull(Q * p); // 判空

void scanQ(Q *p); //遍历

int in(Q * p,int data); //入队

int out(Q * p); //出队

int main(void){
	Q * p = init();
	for(int i=0;i<10;i++){
		if(in(p,i*i)){
			printf("in ok!\n");
		}else{
			printf("in invaild\n");
		}
	}
	scanQ(p);
	for(int i=0;i<5;i++){
		if(out(p)){
			printf("out ok!\n");
		}else{
			printf("out invaild\n");
		}
	}
	scanQ(p);
	return 0;
}

Q * init(void){
	Q *  p = (Q *)malloc(sizeof(Q));
	p->front = _build(0);
	p->rear = p->front;
}
node * _build(int v){
	node * p = (node *)malloc(sizeof(node));
	p->data = v;
	p->next = NULL;
	return p;
}

int isNull(Q *p){
	if(p->front == p->rear){
		return 1;
	}else{
		return 0;
	}
}

void scanQ(Q *p){
	if(!isNull(p)){
		node * s = p->front->next;
		while(s){
			printf("%d ",s->data);
			s=s->next;
		}
		printf("\n");
	}
}

int in(Q *p,int data){
	node * n = _build(data);
	if(n){
		p->rear->next = n;
		p->rear = n;
		return 1;
	}
	return 0;
}

int out(Q *p){
	if(!isNull(p)){
		node * n = p->front->next;
		p->front->next = n->next;
		if(p->rear == n){
			p->rear = p->front;
		}
		free(n);
		return 1;
	}
	return 0;
}

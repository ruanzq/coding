/*
* 队列 链表实现 无头结点
* @author:ruanzq
* @github:ruanzq
* @date:2021年3月6日
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
		}
	}
	scanQ(p);
	for(int i=0;i<5;i++){
		if(out(p)){
			printf("out ok!\n");
		}
	}
	scanQ(p);
	for(int i=0;i<2;i++){
		if(out(p)){
			printf("out ok!\n");
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
	for(int i=0;i<10;i++){
		if(in(p,i*i)){
			printf("in ok!\n");
		}
	}
	scanQ(p);
	return 0;
}

Q * init(void){
	Q *  p = (Q *)malloc(sizeof(Q));
	p->front = NULL;
	p->rear = NULL;
}
node * _build(int v){
	node * p = (node *)malloc(sizeof(node));
	p->data = v;
	p->next = NULL;
	return p;
}

int isNull(Q *p){
	if(p->front && p->rear){
		return 0;
	}else{
		return 1;
	}
}

void scanQ(Q *p){
	if(!isNull(p)){
		node * s = p->front;
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
		if(isNull(p)){
			p->rear = n;
			p->front = n;
		}else{
			p->rear->next = n;
			p->rear = n;
		}
		return 1;
	}
	return 0;
}

int out(Q *p){
	if(!isNull(p)){
		node * n = p->front;
		p->front = p->front->next;
		if(p->rear == n){
			p->rear = NULL;
		}
		free(n);
		return 1;
	}
	return 0;
}

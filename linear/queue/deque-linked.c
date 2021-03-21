/*
*双端队列 双向链表实现 无头节点
*@author:ruanzq
*@github:https://github.com/ruanzq/
*@date: 2021年3月6日
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct n{
	struct n * next;
	struct n * up;
	int v;
}Node;

typedef struct s{
	Node * front;
	Node * rear;
}Deque;

Deque * init(void);//初始化队列

Node * _build(int v);//构造一个Deque节点

int inL(Deque * Q,int v);//从队头入队

int inR(Deque * Q,int v);//从队尾入队

int outL(Deque * Q);//从队头出队

int outR(Deque * Q);//从队尾出队

void scanDeque(Deque * Q);//遍历打印队列

int isNull(Deque *Q);//判空

int main(void){
	Deque * Q = init();
	for(int i = 0;i<5;i++){
		if(inL(Q,i)){
			printf("inL OK\n");
		}else{
			printf("inL invalid\n");
		}
	}
	scanDeque(Q);
	for(int i = 0;i<5;i++){
		if(inR(Q,i)){
			printf("inR OK\n");
		}else{
			printf("inR invalid\n");
		}
	}
	scanDeque(Q);
	for(int i = 0;i<3;i++){
		if(outR(Q)){
			printf("outR OK\n");
		}else{
			printf("outR invalid\n");
		}
	}
	scanDeque(Q);
	for(int i = 0;i<11;i++){
		if(outR(Q)){
			printf("outR OK\n");
		}else{
			printf("outR invalid\n");
		}
	}
	scanDeque(Q);
	return 0;
}

Deque * init(void){
	Deque * Q = (Deque *)malloc(sizeof(Deque));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

Node * _build(int v){
	Node * n = (Node *)malloc(sizeof(Node));
	n->next = NULL;
	n->up = NULL;
	n->v = v;
	return n;
}

int inL(Deque * Q,int v){
	Node * n = _build(v);
	if(n){
		if(isNull(Q)){
			Q->front = n;
			Q->rear = n;
		}else{
			n->next = Q->front;
			Q->front->up = n;
			Q->front = n;
		}
		return 1;
	}
	return 0;
}

int inR(Deque * Q,int v){
	Node * n = _build(v);
	if(n){
		if(isNull(Q)){
			Q->front = n;
			Q->rear = n;
		}else{
			Q->rear->next = n;
			n->up = Q->rear;
			Q->rear = n;
		}
		return 1;
	}
	return 0;
}

int outL(Deque * Q){
	if(!isNull(Q)){
		Node * n = Q->front;
		Q->front = n->next;
		if(Q->front){
			Q->front->up = NULL;
		}else{
			Q->rear = NULL;
		}
		free(n);
		return 1;
	}
	return 0;
}

int outR(Deque * Q){
	if(!isNull(Q)){
		Node * n = Q->rear;
		Q->rear = Q->rear->up;
		if(Q->rear){
			Q->rear->next = NULL;
		}else{
			Q->front = NULL;
		}
		free(n);
		return 1;
	}
	return 0;
}
void scanDeque(Deque * Q){
	if(!isNull(Q)){
		Node * s = Q->front;
		while(s){
			printf("%d ",s->v);
			s=s->next;
		}
		printf("\n");
	}else{
		printf("deque is empty\n");
	}
}

int isNull(Deque *Q){
	if(Q->rear || Q->front){
		return 0;
	}else{
		return 1;
	}
}


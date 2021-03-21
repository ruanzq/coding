/*
* 循环队列 顺序表实现
* @author:ruanzq
* @github:https://github.com/ruanzq/
* @date:2021年3月21日
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
typedef struct{
	int store[MAXSIZE];
	int front,tail;
	int used;
}Q;

int in(Q * queue,int v); //入队

int out(Q * queue); //出队

int isNull(Q * queue); //判空

int isFull(Q * queue);//判满

Q * init(void); //初始化一个新队列

void scanQ(Q * queue);//遍历队列

int main(void){
	Q * q = init();
	for(int i = 0;i<10;i++){
		if(in(q,i*i)){
			printf("入队成功,位置%d,值%d\n",(q->tail-1)%MAXSIZE,i*i);
		}else{
			printf("入队失败\n");
		}
	scanQ(q);
	}
	scanQ(q);
	for(int i = 0;i<10;i++){
		if(out(q)){
			printf("出队成功\n");
		}else{
			printf("出队失败\n");
		}
	scanQ(q);
	}
	return 0;
}
Q * init(void){
	Q * pt = (Q*)malloc(sizeof(Q));
	pt->used = 0;
	pt->front = 0;
	pt->tail = 0;
	return pt;
}
int isNull(Q * queue){
	if(queue->used == 0){
		return 1;
	}
	return 0;
}
int isFull(Q * queue){
	if(queue->used == MAXSIZE){
		return 1;
	}
	return 0;
}
int in(Q * queue,int v){
	if(!isFull(queue)){
		queue->store[queue->tail] = v;
		queue->tail = (queue->tail+1)%MAXSIZE;
		queue->used++;
		return 1;
	}
	return 0;
}
int out(Q *queue){
	if(!isNull(queue)){
		queue->front = (queue->front+1)%MAXSIZE;
		queue->used--;
		return 1;
	}
	return 0;
}
void scanQ(Q * queue){
	if(!isNull(queue)){
		int i = queue->used;
		int f = queue->front;
		printf("\n -- ");
		while(i>0){
			printf("%d ",queue->store[f]);
			f = (f+1)%MAXSIZE;
			i--;
		}
		printf(" -- \n");
	}
}

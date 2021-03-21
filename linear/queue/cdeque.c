/*
* 双端队列 顺序表实现
* @author:ruanzq
* @github:https://github.com/ruanzq/coding
* @date:2021年3月21日
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int * store;//数据区
	int front,rear;
	int size;//队列长度
	int used;//已使用的空间
}Q;

Q * init(int size);//初始化队列

int isNull(Q *p);//判空

int isFull(Q *p);//判满

int inL(Q *p,int value);//队头入队

int inR(Q *p,int value);//队尾入队

int outL(Q *p);//队头出队

int outR(Q *p);//队尾入队

void scanQ(Q *p);//遍历打印队列

int main(void){
 	Q * p = init(30);
         for(int i = 0;i<5;i++){
                 if(inL(p,i)){
                         printf("inL OK\n");
                 }else{
                         printf("inL invalid\n");
                 }
         }
         scanQ(p);
         for(int i = 0;i<5;i++){
                 if(inR(p,i)){
                         printf("inR OK\n");
                 }else{
                         printf("inR invalid\n");
                 }
         }
         scanQ(p);
         for(int i = 0;i<3;i++){
		if(outR(p)){
                	printf("outR OK\n");
                }else{
			printf("outR invalid\n");
                }
         }
         scanQ(p);
         for(int i = 0;i<11;i++){
                 if(outR(p)){
                         printf("outR OK\n");
                 }else{
                         printf("outR invalid\n");
                 }
         }
        scanQ(p);
	return 0;
}

Q * init(int size){
	Q *p = (Q *)malloc(sizeof(Q));
	p->store = (int *)malloc(sizeof(int)*size);
	p->front = 0;
	p->rear = 0;
	p->used = 0;
	p->size = size;
	printf("deque is inited size is %d\n",p->size);
	return p;
}

int isNull(Q *p){
	if(p->used == 0){
		return 1;
	}
	return 0;
}

int isFull(Q *p){
	if(p->size == p->used){
		return 1;
	}
	return 0;
}

int inL(Q *p,int value){
	if(!isFull(p)){
		if(isNull(p)){
			return inR(p,value);
		}else if(p->front == 0){
			p->front = p->size - 1;
		}else{
			p->front = p->front-1;
		}
		p->store[p->front] = value;
		p->used++;
		return 1;
	}
	return 0;
}

int inR(Q *p,int value){
	if(!isFull(p)){
		p->store[p->rear] = value;
		p->rear = (p->rear + 1) % p->size;
		p->used++;
		return 1;
	}
	return 0;
}

int outL(Q *p){
	if(!isNull(p)){
		p->front = (p->front + 1) % p->size;
		p->used--;
		return 1;
	}
	return 0;
}

int outR(Q *p){
	if(!isNull(p)){
		if(p->rear == 0){
			p->rear = p->size - 1;
		}else{
			p->rear = p->rear - 1;
		}
		p->used--;
		return 1;
	}
	return 0;
}

void scanQ(Q *p){
	if(!isNull(p)){
		int start = p->front;
		int count = p->used;
		printf("scanQ: ");
		while(count>0){
			printf("%d ",p->store[start]);
			count--;
			start = (start+1)%p->size;
		}
		printf("\n");
	}
}


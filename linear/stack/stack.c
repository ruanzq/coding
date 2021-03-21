/*
* 栈 顺序表实现
* @author:ruanzq
* @github:https://github.com/ruanzq/
* @date:2021年3月21日
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int * data;
	int top;
	int size;
}stack;

stack * init(int size);//初始化一个栈

int push(stack *p,int value);//压栈

int pop(stack *p);//出栈

void status(stack *p);//查看栈的使用情况

int main(void){
	stack * p = init(32);
	for(int i=0;i<7;i++){
		if(push(p,i)){
			printf("push done %d\n",i);
		}else{
			printf("push failed\n");
		}
		status(p);
	}
	for(int i=0;i<12;i++){
		if(pop(p)){
			printf("pop done %d\n",i);
		}else{
			printf("pop failed\n");
		}
		status(p);
	}
	return 0;
}

stack * init(int size){
	stack * p = (stack*)malloc(sizeof(stack));
	p->data = (int*)malloc(sizeof(int)*size);
	p->size = size;
	p->top = -1;
}

int push(stack *p,int value){
	if(p->top+1<p->size){
		p->data[++p->top] = value;
		return 1;
	}
	return 0;
}

int pop(stack *p){
	if(p->top > -1){
		p->top--;
		return 1;
	}
	return 0;
}
void status(stack *p){
	float rate = (float)(p->top+1)/(float)p->size;
	printf("rate is %2.2f\% \n",rate*100);
}

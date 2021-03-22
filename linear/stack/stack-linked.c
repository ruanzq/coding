/*
* 栈 链表实现
* @author:ruanzq
* @github:
* @date:2021年3月22日
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct n{
	int data;
	struct n * next;
}Node;

typedef struct{
	Node * top;
	int used;
}stack;

Node * _build(int v);//创建一个数据节点

stack * init(void);//创建一个链表

int push(stack * s,int v);//入栈

int pop(stack * s);//出栈

int len(stack * s);//返回栈存储了多少个元素

int main(void){
	 stack * p = init();
         for(int i=0;i<7;i++){
                 if(push(p,i)){
                         printf("push done %d\n",i);
                 }else{
                         printf("push failed\n");
                 }
                 printf("%d",len(p));
         }
         for(int i=0;i<12;i++){
                 if(pop(p)){
                         printf("pop done %d\n",i);
                 }else{
                         printf("pop failed\n");
                 }
                 printf("%d",len(p));
         }
         return 0;
}

Node * _build(int v){
	Node * n = (Node *)malloc(sizeof(Node));
	n->next = NULL;
	n->data = v;
	return n;
}

stack * init(void){
	stack * s = (stack *)malloc(sizeof(stack));
	s->top = NULL;
	s->used = 0;
	return s;
}

int push(stack * s,int v){
	Node * newNode = _build(v);
	if(s->top){
		newNode->next = s->top;
	}
	s->top = newNode;
	s->used++;
	return 1;
}
int pop(stack * s){
	if(s->top){
		Node * n = s->top;
		s->top = n->next;
		s->used--;
		free(n);
		return 1;
	}
	return 0;
}

int len(stack * s){
	return s->used;
}


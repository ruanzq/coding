/*
 * 线性表物理地址上连续存储的实现
 * 
 * author：ruanzq
 * email ：954542623@qq.com
 * github page ：https://www.github.com/ruanzq
 *
 */
#include<stdio.h>
#include<stdlib.h>

// 定义数据结构
struct linear{
	// 数据区指针
	int *fp;

	// 记录总大小
	int size;

	// 已记录数据的最后一个下标，空表为-1
	int lastIndex;
};
// 向索引i插入一个值v，返回插入后的线性表长度
int insert(struct linear *,int i,int v);

// 删除位于索引i的值，并将其作为返回值
int del(struct linear *,int i);

// 清空线性表
void clear(struct linear *);

// 返回索引i处的值
int get(struct linear *,int i);

// 返回第一次找到value的索引
int locate(struct linear *,int value);

// 生成一个线性表
struct linear * create(int size);

// 遍历打印线性表的值
void foreach(struct linear *);

// 返回线性表的长度
int length(struct linear *);

// 判断线性表是否为空
int isEmpty(struct linear *);

// 判断线性表是否满了
int isFull(struct linear *);

// 栈相关操作
// 出栈，返回弹出值
int pop(struct linear *s);

// 入栈，返回栈长度
int push(struct linear *s,int v);

// 队列相关操作
// 入队，返回入队后的队长
int in(struct linear *,int v);

// 出队，返回出队的元素
int out(struct linear *);
int main(void){
	struct linear * l = create(100);
	for(int i = 0;i<100;i++){
		insert(l,i,i);
	}
	foreach(l);
	in(l,10000);
	printf("\n%d\n",out(l));
	printf("%d\n",out(l));
	printf("%d\n",out(l));
	printf("%d\n",out(l));
	printf("%d\n",out(l));
	foreach(l);
	return 0;
}
struct linear * create(int size){
	struct linear * s =(struct linear *)malloc(sizeof(struct linear));
	s->fp = (int *)malloc(sizeof(int)*size);
	s->size = size;
	s->lastIndex = -1;
	return s;
}
int isEmpty(struct linear *s){
	if(s->lastIndex == -1){
		return 1;
	}else{
		return 0;
	}
}
int isFull(struct linear *s){
	if(s->lastIndex+1 == s->size){
		return 1;
	}else{
		return 0;
	}
}
void foreach(struct linear *s){
	for(int i = 0;i <= s->lastIndex;i++){
		printf("%d,",s->fp[i]);
	}
	printf("\n");
}
int insert(struct linear *s,int i,int v){
	if(i < 0 || i > s->lastIndex+1 || s->lastIndex+1 >= s->size ){
		printf("out of range %d %d\n",i,s->lastIndex);
		return -1;
	}else{
		int t = s->lastIndex;
		while(t>=i){
			s->fp[t+1] = s->fp[t];
			t--;
		}
		s->fp[t+1] = v;	
		s->lastIndex++;
	}
}
int del(struct linear *s,int i){
	if(i < 0 || i > s->lastIndex){
		printf("out of range");
		return -1;
	}else{
		while(i < s->lastIndex){
			s->fp[i] = s->fp[i+1];
			i++;
		}
		return s->fp[s->lastIndex--];
	}
}
int length(struct linear *s){
	return s->lastIndex+1;
}
void clear(struct linear *s){
	s->lastIndex = -1;
}
int get(struct linear *s,int i){
	if(i < 0 || i > s->lastIndex){
		printf("fun:get --- out of range");
	}else{
		return s->fp[i];
	}
}

int pop(struct linear *s){
	if(s->lastIndex == -1){
		printf("fun:pop --- out of range");
		return -1;
	}else{
		int t = s->fp[s->lastIndex];
		s->lastIndex--;
		return t;
	}
}
int push(struct linear *s,int v){
	if(isFull(s)){
		printf("fun:push --- linear is fulled");
	}else{
		s->fp[++s->lastIndex] = v;
		return length(s);
	}
}
int in(struct linear *s,int v){
	return push(s,v);
}
int out(struct linear *s){
	return del(s,0);
}
int locate(struct linear *s,int v){
	if(isEmpty(s)){
	
	}else{
		int i = 0;
		while(i <= s->lastIndex){
			if(s->fp[i] == v){
				return i;
			}
			i++;
		}
		return -1;
	}
}

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
int insert_element(struct linear *,int i,int v);

// 删除位于索引i的值，并将其作为返回值
int remove_element(struct linear *,int i);

// 清空线性表
void clear_elements(struct linear *);

// 返回索引i处的值
int get_elements(struct linear *,int i);

// 返回第一次找到value的索引
int find_value(struct linear *,int value);

// 生成一个线性表
struct linear * init(int size);

// 遍历打印线性表的值
void display(struct linear *);

//  输出线性表的使用情况
void total(struct linear *);

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
	struct linear * p = init(50);
	total(p);
	for(int i = 0;i < 10;i++){
		insert_element(p,i,i);
	}
	total(p);
	display(p);
	remove_element(p,0);
	remove_element(p,6);
	remove_element(p,3);
	remove_element(p,p->lastIndex);
	total(p);
	display(p);
	insert_element(p,0,666);
	insert_element(p,p->lastIndex,666);
	insert_element(p,p->lastIndex+1,111666);
	insert_element(p,p->lastIndex+1+321321,111666);
	total(p);
	display(p);
	return 0;
}
struct linear * init(int size){
	struct linear * s = (struct linear *)malloc(sizeof(struct linear));
	s->fp = (int *)malloc(sizeof(int)*size);
	s->size = size;
	s->lastIndex = -1;
	return s;
}
int isEmpty(struct linear * s){
	if(s->lastIndex == -1){
		return 1;
	}else{
		return 0;
	}
}
int isFull(struct linear * s){
	if(s->lastIndex+1 == s->size){
		return 1;
	}else{
		return 0;
	}
}
void display(struct linear * s){
	for(int i = 0;i <= s->lastIndex;i++){
		printf("%d,",s->fp[i]);
	}
	printf("\n");
}
void total(struct linear *s){
	float value = (float)(s->lastIndex + 1)/(float)s->size;
	value = value*100.0;
	printf("已经使用： %d\%\n",(int)value);
}

int insert_element(struct linear *s,int i,int value){
	if(i >= 0 && i<=s->lastIndex + 1 && !isFull(s) ){
		for(int t = s->lastIndex; t >= i; t--)
			s->fp[t+1] = s->fp[t];
		s->fp[i] = value;
		s->lastIndex++;
	}
	return s->lastIndex + 1;
}
int remove_element(struct linear *s,int i){
	if(i >= 0 && i <= s->lastIndex){
		for( ;i < s->lastIndex; i++){
			s->fp[i] = s->fp[i+1];
		}	
		s->lastIndex--;
	}
	return s->lastIndex + 1;
	
}
int length(struct linear *s){
	return s->lastIndex+1;
}
void clear_elements(struct linear *s){
	s->lastIndex = -1;
}
int get_elements(struct linear *s,int i){
	if(i < 0 || i > s->lastIndex){
		printf("fun:get --- out of range");
	}else{
		return s->fp[i];
	}
}
int find_value(struct linear * s,int value){
	int index = -1;
	for( int i = 0;i <= s->lastIndex;i++ ){
		if( s->fp[i] == value ){
			index = i;
			break;
		}
	}
	return index;
}
int pop(struct linear * s){
	if(isEmpty(s)){
		return -1;
	}else{
		remove_element(s,s->lastIndex);
		return 0;
	}
}
int push(struct linear *s,int value){
	if(isFull(s)){
		return -1;
	}else{
		insert_element(s,s->lastIndex + 1,value);
		return 0;
	}
}
int in(struct linear *s,int v){
	return push(s,v);
}
int out(struct linear *s){
	return remove_element(s,0);
}

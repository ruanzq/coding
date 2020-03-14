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

// 创建一个链表,返回表头
struct linked * init(void);

// 向索引i处插入一个值value，返回新插入的节点或NULL
struct linked * insert_node(struct linked *,int i,int value);

// 已存在的节点s后插入值value，返回新插入的节点或NULL
struct linked * insert(struct linked *s,int value);

// 删除索引i处的节点
int remove_node(struct linked *,int i);

// 判断链表是否为空
int isEmpty(struct linked *);

// 打印整个链表
void display(struct linked *);

// 返回索引i处的节点，超过索引则返回NULL
struct linked * get(struct linked * head,int i);

// 返回第一個值为v的节点
struct linked * locate(struct linked *,int v);
int main(void){
	struct linked * fp = init();
	for(int i = 0; i < 30; i++){
		insert_node(fp,i,i);
	}
	display(fp);
	printf("\nlinked length is %d\n",length(fp));
	remove_node(fp,29);
	remove_node(fp,10);
	remove_node(fp,0);
	printf("\nlinked length is %d\n",length(fp));
	display(fp);
	insert_node(fp,26,5);
	insert_node(fp,28,4);
	insert_node(fp,5,3);
	insert_node(fp,0,2);
	printf("\nlinked length is %d\n",length(fp));
	display(fp);
	return 0;
}

struct linked * init(){
	struct linked * p = (struct linked *)malloc(sizeof(struct linked));
	p->next = NULL;
	return p;
}

int isEmpty(struct linked * head){
	return head->next == NULL;
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

struct linked * insert_node(struct linked * head,int i,int value){
	struct linked * cur = get(head,i-1);
	if(cur == NULL){
		return NULL;
	}
	return insert(cur,value);
}

struct linked * insert(struct linked *s,int value){
	struct linked * t = (struct linked *)malloc(sizeof(struct linked));
	t->data = value;
	t->next = s->next;
	s->next = t;
	return t;
}

int remove_node(struct linked  * head,int i){
	struct linked * cur = get(head,i-1);

	if( cur != NULL){
		if(cur->next != NULL){
			struct linked * t = cur->next;
			cur->next = t->next;
			free(t);
			return 0;
		}
	}
	return -1;
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
	while(count <= i && head->next != NULL){
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

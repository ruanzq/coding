/*
 * 单向链表设计
 * anthor:ruanzq
 * email:954542623@qq.com
 * github:https://www.baidu.com/ruanzq
 */
#include <stdio.h>
#include <stdlib.h>
// 定义链表节点结构
typedef struct nodes{
	int data;
	struct nodes * next;
}node;

// 计算链表长度
int count(node * head);

// 返回一个具有值value的新节点
node * create_node(int value);

/* 返回索引处为index的节点，索引越界,head为null,则返回null;
 * 合法的索引为[-1,count(head)-1];
 * -1代表返回头结点，为了处理操作一致性设计;
 */
node * get(node * head,int index);

// 返回链表中，从头结点开始的第一个值为value的节点，找不到则返回null
node * find(node * head,int value);
/*
 * 于索引处插入一个值value的新节点
 * 返回0代表操作成功
 */
int insert(node * head,int index,int value);

// 删除索引处的节点并释放占用的内存
// 返回0代表操作成功
int removes(node * head,int index);

// 打印整个单向链表
void display(node *head);

int main(void){
	// 建立头节点
	node * head = create_node(0);
	// 用例测试
	printf("init size: %d\n",count(head));
	printf("first insert status is %d\n",insert(head,0,99));
	printf("first insert status is %d\n",insert(head,1,99));
	printf("first insert status is %d\n",insert(head,-1,99));
	printf("first insert status is %d\n",insert(head,-2,99));
	printf("first insert status is %d\n",insert(head,20,99));
	display(head);
	insert(head,0,1000);
	insert(head,1,666);
	insert(head,count(head),8888);
	insert(head,count(head),888);
	insert(head,count(head),88);
	insert(head,count(head),8);
	display(head);
	removes(head,-1);
	removes(head,-10);
	removes(head,-100);
	removes(head,count(head));
	display(head);
	removes(head,0);
	removes(head,count(head)-1);
	removes(head,2);
	display(head);
	node * t1 = find(head,92);
	node * t2 = find(head,99);
	node * t3 = find(head,88);
	if(t1){
		printf("t1 find %d\n",t1->data);
	}
	if(t2){
		printf("t2 find %d\n",t2->data);
	}
	if(t3){
		printf("t3 find %d\n",t3->data);
	}
	return 0;
}
int count(node * head){
	int len = -1;
	while(head != NULL){
		len++;
		head = head->next;
	}
	return len;
}

node * create_node(int value){
	node * temp = (node *)malloc(sizeof(node));
	temp->data = value;
	temp->next = NULL;
	return temp;
}

node * get(node * head,int index){
	int count = -1;
	node * result = NULL;
	while(count <= index && head != NULL){
		if(count == index){
			result = head;
		}
		head = head->next;
		count++;
	}
	return result;
}

node * find(node * head,int value){
	node * result = NULL;
	while(head->next != NULL){
		head = head->next;
		if(head->data == value){
			result = head;
			break;
		}
	}
	return result;
}

int insert(node * head,int index,int value){
	node * before = get(head,index-1);
	node * newNode = create_node(value);
	int status = -1;
	if(before != NULL && newNode != NULL){
		newNode->next = before->next;
		before->next = newNode;
		status = 0;
	}
	return status;
}

int removes(node * head,int index){
	node * before = get(head,index-1);
	int status = -1;
	if(before != NULL && before->next != NULL){
		node * temp = before->next;
		before->next = temp->next;
		free(temp);
		status = 0;
	}
	return status;
}

void display(node * head){
	if(count(head) > 0){
		while(head->next != NULL){
			head=head->next;
			printf("%d,",head->data);
		}
		printf("\n");
	}
}

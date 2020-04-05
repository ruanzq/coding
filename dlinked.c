#include <stdio.h>
#include <stdlib.h>

typedef struct nodes{
	struct nodes * next;
	struct nodes * pre;
	int data;
}node;

int count(node * head);

node * create_node(int value);

node * get(node * head,int index);

node * find(node * head,int value);

int insert(node * head,int index,int value);

int removes(node * head,int index);

void display(node * head);

int main(void){
	node * head = create_node(0);
	printf("insert status %d\n",insert(head,0,1));
	printf("insert status %d\n",insert(head,-1,2));
	printf("insert status %d\n",insert(head,-20,3));
	printf("insert status %d\n",insert(head,count(head)-1,4));
	printf("insert status %d\n",insert(head,count(head),5));
	printf("insert status %d\n",insert(head,count(head)+1,6));
	printf("insert status %d\n",insert(head,30,9999));
	printf("insert status %d\n",insert(head,count(head)+2,7));
	for(int i = 0; i<5 ; i++){
		insert(head,count(head),i+10);
	}
	display(head);
	printf("removes status %d\n",removes(head,0));
	printf("removes status %d\n",removes(head,-1));
	printf("removes status %d\n",removes(head,-20));
	printf("removes status %d\n",removes(head,count(head)-1));
	printf("removes status %d\n",removes(head,count(head)+1));
	printf("removes status %d\n",removes(head,30));
	printf("removes status %d\n",removes(head,count(head)));
	display(head);
	return 0;
}
int count(node * head){
	int i = 0;
	for(;head->next;i++)
		head = head->next;
	return i;
}

node * create_node(int value){
	node * newNode = (node *)malloc(sizeof(newNode));
	newNode->next = NULL;
	newNode->pre = NULL;
	newNode->data = value;
	return newNode;
}

node * get(node * head,int index){
	node * result = NULL;
	for(int count = -1;count <= index && head != NULL;count++){
		if(count == index){
			result = head;
			break;
		}
		head = head->next;
	}
	return result;
}

node * find(node * head,int value){
	node * result = NULL;
	while(head->next){
		head = head->next;
		if(head->data == value){
			result = head;
			break;
		}
	}
	return result;
}

int insert(node * head,int index,int value){
	int  status = -1;
	node * before = get(head,index-1);
	node * newNode = create_node(value);

	if(before && newNode){
		newNode->next = before->next;
		newNode->pre = before;
		before->next = newNode;
		if(newNode->next){
			newNode->next->pre = newNode;
		}
		status = 0;
	}
	return status;	
}

int removes(node * head,int index){
	node * before = get(head,index-1);
	int status = -1;
	if( before && before->next ){
		node * t = before->next;
		before->next = t->next;
		if( t->next ){
			t->next->pre = before;
		}
		free(t);
		status = 0;
	}
	return status;
}

void display(node * head){
	while(head->next){
		head = head->next;
		printf("%d,",head->data);
	}
	printf("\n");
}

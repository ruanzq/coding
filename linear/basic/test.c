#include<stdio.h>
#include<stdlib.h>
#include "linked.h"

int main(void){
	list * head = init();
	int i = 0;
	for(;i<10;i++){
		insert(head,i,i);
	}
	travel(head);
	rm(head,0);
	rm(head,-1);
	rm(head,len(head));
	travel(head);
	insert(head,0,10);
	insert(head,-1,11);
	insert(head,len(head),12);
	insert(head,len(head)-1,13);
	travel(head);
}


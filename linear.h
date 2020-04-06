#include <stdio.h>
#include <stdlib.h>
typedef struct linear{
	int * bank;
	int lastIndex;
	int size;
}L;

int count(L *);

L * init(int size);

int insert(L * block,int index,int value);

int remove_by_index(L * block,int index);

int remove_by_value(L * block,int value);

void traversal(L * block);

void clear(L * block);

void total(L *block);

int count(L * block){
	return block->lastIndex + 1;
}

L * init(int size){
	L * block = (L *)malloc(sizeof(L));
	block->bank = (int *)malloc(sizeof(int)*size);
	block->size = size;
	block->lastIndex = -1;
	return block;
}

int insert(L * block,int index,int value){
	int status = -1;
	if(block->lastIndex+1 < block->size)
	if(index >= 0 && index <= block->lastIndex+1 ){
		for(int i = block->lastIndex;i >= index; i--)
			;
		block->bank[index] = value;
		block->lastIndex++;
		status = 0;
	}
	return status;
}

int remove_by_index(L * block,int index){
	int status = -1;
	if(index >= 0 && index <= block->lastIndex){
		for(;index < block->lastIndex;index++)
			block->bank[index] = block->bank[index+1];
		block->lastIndex--;
		status = 0;
	}
	return status;
}

int remove_by_value(L * block,int value);

void traversal(L * block){
	for(int i = 0; i<= block->lastIndex;i++)
		printf("%d,",block->bank[i]);
	printf("\n");
}

void clear(L * block){
	block->lastIndex = -1;
}

void total(L * block){
	float per = (float)(block->lastIndex + 1)/(float)block->size;
	per = per * 100.00;
	printf("%d\%\n",(int)per);
}

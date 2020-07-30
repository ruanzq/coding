#include<stdio.h>
#include<stdlib.h>
typedef struct l{
	int last_index;
	int * dp;
	int size;
}array;
array * create(int size);

int len(array *);

int get(array *,int index);

int set(array *,int index,int value);

int vaildRange(array *,int index);

int insert(array *,int index,int value);

int rm(array *,int index);

int  travel(array *);

int main(void){
	array * c = create(100);
	printf("array len is %d\n",len(c));
	int i = 0;
		for(;i<10;i++){
					insert(c,i,i);
						}
			travel(c);
				rm(c,0);
					rm(c,-1);
						rm(c,len(c));
							travel(c);
								insert(c,0,10);
									insert(c,-1,11);
										insert(c,len(c),12);
											insert(c,len(c)-1,13);
												insert(c,len(c)+1,99);
													travel(c);
														printf("array len is %d\n",len(c));
																travel(c);
	return 0;
}
array * create(int size){
	array * container  = NULL;
	if(size>0){
		container = (array *)malloc(sizeof(array));
		container->dp = (int *)malloc(sizeof(int)*size);
		container->size = size;
		container->last_index = -1;
	}
	return container;
}

int len(array *  container){
	int count = 0;
	if(container){
		count = container->last_index + 1;
	}
	return count;
}
int vaildRange(array * container,int index){
	if(container && index>=0 && index<=container->last_index)
		return 1;
	return 0;
}
int get(array * container,int index){
	if(vaildRange(container,index)){
		return *(container->dp+index);
	}
}
int set(array * container,int index,int value){
	int status = -1;
	if(vaildRange(container,index)){
		*(container->dp+index) = value;
		status = 1;
	}
	return status;
}
int insert(array * container,int index,int value){
	if(container && index >=0 && index <= container->last_index+1){
		if(container->last_index+1 < container->size){
			int rear = container->last_index+1;
			while(rear > index){
				*(container->dp+rear)=*(container->dp+rear-1);
				rear--;
			}
			*(container->dp+index) = value;
			container->last_index++;
		}
	}
	return container->last_index;
}
int rm(array * container,int index){
	if(vaildRange(container,index)){
		while(index<container->last_index){
			*(container->dp+index) = *(container->dp+index+1);
			index++;
		}
		container->last_index--;
	}
}
int travel(array * container){
	if(container && container->last_index>-1){
		int i = 0;
		while(i<=container->last_index){
			printf("%d,",*(container->dp+i));
			i++;
		}
		printf("\n");
	}
}

#include  "lx.h"
int main(void){
	int bool = 0;
	L * head = init(100);

	for(int i = 0;i < 5; i++){
		insert(head,i,i);
	}
	traversal(head);
	// 越界插入与删除
	printf("越界插入删除检测:\n");
	printf("insert status %d\n",insert(head,-1,0));
	printf("insert status %d\n",insert(head,-10,0));
	printf("insert status %d\n",insert(head,count(head)+1,0));
	printf("insert status %d\n",insert(head,10000,0));
	printf("remove status %d\n",remove_by_index(head,-1));
	printf("remove status %d\n",remove_by_index(head,-10));
	printf("remove status %d\n",remove_by_index(head,100));
	printf("remove status %d\n",remove_by_index(head,count(head)));
	printf("检测结束\n");
	traversal(head);
	total(head);
	// 正常位置检测
	printf("正常位置插入删除检测\n");
	printf("insert status %d\n",insert(head,0,1));
	printf("insert status %d\n",insert(head,count(head)/2,2));
	printf("insert status %d\n",insert(head,count(head),3));
	printf("insert status %d\n",insert(head,count(head)-1,4));
	traversal(head);
	total(head);
	printf("remove status %d\n",remove_by_index(head,0));
	printf("remove status %d\n",remove_by_index(head,count(head)-1));
	printf("remove status %d\n",remove_by_index(head,count(head)/2));
	traversal(head);
	total(head);
	printf("检测结束\n");
	return 0;
}

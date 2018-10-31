
#include"Queue.h"


void test()
{
	Queue Qlist;
	QueueInit(&Qlist);
	QueuePush(&Qlist, 1);
	QueuePush(&Qlist, 2);
	QueuePush(&Qlist, 3);
	QueuePush(&Qlist, 4);
	QueuePop(&Qlist);
	printf("front %d\n", QueueFront(&Qlist));
	printf("Back %d\n", QueueBack(&Qlist));
	printf("%d\n", QueueSize(&Qlist));
	printf("%d\n",QueueEmpty(&Qlist));
	QueuePop(&Qlist);
	printf("front %d\n", QueueFront(&Qlist));
	printf("Back %d\n", QueueBack(&Qlist));
	printf("%d\n", QueueSize(&Qlist));
	printf("%d\n",QueueEmpty(&Qlist));
	
}



int main()
{
	test();
	system("pause");
	return 0;
}
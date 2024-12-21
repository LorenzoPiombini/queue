#include <stdio.h>
#include "queue.h"



int main(void)
{
	Queue q = {NULL,NULL,0};
	if(!q_init(&q))
	{
		printf("queue init failed.\n");
		return 0;
	}	

	int a = 1, *pa = &a;
	if(!enqueue(&q,(void*)pa))
	{
		printf("enqueue failed.\n");
		return 0;
	}

	
	int b = 2, *pb = &b;
	if(!enqueue(&q,(void*)pb))
	{
		printf("enqueue failed.\n");
		return 0;
	}

	int c = 3, *pc = &c;
	if(!enqueue(&q,(void*)pc))
	{
		printf("enqueue failed.\n");
		return 0;
	}
	int d = 4, *pd = &d;
	if(!enqueue(&q,(void*)pd))
	{
		printf("enqueue failed.\n");
		return 0;
	}
	int e = 5, *pe = &e;
	if(!enqueue(&q,(void*)pe))
	{
		printf("enqueue failed.\n");
		return 0;
	}

	printf("Queue is %d long.\n\n",q.length);
	printf("the queue: \n");
	Node_q* temp = q.front->next;

	for(int i = 0; i < q.length;i++)
	{
		printf("%d\n",*(int*)temp->value);
		temp = temp->next;
	}
	printf("fornt is pointing to %d",*(int*)q.front->next->value);
	printf("back is pointing to %d",*(int*)q.back->next->value);

	q_free(&q);
	return 0;
}

#include <stdio.h>
#include "queue.h"



int main(void)
{
	struct Queue q = {NULL,NULL,0};
	if(!q_init(&q)) {
		printf("queue init failed.\n");
		return 0;
	}	

	int a = 1;
	if(!enqueue(&q,(void*)&a)){
		printf("enqueue failed.\n");
		return 0;
	}


	int b = 2;
	if(!enqueue(&q,(void*)&b)){
		printf("enqueue failed.\n");
		return 0;
	}

	int c = 3;
	if(!enqueue(&q,(void*)&c)){
		printf("enqueue failed.\n");
		return 0;
	}

	int d = 4;
	if(!enqueue(&q,(void*)&d)){
		printf("enqueue failed.\n");
		return 0;
	}

	int e = 5;
	if(!enqueue(&q,(void*)&e)){
		printf("enqueue failed.\n");
		return 0;
	}

	printf("Queue is %d long.\n\n",q.length);
	printf("the queue: \n");
	struct Node_q* temp = q.front->next;

	for(int i = 0; i < q.length;i++) {
		printf("%d\n",*(int*)temp->value);
		temp = temp->next;
	}

	printf("front is pointing to %d.\n",*(int*)q.front->next->value);
	printf("back is pointing to %d.\n",*(int*)q.back->next->value);

	q_free(&q);
	return 0;
}

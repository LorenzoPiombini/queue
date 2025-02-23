#ifndef _QUEUE_H_
#define _QUEUE_H_

#define MAX_SIZE 300


struct Node_q
{
	void* value;
	struct Node_q* next;
};


struct Queue {
	struct Node_q* front;
	struct Node_q* back;
	int length;
};

unsigned char q_init(struct Queue *q);
unsigned char is_full(struct Queue *q);
unsigned char is_empty(struct Queue *q);
unsigned char enqueue(struct Queue *q, void* value);
unsigned char dequeue(struct Queue *q);
void q_free(struct Queue *q);
#endif
